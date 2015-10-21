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

#endif
