CC = g++
CCFLAGS = -lgmpxx -lgmp
DEPS = gmp.h
all: tate_pairing
	tate_pairing: $(CC) tate_pairing.cpp 
	$< $(CCFLAGS)