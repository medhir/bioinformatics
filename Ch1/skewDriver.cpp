#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string Genome; std::cin >> Genome;
  int* skew = determineSkew(Genome);

  for(int i = 0; i <= Genome.length(); ++i) 
  {
    std::cout << skew[i] << " ";
  }

  std::cout << std::endl;
  return 0;
}
