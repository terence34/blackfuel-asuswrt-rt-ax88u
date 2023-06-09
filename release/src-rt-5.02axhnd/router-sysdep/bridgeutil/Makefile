#
# In most cases, you only need to modify this first section.
#
LIB = libbridgeutil.so

OBJS = bridgeutil.o

all dynamic install: generic_private_lib_install

clean: generic_clean
	rm -f $(INSTALL_DIR)/lib/private/$(LIB)



#
# Set our CommEngine directory (by splitting the pwd into two words
# at /userspace and taking the first word only).
# Then include the common defines under CommEngine.
# You do not need to modify this part.
#
CURR_DIR := $(shell pwd)
BUILD_DIR:=$(HND_SRC)

include $(BUILD_DIR)/make.common

#
# Private apps and libs are allowed to include header files from the
# private and public directories
#
# WARNING: Do not modify this section unless you understand the
# license implications of what you are doing.
#
ALLOWED_INCLUDE_PATHS := -I.\
						 -I$(BUILD_DIR)/userspace/public/include  \
						 -I$(BUILD_DIR)/userspace/public/include/$(OALDIR) \
						 -I$(BUILD_DIR)/userspace/private/include  \
						 -I$(BUILD_DIR)/userspace/private/include/$(OALDIR) \
						 -I$(INC_BRCMDRIVER_PRIV_PATH)/$(BRCM_BOARD) \
						 -I$(KERNEL_LINKS_DIR)

ifeq ($(PROFILE_KERNEL_VER), LINUX_3_14_0)
ALLOWED_INCLUDE_PATHS +=-include bcm_local_kernel_include/linux/in6.h 
endif


#
# Implicit rule will make the .c into a .o
# Implicit rule is $(CC) -c $(CPPFLAGS) $(CFLAGS)
# See Section 10.2 of Gnu Make manual
#
ifneq ($(PREBUILT_BCMBIN),1)
$(LIB): $(OBJS)
	$(CC) -shared $(BCM_LD_FLAGS) -Wl,--whole-archive,-soname,$(notdir $@) -o $@ $(OBJS) -Wl,--no-whole-archive
else
$(LIB): 
	cp -f $(TOP_PLATFORM)/$(shell pwd | sed 's/\(.*router-sysdep\/\)//')/$(PRBM_DIR)/$@ ./
endif



#
# Include the rule for making dependency files.
# The '-' in front of the second include suppresses
# error messages when make cannot find the .d files.
# It will just regenerate them.
# See Section 4.14 of Gnu Make.
# no objects at this level, so don't need dependencies

#include $(BUILD_DIR)/make.deprules

#-include $(OBJS:.o=.d)
