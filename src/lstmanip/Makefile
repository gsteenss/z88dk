
OBJS = lstmanip.o

INSTALL ?= install

ifeq ($(EXEPREFIX),.exe)
OBJS += ../getopt/getopt.o
CFLAGS += -I../getopt
endif

all: z88dk-lstmanip$(EXESUFFIX)

z88dk-lstmanip$(EXESUFFIX):	$(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)

install: 
	$(INSTALL) z88dk-lstmanip$(EXESUFFIX) $(PREFIX)/bin/z88dk-lstmanip$(EXESUFFIX)

clean:
	$(RM) z88dk-lstmanip$(EXESUFFIX) lstmanip.o core
	$(RM) -rf Debug Release


#Dependencies

lstmanip.o: lstmanip.c
