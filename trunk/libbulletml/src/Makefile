CC = psp-g++
AR = psp-ar
PSPDIR = $(shell psp-config --psp-prefix)
INCLUDES = -I.
LIBS = tinyxml/tinyxml.o tinyxml/tinyxmlparser.o tinyxml/tinyxmlerror.o
#CXXFLAGS = -g -W -Wall -ansi -pedantic
#CXXFLAGS = -pg -g -W -Wall -ansi -pedantic
CXXFLAGS = -O2 -G0 -W -Wall -ansi -pedantic
CFLAGS = -O2 -G0
OBJS = bulletmlparser-tinyxml.o bulletmlparser.o bulletmltree.o calc.o formula-variables.o bulletmlrunner.o bulletmlrunnerimpl.o

all: libbulletml.a

libbulletml.a: $(OBJS)
	$(MAKE) -C tinyxml
	$(AR) -r libbulletml.a *.o tinyxml/tiny*.o

clean:
	rm -f *.o *.a
	$(MAKE) -C tinyxml clean

calc.cpp: calc.yy
	bison -y   calc.yy && mv y.tab.c calc.cpp

$(OBJS): %.o: %.cpp
	$(CC) -c $(CXXFLAGS) $(INCLUDES) $<

doxy:
	doxygen

distdir:

install:
	mkdir -p $(PSPDIR)/include/bulletml $(PSPDIR)/lib
	cp bulletml*.h $(PSPDIR)/include/bulletml
	cp libbulletml.a $(PSPDIR)/lib
