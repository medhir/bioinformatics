#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string pattern; int d;
  std::cin >> pattern >> d;

  std::vector<std::string> Neighborhood = Neighbors(pattern, d);

  for(const auto& neighbor : Neighborhood) 
  {
    std::cout << neighbor << std::endl;
  }
  
  return 0;
}
