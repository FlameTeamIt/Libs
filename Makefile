# control Makefile
MAKEFILE_PATH := $(shell dirname $(abspath $(lastword $(MAKEFILE_LIST))))

include $(MAKEFILE_PATH)/Makefile.config

MAKE_LIBS := $(MAKEFILE_PATH)/src/Makefile
MAKE_TESTS := $(MAKEFILE_PATH)/tests/Makefile

all   : .mkdirs .libs .tests

tests : .mkdirs .libs .tests

libs  : .mkdirs .libs

release : 

debug :

clean :
	@echo $@
	rm -rf $(ALL_PATHS)

.PHONY : all clean libs tests release debug

# --------------------------------------------------

.mkdirs : $(ALL_PATHS)
$(ALL_PATHS) :
	mkdir -p $@

# --------------------------------------------------

.libs : .lib_static .lib_shared
	@echo $@ : $^

.lib_static : .mkdirs
	@echo $@ : $^
	$(MAKE) static \
	    CONFIG_FILE=$(MAKEFILE_PATH)/Makefile.config \
	    SOURCE_PATH=$(MAKEFILE_PATH)/src \
	    INCLUDE_PATH=$(MAKEFILE_PATH)/src \
	    -w $(MFLAGS) \
	    -f $(MAKE_LIBS)
	
.lib_shared : .mkdirs
	@echo $@ : $^
	$(MAKE) shared \
	    CONFIG_FILE=$(MAKEFILE_PATH)/Makefile.config \
	    SOURCE_PATH=$(MAKEFILE_PATH)/src \
	    INCLUDE_PATH=$(MAKEFILE_PATH)/src \
	    -w $(MFLAGS) \
	    -f $(MAKE_LIBS)
	
# --------------------------------------------------

.tests: .mkdirs
	@echo $@ : $^
	$(MAKE) \
	    CONFIG_FILE=$(MAKEFILE_PATH)/Makefile.config \
	    INCLUDE_PATH=$(MAKEFILE_PATH)/src \
	    SOURCE_PATH=$(MAKEFILE_PATH)/tests \
	    -w $(MFLAGS) \
	    -f $(MAKE_TESTS)
