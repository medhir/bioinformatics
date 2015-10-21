#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string Genome; int k, L, t;
  std::cin >> Genome >> k >> L >> t;
  
  std::vector<std::string> frequentPatterns = BetterClumpFinding(Genome, k, t, L);

  for(const auto &i : frequentPatterns) 
  {
    std::cout << i << " ";
  }

  std::cout << std::endl;

  return 0;
}
