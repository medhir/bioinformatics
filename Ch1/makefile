all: clumpDriver

clumpFinder: computingFrequencies.o betterClumpFinding.o clumpDriver.o
	g++ computingFrequencies.o betterClumpFinding.o clumpDriver.o -o clumpFinder

clumpDriver.o: clumpDriver.cpp
	g++ -c clumpDriver.cpp

computingFrequencies.o: computingFrequencies.cpp
	g++ -c computingFrequencies.cpp

betterClumpFinding.o: betterClumpFinding.cpp
	g++ -c betterClumpFinding.cpp 
