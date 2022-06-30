IDIR = ../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm -lncurses

_DEPS = CommonVector.h globVar.h  Measurement.h FillArr.h menu.h MesRes.h Sorts.h conio.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Sorts.o MesRes.o menu.o Measurement.o FillArr.o  main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $ $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
