# A simple Makefile example to learn modern C++.

hello.exe: common.cpp hello.cpp
world.exe: common.cpp world.cpp

#########################################################################

CPPFLAGS += -D_FILE_OFFSET_BITS=64 -D_REENTRANT
CXXFLAGS += -std=c++23 -MMD -MP -Wall -Wextra -Wpedantic \
	-Wshadow -Wnull-dereference -Warray-bounds \
	-Wconversion -Wsign-conversion \
	-Wformat=2 -Wformat-security -Wformat-overflow -Wformat-truncation \
	-Wuninitialized -Wold-style-cast -Wnon-virtual-dtor \
	-fPIE -fstack-protector-strong

ifeq ($(DEBUG),false)
	CPPFLAGS += -DNDEBUG
	CXXFLAGS += -O2 -flto=auto -march=native
else
	CPPFLAGS += -DDEBUG
	CXXFLAGS += -O0 -g3 -gdwarf-5 -fno-inline
	CXXFLAGS += -fsanitize=address,undefined,bool,enum,null,bounds,alignment,float-divide-by-zero,float-cast-overflow,pointer-compare,pointer-subtract
endif

%.exe: %.cpp
	$(CXX) $(CPPFLAGS) $($(@:.exe=)_CPPFLAGS) $(CXXFLAGS) $($(@:.exe=)_CXXFLAGS) $(filter %.cpp, $^) $(LDFLAGS) $($(@:.exe=)_LDFLAGS) $(LDLIBS) $($(@:.exe=)_LDLIBS) -o $@

ALL_TARGETS	:= $(shell grep -Eo '^[^%\#]+\.exe\s*:' $(lastword $(MAKEFILE_LIST)))
ALL_TARGETS	:= $(ALL_TARGETS::=)
ALL_DEP	:= $(addsuffix .d, $(ALL_TARGETS)) $(addsuffix .d, $(ALL_TARGETS:.exe=))
ALL_DSYM	:= $(addsuffix .dSYM, $(ALL_TARGETS))

-include $(ALL_DEP)

all: $(ALL_TARGETS)

clean:
	$(RM) -r $(ALL_TARGETS) $(ALL_DEP) $(ALL_DSYM) $(EXTRA_CLEAN)

help:
	@echo "Usage: $(MAKE) TARGETS... [DEBUG=false]"
	@echo "Possible targets: all $(ALL_TARGETS) clean help"
	@echo "Use <target_no_exe_suffix>_[CPPFLAGS|CXXFLAGS|LDFLAGS|LDLIBS] to configure each target."

.DEFAULT_GOAL	:= help

.PHONY: all clean help

