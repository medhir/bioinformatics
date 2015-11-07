#include <vector> 
#include <string>
#include "ch2.h"

std::vector<std::string> Neighbors(std::string pattern, int d)
{
  if(d == 0) 
  {
    std::vector<std::string> set = {pattern};
    return set;
  }
  if(pattern.length() == 1) 
  {
    std::vector<std::string> set = {"A", "C", "G", "T"};
    return set;
  }
  std::vector<std::string> Neighborhood;
  std::vector<std::string> SuffixNeighbors = Neighbors(Suffix(pattern), d);

  for(const auto& text : SuffixNeighbors) 
  {
    if(hammingDistance(Suffix(pattern), text) < d)
    {
      Neighborhood.push_back("A" + text);
      Neighborhood.push_back("C" + text);
      Neighborhood.push_back("T" + text);
      Neighborhood.push_back("G" + text);
    }
    else
    {
      Neighborhood.push_back(FirstSymbol(pattern) + text);
    }
  }

  return Neighborhood;
}

int hammingDistance(std::string a, std::string b)
{
  int distance = 0, length = a.length();
  for(int i = 0; i < length; ++i)
  {
    if(a[i] != b[i])
    {
      ++distance;
    }
  }
  return distance;
}

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

  //traverse all strings in Dna
  for(int i = 0; i < Dna.size(); ++i) 
  {
    for(int j = 0; j < Dna[i].length()-k; ++j)
    {
      std::string pattern = Dna[i].substr(j, k);
      std::vector<std::string> neighbors = Neighbors(pattern, d);
      for(int k = 0; k < neighbors.size(); ++k) 
      {
        if(patternExists(Dna, neighbors[k], d))
        {
          patterns.push_back(neighbors[k]);
        }
      }
    }
  }

  removeDuplicates(patterns);
}
