#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string Text; int k, d;
  std::cin >> Text >> k >> d;

  std::vector<std::string> FrequentPatterns = FrequentWordsWithMismatches(Text, k, d);

  for(const auto& pattern : FrequentPatterns) 
  {
    std::cout << pattern << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
