all: clumpDriver

clumpDriver: computingFrequencies.o betterClumpFinding.o
	g++ computingFrequencies.o betterClumpFinding.o -o clumpDriver

computingFrequencies.o: computingFrequencies.cpp
	g++ -c computingFrequencies.cpp

betterClumpFinding.o: betterClumpFinding.cpp
	g++ -c betterClumpFinding.cpp 
