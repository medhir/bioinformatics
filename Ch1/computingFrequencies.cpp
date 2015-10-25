#include <iostream>
#include <string>
#include <vector>
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

std::vector<std::string> BetterClumpFinding(std::string Genome, int k, int t, int L) 
{
  std::vector<std::string> frequentPatterns;
  int entries = pow(4, k);
  int clump[entries];

  for(int i = 0; i < entries; ++i) 
  {
    clump[i] = 0;  
  }

  std::string Text = Genome.substr(0, L);
  int* frequencyArray = computeFrequencies(Text, k);

  for(int i = 0; i < entries; ++i)
  {
    if(frequencyArray[i] >= t) 
    {
      clump[i] = 1;
    }
  }

  for(int i = 0; i <= (Genome.length()-L); ++i)
  {
    std::string firstPattern, lastPattern; int index;
    if(i > 0) 
    {
      firstPattern = Genome.substr(i-1, k); 
      index = PatternToNum(firstPattern);
      frequencyArray[index] -= 1;
    }

    if(i <= Genome.length()-L) 
    {
      lastPattern = Genome.substr(i+L-k, k);
      index = PatternToNum(lastPattern);
      frequencyArray[index] += 1;
    }

    if(frequencyArray[index] >= t) 
    {
      clump[index] = 1;
    }
  }

  for(int i = 0; i < entries; ++i) 
  {
    if(clump[i] == 1)
    {
      std::string pattern = NumToPattern(i, k);
      frequentPatterns.push_back(pattern);
    }
  }

  return frequentPatterns;
}

int* determineSkew(std::string Genome) 
{
  int length = Genome.length();
  int* skew = new int[length];
  skew[0] = 0;

  for(int i = 1; i <= length; ++i)
  {
    if(Genome[i-1] == 'G') 
    {
      skew[i] = skew[i-1] + 1;
    }
    else if(Genome[i-1] == 'C') 
    {
      skew[i] = skew[i-1] - 1;
    }
    else 
    {
      skew[i] = skew[i-1];
    }
  }

  return skew;
}

int findMin(int* array, int length) 
{
  int min = array[0];
  for(int i = 1; i < length; ++i)
  {
    if(array[i] < min)
    {
      min = array[i];
    }
  }
  return min;
}

std::vector<int> minimumSkew(std::string Genome) 
{
  int* skew = determineSkew(Genome);
  int length = Genome.length(), min = findMin(skew, length);
  std::vector<int> minIndeces;
  for(int i = 0; i < length; ++i) 
  {
    if(skew[i] == min)
    {
      minIndeces.push_back(i);
    }
  }
  return minIndeces;
}
