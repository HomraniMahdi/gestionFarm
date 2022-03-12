## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = ajouter

ajouter_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	ouvrier.c ouvrier.h \
	calendrier.c calendrier.h \
        capteur.c capteur.h \
	equipement.c equipement.h \
	verification.h verification.c \
	verificationA.h verificationA.c \
	troupeaux.c troupeaux.h \
	client.c client.h \
	fonction.c fonction.h \
	absenteisme.c absenteisme.h \
	captdef.c captdef.h \
	capteurtache2.c capteurtache2.h
   

ajouter_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

