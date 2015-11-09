#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

int main() 
{
  int k; std::cin >> k; 
  std::string text; std::vector<std::string> dna;

  while(std::cin >> text)
  { 
    dna.push_back(text);
  }

  std::cout << medianString(dna, k) << std::endl;
  return 0;
}