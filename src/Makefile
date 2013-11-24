# Makefile.in generated automatically by automake 1.4-p6 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999, 2001 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.

# This is part of Dan Hammer's SABRE Fighter Plane Simulator
# portions donated by Antti Barck
#
# 2000-01-22: Modified by Milan Zamazal <pdm@debian.org> for Debian
# compilation.
# 2000-02-12: Modified by Milan Zamazal <pdm@debian.org> for non-SVGAlib
# compilation.


SHELL = /bin/sh

srcdir = .
top_srcdir = ..

prefix = /tmp/gcw
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/sabre
pkglibdir = $(libdir)/sabre
pkgincludedir = $(includedir)/sabre

top_builddir = ..

ACLOCAL = @ACLOCAL@
AUTOCONF = autoconf
AUTOMAKE = automake
AUTOHEADER = @AUTOHEADER@

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}
transform = s,x,x,

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
host_alias = mipsel-linux
host_triplet = mipsel-unknown-linux-gnu
AUTOCONF = autoconf
AUTOMAKE = automake
CC = mipsel-linux-gcc
CXX = mipsel-linux-g++
HAVE_LIB = @HAVE_LIB@
LIB = @LIB@
LTLIB = @LTLIB@
PACKAGE = sabre
RANLIB = mipsel-linux-ranlib
REV_DATE = 11/21/99
VERSION = 0.2.4b

AUTOMAKE_OPTIONS = foreign
#bin_PROGRAMS = sabre
#SVGALIBSRCS = main.C vga_13.C input.C kbdhit.C
SVGALIBSRCS = 
# sabre_SOURCES = main.C game.C scnedit.C vga_13.C vmath.C traveler.C pen.C \
# 		transblt.C port_3d.C clip.C cpoly.C obj_3d.C group_3d.C \
# 		copoly.C txtrmap.C bits.C convpoly.C rendpoly.C rndrpoly.C \
# 		rndzpoly.C zview.C rotate.C terrain.C earth.C colormap.C \
# 		dvector.C flight.C weapons.C pilot.C fltlite.C \
# 		moveable.C unguided.C fltzview.C viewobj.C fltmngr.C \
# 		grndunit.C font8x8.C plltt.C input.C key_map.C linux_joy.C \
# 		kbdhit.C siminput.C simfile.C hud.C cockpit.C instrmnt.C \
# 		ppm.C mytimer.C colorspc.C globals.C portkey.C vtable2.C \
# 		led2.C aaaunit.C waypoint.C fltobj.C simfilex.C simmath.C \
# 		target.C sbrkeys.C aibase.C aiflite.C aigunner.C aipilot.C \
# 		aipilot2.C aipilot3.C aipilot4.C aipilot5.C aipilot6.C sairfld.C \
# 		sarray.C sattkr.C sfltmdl.C sfrmtn.C smath.C smnvrst.C \
# 		spilcaps.C splncaps.C srunway.C sslewer.C stact.C starget.C \
#                 sweapon.C sbfltmdl.C simsnd.C dhlist.c stime.c spid.c pilobj.C
sabre_SOURCES = $(SVGALIBSRCS) game.C scnedit.C vmath.C traveler.C pen.C 		transblt.C port_3d.C clip.C cpoly.C obj_3d.C group_3d.C 		copoly.C txtrmap.C bits.C convpoly.C rendpoly.C rndrpoly.C 		rndzpoly.C zview.C rotate.C terrain.C earth.C colormap.C 		dvector.C flight.C weapons.C pilot.C fltlite.C 		moveable.C unguided.C fltzview.C viewobj.C fltmngr.C 		grndunit.C font8x8.C plltt.C key_map.C linux_joy.C 		siminput.C simfile.C hud.C cockpit.C instrmnt.C 		ppm.C mytimer.C colorspc.C globals.C portkey.C vtable2.C 		led2.C aaaunit.C waypoint.C fltobj.C simfilex.C simmath.C 		target.C sbrkeys.C aibase.C aiflite.C aigunner.C aipilot.C 		aipilot2.C aipilot3.C aipilot4.C aipilot5.C aipilot6.C sairfld.C 		sarray.C sattkr.C sfltmdl.C sfrmtn.C smath.C smnvrst.C 		spilcaps.C splncaps.C srunway.C sslewer.C stact.C starget.C                 sweapon.C sbfltmdl.C simsnd.C dhlist.c stime.c spid.c pilobj.C

sabre_LDADD = ../libzip/libcomp.a ../libzip/libuncl.a ../gdev/libgdev.a
EXTRA_DIST = *.h *.c
INCLUDES = -I../gdev -I../libzip
CXXFLAGS = -g -O2 -DDEBIAN
mkinstalldirs = $(SHELL) $(top_srcdir)/mkinstalldirs
CONFIG_CLEAN_FILES = 
PROGRAMS =  $(bin_PROGRAMS)


DEFS = -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DVERSION=\"0.2.4b\" -DREV_DATE=\"11/21/99\" -DUSING_NEWPILOT=1 -DJSTICK_INSTALLED=1 -DHAVE_LIBNCURSES=1 -DHAVE_LIBM=1  -I. -I$(srcdir) 
CPPFLAGS = 
LDFLAGS = 
LIBS = -lm -lncurses 
#sabre_OBJECTS =  main.o vga_13.o input.o kbdhit.o game.o \
#scnedit.o vmath.o traveler.o pen.o transblt.o port_3d.o \
#clip.o cpoly.o obj_3d.o group_3d.o copoly.o txtrmap.o \
#bits.o convpoly.o rendpoly.o rndrpoly.o rndzpoly.o \
#zview.o rotate.o terrain.o earth.o colormap.o dvector.o \
#flight.o weapons.o pilot.o fltlite.o moveable.o \
#unguided.o fltzview.o viewobj.o fltmngr.o grndunit.o \
#font8x8.o plltt.o key_map.o linux_joy.o siminput.o \
#simfile.o hud.o cockpit.o instrmnt.o ppm.o mytimer.o \
#colorspc.o globals.o portkey.o vtable2.o led2.o aaaunit.o \
#waypoint.o fltobj.o simfilex.o simmath.o target.o \
#sbrkeys.o aibase.o aiflite.o aigunner.o aipilot.o \
#aipilot2.o aipilot3.o aipilot4.o aipilot5.o aipilot6.o \
#sairfld.o sarray.o sattkr.o sfltmdl.o sfrmtn.o smath.o \
#smnvrst.o spilcaps.o splncaps.o srunway.o sslewer.o \
#stact.o starget.o sweapon.o sbfltmdl.o simsnd.o dhlist.o \
#stime.o spid.o pilobj.o
sabre_OBJECTS =  game.o scnedit.o vmath.o traveler.o \
pen.o transblt.o port_3d.o clip.o cpoly.o obj_3d.o \
group_3d.o copoly.o txtrmap.o bits.o convpoly.o \
rendpoly.o rndrpoly.o rndzpoly.o zview.o rotate.o \
terrain.o earth.o colormap.o dvector.o flight.o \
weapons.o pilot.o fltlite.o moveable.o unguided.o \
fltzview.o viewobj.o fltmngr.o grndunit.o font8x8.o \
plltt.o key_map.o linux_joy.o siminput.o simfile.o hud.o \
cockpit.o instrmnt.o ppm.o mytimer.o colorspc.o \
globals.o portkey.o vtable2.o led2.o aaaunit.o \
waypoint.o fltobj.o simfilex.o simmath.o target.o \
sbrkeys.o aibase.o aiflite.o aigunner.o aipilot.o \
aipilot2.o aipilot3.o aipilot4.o aipilot5.o aipilot6.o \
sairfld.o sarray.o sattkr.o sfltmdl.o sfrmtn.o smath.o \
smnvrst.o spilcaps.o splncaps.o srunway.o sslewer.o \
stact.o starget.o sweapon.o sbfltmdl.o simsnd.o dhlist.o \
stime.o spid.o pilobj.o
sabre_DEPENDENCIES =  ../libzip/libcomp.a ../libzip/libuncl.a \
../gdev/libgdev.a
sabre_LDFLAGS = 
CXXCOMPILE = $(CXX) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CXXFLAGS) $(CXXFLAGS)
CXXLD = $(CXX)
CXXLINK = $(CXXLD) $(AM_CXXFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@
CFLAGS = -g -O2
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DIST_COMMON =  COPYING Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = tar
GZIP_ENV = --best
DEP_FILES =  .deps/aaaunit.P .deps/aibase.P .deps/aiflite.P \
.deps/aigunner.P .deps/aipilot.P .deps/aipilot2.P .deps/aipilot3.P \
.deps/aipilot4.P .deps/aipilot5.P .deps/aipilot6.P .deps/bits.P \
.deps/clip.P .deps/cockpit.P .deps/colormap.P .deps/colorspc.P \
.deps/convpoly.P .deps/copoly.P .deps/cpoly.P .deps/dhlist.P \
.deps/dvector.P .deps/earth.P .deps/flight.P .deps/fltlite.P \
.deps/fltmngr.P .deps/fltobj.P .deps/fltzview.P .deps/font8x8.P \
.deps/game.P .deps/globals.P .deps/grndunit.P .deps/group_3d.P \
.deps/hud.P .deps/input.P .deps/instrmnt.P .deps/kbdhit.P \
.deps/key_map.P .deps/led2.P .deps/linux_joy.P .deps/main.P \
.deps/moveable.P .deps/mytimer.P .deps/obj_3d.P .deps/pen.P \
.deps/pilobj.P .deps/pilot.P .deps/plltt.P .deps/port_3d.P \
.deps/portkey.P .deps/ppm.P .deps/rendpoly.P .deps/rndrpoly.P \
.deps/rndzpoly.P .deps/rotate.P .deps/sairfld.P .deps/sarray.P \
.deps/sattkr.P .deps/sbfltmdl.P .deps/sbrkeys.P .deps/scnedit.P \
.deps/sfltmdl.P .deps/sfrmtn.P .deps/simfile.P .deps/simfilex.P \
.deps/siminput.P .deps/simmath.P .deps/simsnd.P .deps/smath.P \
.deps/smnvrst.P .deps/spid.P .deps/spilcaps.P .deps/splncaps.P \
.deps/srunway.P .deps/sslewer.P .deps/stact.P .deps/starget.P \
.deps/stime.P .deps/sweapon.P .deps/target.P .deps/terrain.P \
.deps/transblt.P .deps/traveler.P .deps/txtrmap.P .deps/unguided.P \
.deps/vga_13.P .deps/viewobj.P .deps/vmath.P .deps/vtable2.P \
.deps/waypoint.P .deps/weapons.P .deps/zview.P
SOURCES = $(sabre_SOURCES)
OBJECTS = $(sabre_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .C .S .c .o .s
$(srcdir)/Makefile.in: Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) 
	cd $(top_srcdir) && $(AUTOMAKE) --foreign src/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status $(BUILT_SOURCES)
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-binPROGRAMS:

clean-binPROGRAMS:
	-test -z "$(bin_PROGRAMS)" || rm -f $(bin_PROGRAMS)

distclean-binPROGRAMS:

maintainer-clean-binPROGRAMS:

install-binPROGRAMS: $(bin_PROGRAMS)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(bindir)
	@list='$(bin_PROGRAMS)'; for p in $$list; do \
	  if test -f $$p; then \
	    echo "  $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`"; \
	     $(INSTALL_PROGRAM) $$p $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	  else :; fi; \
	done

uninstall-binPROGRAMS:
	@$(NORMAL_UNINSTALL)
	list='$(bin_PROGRAMS)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(bindir)/`echo $$p|sed 's/$(EXEEXT)$$//'|sed '$(transform)'|sed 's/$$/$(EXEEXT)/'`; \
	done

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

sabre: $(sabre_OBJECTS) $(sabre_DEPENDENCIES)
	@rm -f sabre
	$(CXXLINK) $(sabre_LDFLAGS) $(sabre_OBJECTS) $(sabre_LDADD) $(LIBS)
.C.o:
	$(CXXCOMPILE) -c $<

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags -o $$here/TAGS $(ETAGS_ARGS) $$tags  $$unique $(LISP))

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = src

distdir: $(DISTFILES)
	here=`cd $(top_builddir) && pwd`; \
	top_distdir=`cd $(top_distdir) && pwd`; \
	distdir=`cd $(distdir) && pwd`; \
	cd $(top_srcdir) \
	  && $(AUTOMAKE) --include-deps --build-dir=$$here --srcdir-name=$(top_srcdir) --output-dir=$$top_distdir --foreign src/Makefile
	@for file in $(DISTFILES); do \
	  d=$(srcdir); \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done

DEPS_MAGIC := $(shell mkdir .deps > /dev/null 2>&1 || :)

-include $(DEP_FILES)

mostlyclean-depend:

clean-depend:

distclean-depend:
	-rm -rf .deps

maintainer-clean-depend:

%.o: %.c
	@echo '$(COMPILE) -c $<'; \
	$(COMPILE) -Wp,-MD,.deps/$(*F).pp -c $<
	@-cp .deps/$(*F).pp .deps/$(*F).P; \
	tr ' ' '\012' < .deps/$(*F).pp \
	  | sed -e 's/^\\$$//' -e '/^$$/ d' -e '/:$$/ d' -e 's/$$/ :/' \
	    >> .deps/$(*F).P; \
	rm .deps/$(*F).pp

%.lo: %.c
	@echo '$(LTCOMPILE) -c $<'; \
	$(LTCOMPILE) -Wp,-MD,.deps/$(*F).pp -c $<
	@-sed -e 's/^\([^:]*\)\.o[ 	]*:/\1.lo \1.o :/' \
	  < .deps/$(*F).pp > .deps/$(*F).P; \
	tr ' ' '\012' < .deps/$(*F).pp \
	  | sed -e 's/^\\$$//' -e '/^$$/ d' -e '/:$$/ d' -e 's/$$/ :/' \
	    >> .deps/$(*F).P; \
	rm -f .deps/$(*F).pp

%.o: %.C
	@echo '$(CXXCOMPILE) -c $<'; \
	$(CXXCOMPILE) -Wp,-MD,.deps/$(*F).pp -c $<
	@-cp .deps/$(*F).pp .deps/$(*F).P; \
	tr ' ' '\012' < .deps/$(*F).pp \
	  | sed -e 's/^\\$$//' -e '/^$$/ d' -e '/:$$/ d' -e 's/$$/ :/' \
	    >> .deps/$(*F).P; \
	rm .deps/$(*F).pp

%.lo: %.C
	@echo '$(LTCXXCOMPILE) -c $<'; \
	$(LTCXXCOMPILE) -Wp,-MD,.deps/$(*F).pp -c $<
	@-sed -e 's/^\([^:]*\)\.o[ 	]*:/\1.lo \1.o :/' \
	  < .deps/$(*F).pp > .deps/$(*F).P; \
	tr ' ' '\012' < .deps/$(*F).pp \
	  | sed -e 's/^\\$$//' -e '/^$$/ d' -e '/:$$/ d' -e 's/$$/ :/' \
	    >> .deps/$(*F).P; \
	rm -f .deps/$(*F).pp
info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am: all-am
check: check-am
installcheck-am:
installcheck: installcheck-am
install-exec-am: install-binPROGRAMS
install-exec: install-exec-am

install-data-am:
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-binPROGRAMS
uninstall: uninstall-am
all-am: Makefile $(PROGRAMS) all-local
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(bindir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-binPROGRAMS mostlyclean-compile \
		mostlyclean-tags mostlyclean-depend mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-binPROGRAMS clean-compile clean-tags clean-depend \
		clean-generic mostlyclean-am

clean: clean-am

distclean-am:  distclean-binPROGRAMS distclean-compile distclean-tags \
		distclean-depend distclean-generic clean-am

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-binPROGRAMS \
		maintainer-clean-compile maintainer-clean-tags \
		maintainer-clean-depend maintainer-clean-generic \
		distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-binPROGRAMS distclean-binPROGRAMS clean-binPROGRAMS \
maintainer-clean-binPROGRAMS uninstall-binPROGRAMS install-binPROGRAMS \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir mostlyclean-depend \
distclean-depend clean-depend maintainer-clean-depend info-am info \
dvi-am dvi check check-am installcheck-am installcheck install-exec-am \
install-exec install-data-am install-data install-am install \
uninstall-am uninstall all-local all-redirect all-am all installdirs \
mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


all-local: $(sabre_OBJECTS)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
