# control Makefile
include Makefile.config

MAKE_LIBS := ./src/Makefile
MAKE_TESTS := ./tests/Makefile

all   : .mkdirs .libs .tests

tests : .mkdirs .libs .tests

libs  : .mkdirs .libs

clean :
	@echo $@
	rm -rf $(ALL_PATHS)

.PHONY : clean

# --------------------------------------------------

.mkdirs :
	@echo MAKEFLAGS = $(MAKEFLAGS)
	@echo MFLAGS = $(MFLAGS)
	mkdir -p $(ALL_PATHS)

# --------------------------------------------------

.libs : .mkdirs
	@echo $@ : $^
	$(MAKE) \
	    CONFIG_FILE=$(LOCAL_PATH)/Makefile.config \
	    SOURCE_PATH=src \
	    -w $(MFLAGS) \
	    -f $(MAKE_LIBS)

# --------------------------------------------------

.tests: .mkdirs
	@echo $@ : $^
# 	$(MAKE) \
# 	    CONFIG_FILE=$(shell pwd)/Makefile.config \
# 	    -w $(MFLAGS) \
# 	    -f $(MAKE_TESTS)
