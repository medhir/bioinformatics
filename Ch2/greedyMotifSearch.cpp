#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

int main()
{
  int k, t; std::string text; std::vector<std::string> dna;
  std::cin >> k >> t; 
  while(std::cin >> text)
  {
    dna.push_back(text);
  }

  std::vector<std::string> motifs = greedyMotifSearch(dna, k, t);
  for(const auto& motif : motifs) 
  {
    std::cout << motif << std::endl;
  }

  return 0;
}