DIRS	= Build

TARGETS: clean all

all: 
	-for d in $(DIRS); do (cd $$d; $(MAKE) $(MFLAGS) all ); done

clean: 
	-for d in $(DIRS); do (cd $$d; $(MAKE) $(MFLAGS) clean ); done

