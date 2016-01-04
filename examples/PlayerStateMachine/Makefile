
TARGET = PlayerStateMachine.a

all: $(TARGET)

SRCS = PSM.cpp PSMPaused.cpp PSMPlaying.cpp PSMState.cpp PSMStopped.cpp
SRCS += PSMFF.cpp PSMFR.cpp PSMScanF.cpp PSMScanR.cpp

OBJS = $(SRCS:%.cpp=%.o)

$(OBJS) : Makefile

STATE_MACHINE_LIBDIR = ../../lib
STATE_MACHINE_LIB = $(STATE_MACHINE_LIBDIR)/StateMachine.a

INCPATH = -I. -I.. -I$(STATE_MACHINE_LIBDIR)

CXX = g++

AR = ar

OPT = -O2

PROF_FLAGS = -pg

DEBUG = -g -DDEBUG

# 
# Optional flags

OPT	+= -fno-strict-aliasing

CXXFLAGS	+= -Werror -Wall
CXXFLAGS	+= -Wno-deprecated-declarations
CXXFLAGS	+= $(INCPATH)
CXXFLAGS	+= $(DEBUG)
CXXFLAGS	+= $(OPT)
CXXFLAGS	+= $(PROF_FLAGS)
CXXFLAGS	+= $(LOCAL_FLAGS)

# Enable to save intermediate files for debugging
#CXXFLAGS	+= -save-temps

.PHONY: clean distclean cscope ctags valgrind _catalog

$(TARGET): $(IMPORTS) $(OBJS) $(DEPENDS)
	$(AR) cr $(TARGET) $(OBJS)

%.o: %.cpp | .deps
	$(CXX) -c $(CXXFLAGS) -MD -MF .deps/$*.d -o $@ $<

clean:
	rm -f $(TARGET)
	rm -f $(OBJS) *~
	rm -rf .deps
	rm -f *.ii *.s

.deps :
	mkdir -p $@

-include .deps/*.d
