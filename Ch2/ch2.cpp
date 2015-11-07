#include <iostream>
#include <vector> 
#include <string>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

bool patternExistsInString(std::string pattern, std::string text, int d) 
{
  for(int i = 0; i <= text.length()-pattern.length(); ++i)
  {
    std::string compare = text.substr(i, pattern.length());
    if(hammingDistance(pattern, compare) <= d)
    {
      return true;
    }
  }
  return false;
}

bool patternExistsInSet(std::vector<std::string> Dna, std::string pattern, int d)
{
  for(int i = 0; i < Dna.size(); ++i)
  {
    if(!patternExistsInString(pattern, Dna[i], d))
    {
      return false;
    }
  }
  return true;
}

void removeDuplicates(std::vector<std::string> &set)
{
  std::sort(set.begin(), set.end());
  auto last = std::unique(set.begin(), set.end());
  set.erase(last, set.end());
}

std::vector<std::string> MotifEnumeration(std::vector<std::string> Dna, int k, int d)
{
  std::vector<std::string> patterns;

  for(int i = 0; i < Dna.size(); ++i) 
  {
    for(int j = 0; j <= Dna[i].length()-k; ++j)
    {
      std::string pattern = Dna[i].substr(j, k);
      std::vector<std::string> neighbors = Neighbors(pattern, d);
      for(int k = 0; k < neighbors.size(); ++k) 
      {
        if(patternExistsInSet(Dna, neighbors[k], d))
        {
          patterns.push_back(neighbors[k]);
        }
      }
    }
  }

  removeDuplicates(patterns);
  return patterns;
}
