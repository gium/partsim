CXX=g++
CXXFLAGS=
EXE=simulateur
all: $(EXE)
RANDOM = `perl -e 'print int(rand()*34000)'`

$(EXE): main.cc force_calc.hxx particule.hxx rand.hxx signe.hxx simulation.hxx constant.hh
	$(CXX) $(CXXFLAGS) main.cc -o $(EXE) -DSEED=$(RANDOM)

clean:
	rm -f *~
distclean: clean
	rm -f $(EXE)
	rm -f *.tar.bz2

dist: distclean
	tar cjf $(EXE).tar.bz2 -C .. simulateur --exclude='*.tar.bz2'

