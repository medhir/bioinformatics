#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "computingFrequencies.h"
#include "betterClumpFinding.h"

std::vector<std::string> BetterClumpFinding(std::string Genome, int k, int t, int L) 
{
  std::vector<std::string> frequentPatterns;
  int entries = pow(4, k);
  int clump[entries];

  for(int i = 0; i < freqArraySize; ++i) 
  {
    clump[i] = 0;  
  }

  std::string Text = Genome.substr(0, L);
  int* frequencyArray = computingFrequencies(Text, k);

  for(int i = 0; i < entries; ++i)
  {
    if(frequencyArray[i] >= t) 
    {
      clump[i] = 1
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

