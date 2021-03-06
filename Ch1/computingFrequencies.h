#ifndef COMPUTINGFREQUENCIES_H
#define COMPUTINGFREQUENCIES_H

//function definitions

char NumToSymbol(int num);
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
int approximatePatternCount(std::string text, std::string pattern, int d);

//Neighborhood of a string
std::string Suffix(std::string pattern);
std::string FirstSymbol(std::string pattern);
std::vector<std::string> Neighbors(std::string pattern, int d);

//frequent words with mismatches
int findMax(int* array, int length);
std::string reverseComplement(std::string pattern);
std::vector<std::string> FrequentWordsWithMismatches(std::string text, int k, int d);
std::vector<std::string> FrequentWordsWithMismatchesAndReverseComplements(std::string text, int k, int d);

#endif
