include ../common.mak

include $(SRCBASE)/.config

all:

install: all
	install -d $(INSTALLDIR)/usr/sbin
ifneq ($(HND_ROUTER),y)
	install lld2d $(INSTALLDIR)/usr/sbin
else
	install lld2d.hnd $(INSTALLDIR)/usr/sbin/lld2d
endif
ifeq ($(BUILD_NAME),RT-AC3200)
	install icon.rtac3200.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac3200.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC56U)
	install icon.rtac56u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac56u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC87U)
	install icon.rtac87u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac87u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC68U))
	mkdir -p $(INSTALLDIR)/usr/sbin/lltd
	install icon.rtac68u.ico $(INSTALLDIR)/usr/sbin/lltd/icon.ico
	install icon.large.rtac68u.ico $(INSTALLDIR)/usr/sbin/lltd/icon.large.ico
	install icon.rtac66u_v2.ico $(INSTALLDIR)/usr/sbin/lltd/icon_alt.ico
	install icon.large.rtac66u_v2.ico $(INSTALLDIR)/usr/sbin/lltd/icon_alt.large.ico
	install icon.rpac1900.ico $(INSTALLDIR)/usr/sbin/lltd/icon_alt2.ico
	install icon.large.rpac1900.ico $(INSTALLDIR)/usr/sbin/lltd/icon_alt2.large.ico
else ifeq ($(BUILD_NAME),$(filter $(BUILD_NAME),RT-AC68A 4G-AC68U))
	install icon.rtac68u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac68u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC88U)
	install icon.rtac88u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac88u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC86U)
	install icon.rtac86u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac86u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),AC2900)
	install icon.ac2900.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.ac2900.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC3100)
	install icon.rtac3100.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac3100.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC5300)
	install icon.rtac5300.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac5300.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),GT-AC5300)
	install icon.rtac5300.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac5300.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME), RT-AX88U)
	install icon.rtax88u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtax88u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME), GT-AX11000)
	install icon.gtax11000.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.gtax11000.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME), RT-AX92U)
	install icon.rtax92u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtax92u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC1200G)
	install icon.rtac1200g.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac1200g.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),RT-AC1200G+)
	install icon.rtac1200g+.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac1200g+.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else ifeq ($(BUILD_NAME),DSL-AC68U)
	install icon.rtac68u.ico $(INSTALLDIR)/usr/sbin/icon.ico
	install icon.large.rtac68u.ico $(INSTALLDIR)/usr/sbin/icon.large.ico
else
	install icon.ico $(INSTALLDIR)/usr/sbin
	install icon.large.ico $(INSTALLDIR)/usr/sbin
endif
ifneq ($(RTCONFIG_BCMARM),y)
	install lld2d.conf $(INSTALLDIR)/usr/sbin
else
	cd $(INSTALLDIR)/usr/sbin && ln -sf /tmp/lld2d.conf lld2d.conf
ifeq ($(BUILD_NAME),RT-AC68U))
	cd $(INSTALLDIR)/usr/sbin && ln -sf /tmp/icon.ico icon.ico
	cd $(INSTALLDIR)/usr/sbin && ln -sf /tmp/icon.large.ico icon.large.ico
endif
endif

clean:
