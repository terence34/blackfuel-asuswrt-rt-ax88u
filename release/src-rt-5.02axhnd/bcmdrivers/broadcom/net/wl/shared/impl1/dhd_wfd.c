/*
    Copyright (c) 2017 Broadcom
    All Rights Reserved

    <:label-BRCM:2017:DUAL/GPL:standard

    Unless you and Broadcom execute a separate written software license
    agreement governing use of this software, this software is licensed
    to you under the terms of the GNU General Public License version 2
    (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
    with the following added to such license:

       As a special exception, the copyright holders of this software give
       you permission to link this software with independent modules, and
       to copy and distribute the resulting executable under terms of your
       choice, provided that you also meet, for each linked independent
       module, the terms and conditions of the license of that module.
       An independent module is a module which is not derived from this
       software.  The special exception does not apply to any modifications
       of the software.

    Not withstanding the above, under no circumstances may you combine
    this software in any way with any other Broadcom software provided
    under a license other than the GPL, without Broadcom's express prior
    written consent.

    :>
*/

#include <linux/skbuff.h>
#include <linux/netdevice.h>
#if defined(BCM_NBUFF)
#include <linux/nbuff.h>
#endif
#include <bcmutils.h>
#include <dngl_stats.h>
#include <dhd_dbg.h>
#include <dhd.h>
#include <dhd_linux.h>
#include <dhd_flowring.h>
#include <dhd_bus.h>
#include <dhd_wfd.h>
#include <dhd_wmf_linux.h>

#if defined(BCM_BLOG)
#include <linux/blog.h>
#include <dhd_blog.h>
#endif

#if defined(BCM_DHD_RUNNER)
/* compare two ethernet addresses - assumes the pointers can be referenced as shorts */
#define dhd_eacmp(a, b) ((((const uint16 *)(a))[0] ^ ((const uint16 *)(b))[0]) | \
                         (((const uint16 *)(a))[1] ^ ((const uint16 *)(b))[1]) | \
                         (((const uint16 *)(a))[2] ^ ((const uint16 *)(b))[2]))

static ulong tx_flowring_mismatch_drop_wfd[FWDER_MAX_RADIO] = {0};
#endif /* BCM_DHD_RUNNER */
extern const uint8 prio2ac[8];
#if defined(BCM_BLOG)
#if defined(BCM_WFD) && !( defined(CONFIG_BCM_FAP) || defined(CONFIG_BCM_FAP_MODULE)) && !(defined(CONFIG_BCM_PKTRUNNER) || defined(CONFIG_BCM_PKTRUNNER_MODULE))
typedef int (*FC_WFD_ENQUEUE_HOOK)(void * nbuff_p,const Blog_t * const blog_p); /* Xmit with blog */
extern FC_WFD_ENQUEUE_HOOK fc_wfd_enqueue_cb;

static int dhd_fc_wfd_enqueue(void * nbuff_p,const Blog_t * const blog_p)
{
    if(fc_wfd_enqueue_cb)
        return (fc_wfd_enqueue_cb)(nbuff_p,blog_p);
         
    return 0;
}
#endif
#endif

int
dhd_handle_wfd_blog(dhd_pub_t *dhdp, struct net_device *net, int ifidx,
                    void *pktbuf, int b_wmf_unicast)
{
    uint prio = 0, flowid = 0;
    int ret = 0;
    struct sk_buff *skb = NULL;
    bool b_skb_fc_unhandled = FALSE;

#if defined(BCM_NBUFF)
    if (IS_FKBUFF_PTR(pktbuf))
        flowid = PKTFLOWID(pktbuf);
    else
        skb = PNBUFF_2_SKBUFF(pktbuf);
#endif /* BCM_NBUFF */

    prio = PKTPRIO(pktbuf);

    b_skb_fc_unhandled = skb && !DHD_PKT_GET_SKB_FLOW_HANDLED(skb);

    /* when wlan_mark is not marked, do WFD and blog for skb
     * or for FKB, do it when it is wmf unicast from flowcache.
     */
    if (b_skb_fc_unhandled || b_wmf_unicast) {
        ret = dhd_flowid_update(dhdp, ifidx, dhdp->flow_prio_map[prio], pktbuf);
        if (ret != BCME_OK) {
            PKTFREE(dhdp->osh, pktbuf, FALSE);
            return ret;
        }
        flowid = PKTFLOWID(pktbuf); /* get flowid after updated */
        /* save as the format of prio + flowid */
        PKTSETPRIO(pktbuf, prio);
    }

#if defined(BCM_BLOG)
    if (!b_wmf_unicast && b_skb_fc_unhandled) {
        struct blog_t *blog_p = skb->blog_p;
        if (blog_p != NULL)
        {
#if defined(BCM_DHD_RUNNER)
            flow_ring_node_t *flow_ring_node;
            flow_ring_node = &(((flow_ring_node_t *)(dhdp->flow_ring_table))[flowid]);

            if (DHD_FLOWRING_RNR_OFFL(flow_ring_node))
            {
                blog_p->rnr.is_tx_hw_acc_en = 1;
                blog_p->rnr.is_wfd = 0;
                blog_p->rnr.flowring_idx = PKTFLOWID(pktbuf);
                blog_p->rnr.ssid = ifidx;
                blog_p->rnr.priority = prio;
                blog_p->rnr.radio_idx = dhdp->unit;
                blog_p->rnr.flow_prio = ((prio2ac[prio] == AC_VI) || (prio2ac[prio] == AC_VO)) ? flow_prio_exclusive : flow_prio_normal;
                blog_p->rnr.llcsnap_flag = DHDHDR_SUPPORT(dhdp) ? 1 : 0;
            }
            else
#endif /* BCM_DHD_RUNNER */
            {
                blog_p->wfd.dhd_ucast.is_tx_hw_acc_en = 1;
                blog_p->wfd.dhd_ucast.is_wfd = 1;
                blog_p->wfd.dhd_ucast.is_chain = 0;
                blog_p->wfd.dhd_ucast.wfd_idx = dhdp->wfd_idx;
                blog_p->wfd.dhd_ucast.flowring_idx = flowid;
                blog_p->wfd.dhd_ucast.priority = prio;
                blog_p->wfd.dhd_ucast.ssid = ifidx;
                blog_p->wfd.dhd_ucast.wfd_prio = blog_p->iq_prio;
#if defined(BCM_WFD) && !( defined(CONFIG_BCM_FAP) || defined(CONFIG_BCM_FAP_MODULE)) && !(defined(CONFIG_BCM_PKTRUNNER) || defined(CONFIG_BCM_PKTRUNNER_MODULE))
                blog_p->dev_xmit_blog = dhd_fc_wfd_enqueue;
#else
                blog_p->dev_xmit_blog = NULL;
#endif
            }

            DHD_PERIM_UNLOCK(dhdp);
            blog_emit(pktbuf, dhd_idx2net(dhdp, ifidx), TYPE_ETH, 0, BLOG_WLANPHY);

#if defined(BCM_DHD_RUNNER)
            /* when RUNNER accelerate flow, stats will not be availabe until
             * put_stats is called blog has to fill vir_dev in order to get
             * put_stats called, so call this blog_link() to fill vir_dev
             */
            blog_lock();
            blog_link(IF_DEVICE, blog_p, (void*)net, DIR_TX, skb->len);
            blog_unlock();
#endif /* BCM_DHD_RUNNER */
            DHD_PERIM_LOCK(dhdp);
        }
    }

    if (skb && DHD_PKT_GET_SKB_FLOW_HANDLED(skb))
        DHD_PKT_CLR_SKB_FLOW_HANDLED(skb);
#endif /* BCM_BLOG */

    return ret;
}


static int BCMFASTPATH
dhd_wfd_forward(unsigned int pkt_cnt, void **pkts, unsigned long wl_radio_idx, unsigned long dummy)
{
    int cnt;
    int ifidx;
    uint16 flowid;
    dhd_pub_t *dhdp;
    FkBuff_t *fkb_p;
    pNBuff_t pNBuf;
    int ret;
    flow_ring_node_t *flow_ring_node;

    DHD_PERIM_LOCK_ALL(wl_radio_idx % FWDER_MAX_UNIT);
    dhdp = g_dhd_info[wl_radio_idx];

    for (cnt = 0; cnt < pkt_cnt; cnt++) { /* Process the array of packets */

        fkb_p = (FkBuff_t *)pkts[cnt];
        pNBuf = FKBUFF_2_PNBUFF((FkBuff_t *)fkb_p);
        ifidx = fkb_p->wl.ucast.dhd.ssid;

#if (defined(DSLCPE) && defined(BCM_NBUFF)) || defined(BCM_NBUFF_WLMCAST)
        if ((fkb_p->len > (WLAN_MAX_MTU_PAYLOAD_SIZE+BCM_MAX_MTU_EXTRA_SIZE)) || PKTATTACHTAG(dhdp->osh, pNBuf))
        {
            PKTFREE(dhdp->osh, pNBuf, FALSE);
            dhdp->tx_dropped++;
            dhdp->tx_packets_dropped_wfd++;
            dhd_if_inc_txpkt_drop_cnt(dhdp, ifidx);
            continue;
        }
#endif /* DSLCPE && BCM_NBUFF || BCM_NBUFF_WLMCAST */

        flowid = fkb_p->wl.ucast.dhd.flowring_idx;

        /* tag this packet as coming from wfd */
        DHD_PKT_SET_WFD_BUF(pNBuf);

        /* Save the flowid and the dataoff in the skb's pkttag */
        DHD_PKT_SET_FLOWID(pNBuf, flowid);

        flow_ring_node = DHD_FLOW_RING(dhdp, flowid);
        if ((flow_ring_node->status != FLOW_RING_STATUS_PENDING) &&
                (flow_ring_node->status != FLOW_RING_STATUS_OPEN)) {
            DHD_INFO(("%s: on flowid %d when flow ring status is %d\r\n",
                      __FUNCTION__,flowid, flow_ring_node->status));
            ret = BCME_NOTREADY;
        } else {
#if defined(BCM_DHD_RUNNER)
             struct ether_header *eh;
            
            /* At present we do not have any mechanism to flush runner/wfd
             * rings when a STA disassociates. So runner can still feed some
             * packets with an old flowid when that STA has left and flowid
             * is allocated to some other STA. Drop the packets here to avoid
             * scb mismatch in wl
             */
            eh = (struct ether_header *)PKTDATA(dhdp->osh, pNBuf);
            if ((DHD_IF_ROLE_AP(dhdp, ifidx) &&
                     dhd_eacmp(eh->ether_dhost, flow_ring_node->flow_info.da)) ||
                     (dhdp->flow_prio_map[(PKTPRIO(pNBuf))] != flow_ring_node->flow_info.tid)) {
                DHD_INFO(("dhd%d: dhd_wfd_forward: Wrong flow dst mac "MACF""
                        "ring mac "MACF" status %d active %d\n",
                        dhdp->unit, ETHERP_TO_MACF(eh->ether_dhost),
                        ETHERP_TO_MACF(flow_ring_node->flow_info.da),
                        flow_ring_node->status, flow_ring_node->active));
            
                tx_flowring_mismatch_drop_wfd[dhdp->unit]++;
                ret = BCME_ERROR;
            } else 
#endif /* BCM_DHD_RUNNER */
                ret = dhd_bus_txqueue_enqueue(dhdp->bus, pNBuf, flowid);
        }
        if (!ret) {
#ifdef WLCSM_DEBUG
            wlcsm_dbg_inc(11,1);
#endif
            dhdp->tx_packets++;
            dhdp->tx_packets_wfd++;
#ifndef BCM_DHD_RUNNER
            dhd_if_inc_txpkt_cnt(dhdp, ifidx, pNBuf);
#endif
        } else {
            PKTFREE(dhdp->osh, pNBuf, FALSE);
            dhdp->tx_dropped++;
            dhdp->tx_packets_dropped_wfd++;
            dhd_if_inc_txpkt_drop_cnt(dhdp, ifidx);
        }

    } /* for cnt */

    /* Flush all pending tx queued packets in bus(s) managed on this CPU core */
    dhd_wfd_invoke_func(wl_radio_idx, dhd_bus_txqueue_flush);

    DHD_PERIM_UNLOCK_ALL(wl_radio_idx % FWDER_MAX_UNIT);

    return 0;
}


static void BCMFASTPATH
dhd_send_all(unsigned int dummy)
{
    /* dummy function for now */
}

static void BCMFASTPATH
dhd_wfd_mcasthandler(uint32_t wl_radio_idx, unsigned long fkb, unsigned long dev)
{
    pNBuff_t *pNBuf = FKBUFF_2_PNBUFF((FkBuff_t *)fkb);
    struct net_device *dev_p = (struct net_device *)dev;
    int ret = 0,ifidx;
    dhd_pub_t *dhdp;
#ifdef DHD_WMF
    dhd_wmf_t *wmf;
#endif
#if defined(DSLCPE) && defined(BCM_COUNTER_EXTSTATS)
    int pktlen;
#endif

#ifdef WLCSM_DEBUG
    wlcsm_dbg_inc(10,1);
    WLCSM_TRACE(WLCSM_TRACE_DBG, "wfd mcast coming\n");
#endif
    DHD_PERIM_LOCK_ALL(wl_radio_idx % FWDER_MAX_UNIT);
    dhdp = g_dhd_info[wl_radio_idx];
    /*  we can assum ifidx will be right since it comes from fastpath. */
    ifidx = dhd_dev_get_ifidx(dev_p);
#ifdef DHD_WMF
    wmf = dhd_wmf_conf(dhdp, ifidx);
#endif
#if (defined(DSLCPE) && defined(BCM_NBUFF))|| defined(BCM_NBUFF_WLMCAST)
    if (((FkBuff_t *)fkb)->len > (WLAN_MAX_MTU_PAYLOAD_SIZE+BCM_MAX_MTU_EXTRA_SIZE)) {
        DHD_ERROR(("%s : oversize packets!!\n", __FUNCTION__));
        goto free_drop;
    }

    if (PKTATTACHTAG(dhdp->osh,  pNBuf)) {
        DHD_ERROR(("%s : pcie is still in suspend state!!\n", __FUNCTION__));
        goto free_drop;
    }
#endif /* DSLCPE && BCM_NBUFF || defined(BCM_NBUFF_WLMCAST */


    DHD_PKT_CLR_DATA_DHDHDR(pNBuf);

    /* if pkt's priority is not set, retrive it from TOS/DSCP and set it,
     * if it is still 0, then set it to VI by default, in runner offloading N+M case,
     * N will use pre-defined priority and for M the packet should be marked by
     * correct dscp matching to the pre-defined priority.
     */

#if (defined(DSLCPE) && defined(BCM_DHD_RUNNER)) || defined(BCM_NBUFF_WLMCAST)
    /*  when DHD_RUNNER offloading is enabled, the N and M station priority has to be the same
     *  otherwize, there is a chance N station will recevied duplicated pkt.
     */
    if (g_multicast_priority > 0) {
        PKTSETPRIO(pNBuf, g_multicast_priority);
    } else
#endif /* DSLCPE && BCM_DHD_RUNNER || defined(BCM_NBUFF_WLMCAST */
        if (!PKTPRIO(pNBuf)) {
            pktsetprio(pNBuf, FALSE);
            if (!PKTPRIO(pNBuf))
                PKTSETPRIO(pNBuf, PRIO_8021D_VI);
        }
#ifdef DHD_WMF
    if (wmf->wmf_enable) {
        /* set  WAN multicast indication before sending to EMF module */
        DHD_PKT_SET_WFD_BUF(pNBuf);
        DHD_PKT_SET_WAN_MCAST(pNBuf);
        DHD_INFO(("%s: pakcet:%p from WMF MCAST and is WANMCAST:%d\n",
                  __FUNCTION__, pNBuf, DHD_PKT_GET_WAN_MCAST(pNBuf)));
        ret = dhd_wmf_packets_handle(dhdp, pNBuf, NULL, ifidx, 0);
        if (ret == WMF_TAKEN)
            goto succ_count;
        else if (ret == WMF_DROP)
            goto free_drop;
    }
#endif /* DHD_WMF */
    DHD_PKT_CLR_WFD_BUF(pNBuf);
    ret = dhd_flowid_update(dhdp, ifidx, dhdp->flow_prio_map[(PKTPRIO(pNBuf))], pNBuf);
    if (ret == BCME_OK) {
#if defined(DSLCPE) &&  defined(BCM_COUNTER_EXTSTATS)
        pktlen=PKTLEN(dhdp->osh,pNBuf);
#endif
        ret=dhd_sendpkt(dhdp,ifidx,pNBuf);
        if(ret)
            goto mcast_drop;
        else {
#if defined(DSLCPE) &&  defined(BCM_COUNTER_EXTSTATS)
            dhd_if_inc_txpkt_mcnt(dhdp,ifidx,pktlen);
#endif
            goto mcast_count;
        }
    } else {
        DHD_ERROR(("%s: flowid_update error.\n", __FUNCTION__));
    }
free_drop:
    PKTFREE(dhdp->osh, pNBuf, FALSE);
mcast_drop:
    dhd_if_inc_txpkt_drop_cnt(dhdp, ifidx);
    dhdp->tx_dropped++;
    dhdp->tx_packets_dropped_wfd_mcast++;
    goto unlock;
succ_count:
    dhdp->tx_multicast++;
mcast_count:
    dhdp->tx_packets_wfd_mcast++;
unlock:
    DHD_PERIM_UNLOCK_ALL((dhdp->fwder_unit % FWDER_MAX_UNIT));
    return;
}


int dhd_wfd_bind(struct net_device *net, unsigned int unit)
{
    int wfd_idx = -1;

    wfd_idx = wfd_bind(net, WFD_WL_FWD_HOOKTYPE_FKB, true, (HOOK4PARM)dhd_wfd_forward,
                       (HOOK32)dhd_send_all, (HOOK3PARM)dhd_wfd_mcasthandler, unit);
    if (wfd_idx < 0)
        DHD_ERROR(("%s: Error in binding WFD.\n", __FUNCTION__));

    return wfd_idx;
}

void dhd_wfd_unbind(int wfd_idx)
{
    wfd_unbind(wfd_idx, WFD_WL_FWD_HOOKTYPE_FKB);
}

int dhd_wfd_registerdevice(int wfd_idx, struct net_device *dev)
{
    int ret = 0;
    int ifidx = WLAN_NETDEVPATH_SSID(netdev_path_get_hw_port(dev));

    ret = wfd_registerdevice(wfd_idx, ifidx, dev);
    if (ret != 0) {
        DHD_ERROR(("%s failed wfd_idx %d, ifidx %d\n",
                   __FUNCTION__, wfd_idx, ifidx));
    }
    return ret;
}

int dhd_wfd_unregisterdevice(int wfd_idx, struct net_device *dev)
{
    int ret = 0;
    int ifidx = WLAN_NETDEVPATH_SSID(netdev_path_get_hw_port(dev));

    ret = wfd_unregisterdevice(wfd_idx, ifidx);
    if (ret != 0) {
        DHD_ERROR(("%s failed wfd_idx %d ifidx %d\n",
                   __FUNCTION__, wfd_idx, ifidx));
    }

    return ret;
}

/* Add wfd dump output to a buffer */
void
dhd_wfd_dump(dhd_pub_t *dhdp, struct bcmstrbuf *strbuf)
{
#if defined(BCM_DHD_RUNNER)
    bcm_bprintf(strbuf, "\ntx_packets_wfd  %lu tx_packets_dropped_wfd %lu tx_flowring_mismatch_drop_wfd %lu\n",
                dhdp->tx_packets_wfd, dhdp->tx_packets_dropped_wfd, tx_flowring_mismatch_drop_wfd[dhdp->unit]);
#else
    bcm_bprintf(strbuf, "\ntx_packets_wfd  %lu tx_packets_dropped_wfd %lu\n",
                dhdp->tx_packets_wfd, dhdp->tx_packets_dropped_wfd);
#endif
    bcm_bprintf(strbuf, "tx_packets_wfd_mcast  %lu tx_packets_dropped_wfd_mcast %lu\n",
                dhdp->tx_packets_wfd_mcast, dhdp->tx_packets_dropped_wfd_mcast);

    return;
}

/* Clear wfd stats */
void
dhd_wfd_clear_dump(dhd_pub_t *dhdp)
{
    dhdp->tx_packets_wfd = 0;
    dhdp->tx_packets_dropped_wfd = 0;
    dhdp->tx_packets_wfd_mcast = 0;
    dhdp->tx_packets_dropped_wfd_mcast = 0;
#if defined(BCM_DHD_RUNNER)
    tx_flowring_mismatch_drop_wfd[dhdp->unit] = 0;
#endif
    return;
}
