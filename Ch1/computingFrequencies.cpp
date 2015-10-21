#include <iostream>
#include <string>
#include <math.h>
#include "computingFrequencies.h"

char NumToSymbol(int num) 
{
  if (num == 0) return 'A';
  else if (num == 1) return 'C';
  else if (num == 2) return 'G';
  else if (num == 3) return 'T';
}

int SymbolToNum(char symbol) 
{
  if (symbol == 'A') return 0;
  else if (symbol == 'C') return 1;
  else if (symbol == 'G') return 2;
  else if (symbol == 'T') return 3;
  else return -1;
}

std::string NumToPattern(int index, int k)
{
  if (k == 1) 
  {
    std::string symbol = "";
    symbol += NumToSymbol(index);
    return symbol;
  }

  int prefixIndex = index/4;
  int r = index - prefixIndex*4;
  char symbol = NumToSymbol(r);

  std::string PrefixPattern = NumToPattern(prefixIndex, k-1);
  return PrefixPattern + symbol;
}


int PatternToNum(std::string pattern) 
{
  //compute number based on sequence pattern
  if(pattern.length() == 0) 
  {
    return 0; 
  }

  char symbol = *pattern.rbegin(); //retrieve last element of pattern
  std::string prefix = pattern.substr(0, pattern.length()-1);
  return 4 * PatternToNum(prefix) + SymbolToNum(symbol);
}

std::string extract(int i, std::string Text, int patternLength) {
  //return a string
  std::string compare;

  //starting at i, add chars to compare until it is |pattern|
  for(int j = i, k = 0; k < patternLength; ++j, ++k) {
    compare += Text[j];
  }
  return compare;
}

int* computeFrequencies(std::string Genome, int k) 
{
  int length = pow(4, k), traversalLength = Genome.length() - k;
  int *frequencyArray = new int[length];

  for(int i = 0; i < length; ++i)
  {
    frequencyArray[i] = 0;
  }

  for(int i = 0; i <= traversalLength; ++i) 
  {
    std::string Pattern = extract(i, Genome, k);
    int j = PatternToNum(Pattern);
    frequencyArray[j]++;
  }

  return frequencyArray;
}
