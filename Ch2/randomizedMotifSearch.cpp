#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>
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

  srand(time(NULL)); //initialize random seed

  int bestScore = std::numeric_limits<int>::max();
  std::vector<std::string> bestMotifs;

  for(int i = 0; i < 1000; ++i)
  {
    std::vector<std::string> motifs = randomizedMotifSearch(dna, k, t);
    int motifScore = score(motifs, k);
    if(motifScore <= bestScore)
    {
      bestScore = motifScore; 
      bestMotifs = motifs;
    }
  }

  for(const auto& motif : bestMotifs)
  {
    std::cout << motif << std::endl;
  }

  return 0;
}