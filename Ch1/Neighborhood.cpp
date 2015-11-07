#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string pattern; int d;
  std::cin >> pattern >> d;

  std::vector<std::string> Neighborhood = Neighbors(pattern, d);

  std::cout << "Size of " << d << "-neighborhood of " << pattern << " is " << Neighborhood.size() << std::endl;

  for(const auto& neighbor : Neighborhood) 
  {
    std::cout << neighbor << std::endl;
  }
  
  return 0;
}
