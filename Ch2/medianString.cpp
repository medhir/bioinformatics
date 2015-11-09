#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

int main() 
{
  std::string pattern, text; std::cin >> pattern;
  std::vector<std::string> dna;

  while(std::cin >> text)
  { 
    dna.push_back(text);
  }

  std::cout << distance(pattern, dna) << std::endl;
  return 0;
}