help:
	@echo "Usage: $(MAKE) TARGETS... [DEBUG=false]"
	@echo "Possible targets: all $(ALL) clean help"

#########################################################################

ALL	= hello world

hello: common.cpp hello.cpp
world: common.cpp world.cpp

#########################################################################

CPPFLAGS += -D_FILE_OFFSET_BITS=64 -D_REENTRANT
CXXFLAGS += -std=c++23 -MMD -MP -Wall -Wextra -Wpedantic \
	-Wshadow -Wnull-dereference -Warray-bounds \
	-Wconversion -Wsign-conversion \
	-Wformat=2 -Wformat-security -Wformat-overflow -Wformat-truncation \
	-Wuninitialized -Wold-style-cast -Wnon-virtual-dtor

ifeq ($(DEBUG),false)
	CPPFLAGS += -DNDEBUG
	CXXFLAGS += -O2 -flto=auto -fPIE -fstack-protector-strong -march=native
else
	CPPFLAGS += -DDEBUG
	CXXFLAGS += -O0 -g3 -gdwarf-5 -fno-inline
	CXXFLAGS += -fsanitize=address,undefined,integer,bool,enum,null,bounds,alignment,float-divide-by-zero,float-cast-overflow,pointer-compare,pointer-subtract
endif

%: %.cpp
	$(CXX) $(CPPFLAGS) $($@_CPPFLAGS) $(CXXFLAGS) $($@_CXXFLAGS) $(filter %.cpp, $^) $(LDFLAGS) $($@_LDFLAGS) $(LDLIBS) $($@_LDLIBS) -o $@

-include $(addsuffix .d, $(ALL))

all: $(ALL)

clean:
	$(RM) -r $(ALL) $(addsuffix .exe, $(ALL)) $(addsuffix .d, $(ALL)) $(addsuffix .dSYM, $(ALL)) $(EXTRA_CLEAN)

.PHONY: all clean help

