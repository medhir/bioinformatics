#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include <random>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

int main()
{
  int k, t, N; std::cin >> k >> t >> N;
  std::vector<std::string> dna, motifs; std::string text;
  for(int i = 0; i < t; ++i)
  {
    std::cin >> text; dna.push_back(text);
  }

  motifs = gibbsSampler(dna, k, t, N);

  for(const auto& motif : motifs)
  {
    std::cout << motif << std::endl;
  }
  std::cout << "Score: " << score(motifs, k) << std::endl;
}