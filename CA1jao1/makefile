
all:	 Donate

Donate:	CA1.o AoJocelynDonorFunctions.o
	g++ CA1.o AoJocelynDonorFunctions.o -o Donate

CA1.o:	CA1.cpp CA1H.h
	g++ -c CA1.cpp
AoJocelynDonorFunctions.o:	AoJocelynDonorFunctions.cpp CA1H.h
	g++ -c AoJocelynDonorFunctions.cpp
clean:
	rm -f *.o Donate.exe
