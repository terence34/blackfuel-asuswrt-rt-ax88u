#
# Router dhd_monitor Makefile
#
# Copyright (C) 2015, Broadcom Corporation. All Rights Reserved.
# 
# Permission to use, copy, modify, and/or distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
# 
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
# SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
# OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
# CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#
#

include $(TOP)/.config

CFLAGS += -I. -I$(TOP)/shared -I$(SRCBASE)/include -I$(SRCBASE)/../components/shared -I$(SRCBASE)/../components/wlioctl/include -I$(SRCBASE)/../components/proto/include -I$(SRCBASE)/common/include -I$(LINUXDIR)/include -I$(TOP)/$(BUSYBOX_DIR)

LDFLAGS += -L$(TOP_PLATFORM)/nvram${BCMEX}${EX7} -L$(PLATFORMDIR)/install/nvram/usr/lib -lnvram ${EXTRA_NV_LDFLAGS}
LDFLAGS += -L$(TOP)/shared -L$(PLATFORMDIR)/install/shared/usr/lib -lshared
LDFLAGS += -lgcc_s

ifeq ($(RTCONFIG_QTN),y)
CFLAGS += -I$(TOP)/libqcsapi_client -I$(TOP)/httpd -I./sysdeps/qtn
LDFLAGS += -L$(TOP)/libqcsapi_client -lqcsapi_client
endif

OBJS := dhd_monitor.o

ifeq ($(wildcard $(SRCBASE)/router/dhd_monitor/*.c),)
all:
	-cp -f prebuilt/dhd_monitor dhd_monitor
else
all: dhd_monitor
endif

clean:
	rm -f *.o dhd_monitor .*.depend

install: all
	install -d $(INSTALLDIR)/usr/sbin
	install dhd_monitor $(INSTALLDIR)/usr/sbin
	$(STRIP) $(INSTALLDIR)/usr/sbin/dhd_monitor

ifeq ($(wildcard $(SRCBASE)/router/dhd_monitor/*.c),)
dhd_monitor:
	-cp -f prebuilt/dhd_monitor dhd_monitor
else
dhd_monitor: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)
endif

%.o: .%.depend
.%.depend: %.c
	$(CC) $(CFLAGS) -M $< > $@

-include $(OBJS:%.o=.%.depend)
