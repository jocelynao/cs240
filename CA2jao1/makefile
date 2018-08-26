
all:	 Donate

Donate:	CA2.o Donor.o DonorDatabase.o
	g++ CA2.o Donor.o DonorDatabase.o -o Donate

CA2.o:	CA2.cpp 
	g++ -c CA2.cpp
DonorDatabase.o: DonorDatabase.cpp 
	g++ -c DonorDatabase.cpp
Donor.o: Donor.cpp
	g++ -c Donor.cpp
clean:
	rm -f *.o Donate
