#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string pattern, text; int d; 
  std::cin >> pattern >> text >> d;
  
  std::vector<int> indeces = approximateMatching(pattern, text, d);

  for(const auto& i : indeces) 
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
