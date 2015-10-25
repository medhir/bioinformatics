#ifndef COMPUTINGFREQUENCIES_H
#define COMPUTINGFREQUENCIES_H

//function definitions

char NumberToSymbol(int num);
int SymbolToNum(char symbol);

std::string NumToPattern(int index, int k);
int PatternToNum(std::string Pattern);

std::string extract(int i, std::string Text, int patternLength);

//frequency array generator
int* computeFrequencies(std::string Genome, int k);

//clump finding algorithm
std::vector<std::string> BetterClumpFinding(std::string Genome, int k, int t, int L);

//skew calculation
int findMin(int* array, int length);
int* determineSkew(std::string Genome);
std::vector<int> minimumSkew(std::string Genome);

//hamming distance
int hammingDistance(std::string a, std::string b);

//approximate pattern matching
std::vector<int> approximateMatching(std::string pattern, std::string text, int d);

#endif
