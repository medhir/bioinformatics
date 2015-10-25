#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string Genome; 
  std::cin >> Genome;
  std::vector<int> indeces = minimumSkew(Genome); 

  for(const auto& i : indeces) 
  {
    std::cout << i << " ";
  }

  std::cout << std::endl;
  return 0;
}
