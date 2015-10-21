#include <iostream>
#include <string>
#include <math.h>
#include "computingFrequencies.h"

int main()
{
  std::string Genome; int k; 
  std::cin >> Genome >> k;

  int* frequencies = computeFrequencies(Genome, k);
  int freqArrayLength = pow(4, k);

  for (int i = 0; i < pow(4, k); ++i) 
  {
    std::cout << frequencies[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}
