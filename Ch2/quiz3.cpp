#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include <random>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

int main()
{
  std::string kmer; int k; double prob;
  std::cin >> kmer; std::cin >> k;

  double** profile; profile = new double *[4];
  for(int i = 0; i < 4; ++i)
  {
    profile[i] = new double[k];
    for(int j = 0; j < k; ++j) 
    {
      std::cin >> prob;
      profile[i][j] = prob;
    }
  }

  std::cout << probability(kmer, profile) << std::endl;
}