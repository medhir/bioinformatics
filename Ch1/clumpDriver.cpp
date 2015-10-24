#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string Genome; int k, L, t;
  std::cin >> Genome >> k >> L >> t;

  std::vector<std::string> frequentPatterns = BetterClumpFinding(Genome, k, t, L);

  //remove duplicates from frequent patterns
  std::sort(frequentPatterns.begin(), frequentPatterns.end());
  auto last = std::unique(frequentPatterns.begin(), frequentPatterns.end());
  frequentPatterns.erase(last, frequentPatterns.end());


  std::cout << frequentPatterns.size() << std::endl;

  return 0;
}
