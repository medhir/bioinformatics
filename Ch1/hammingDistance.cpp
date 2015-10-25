#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string a, b; 
  std::cin >> a >> b;
  std::cout << hammingDistance(a, b) << std::endl;
  return 0;
}
