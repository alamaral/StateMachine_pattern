
TARGETS = DVDPlayerTest

all: $(TARGETS)

SRCS = Player.cpp DVDPlayer.cpp

OBJS = $(SRCS:%.cpp=%.o)

main.o: main.cpp $(OBJS)

$(OBJS) : Makefile

STATE_MACHINE_LIBDIR = ../lib
STATE_MACHINE_LIB = $(STATE_MACHINE_LIBDIR)/StateMachine.a

PLAYER_STATE_MACHINE_LIBDIR = PlayerStateMachine
PLAYER_STATE_MACHINE_LIB = $(PLAYER_STATE_MACHINE_LIBDIR)/PlayerStateMachine.a

INCPATH = -I. -I$(STATE_MACHINE_LIBDIR) -I$(PLAYER_STATE_MACHINE_LIBDIR)

LIBS = $(PLAYER_STATE_MACHINE_LIB) $(STATE_MACHINE_LIB)

#LIBS += -lefence

CXX = g++

LD = $(CXX)

OPT = -O2

#PROF_FLAGS = -pg

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

LDFLAGS	= $(PROF_FLAGS)

.PHONY: clean distclean cscope ctags valgrind _catalog

DVDPlayerTest: $(IMPORTS) DVDPlayerTest.o $(OBJS) $(DEPENDS) $(LIBS)
	$(LD) $(LDFLAGS) -o $@ DVDPlayerTest.o $(OBJS) $(LIBS)

%.o: %.cpp $(LIBS) | .deps
	$(CXX) -c $(CXXFLAGS) -MD -MF .deps/$*.d -o $@ $<

$(PLAYER_STATE_MACHINE_LIB):
	cd $(PLAYER_STATE_MACHINE_LIBDIR) && make

$(STATE_MACHINE_LIB):
	cd $(STATE_MACHINE_LIBDIR) && make

clean:
	rm -f $(TARGETS) DVDPlayerTest.o
	rm -f $(OBJS) *~
	rm -rf .deps
	rm -f *.ii *.s
	rm -f gmon.out
	cd $(STATE_MACHINE_LIBDIR) && make clean
	cd $(PLAYER_STATE_MACHINE_LIBDIR) && make clean

.deps :
	mkdir -p $@

-include .deps/*.d
