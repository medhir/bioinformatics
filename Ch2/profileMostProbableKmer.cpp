#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

int main()
{
  std::string text; std::cin >> text;
  int k = 0; std::cin >> k;

  double prob; 
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

  std::cout << profileMostProbableKmer(text, k, profile) << std::endl;
  return 0;
}