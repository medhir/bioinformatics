#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string pattern, text; int d;
  std::cin >> pattern >> text >> d;

  int count = approximatePatternCount(pattern, text, d);

  std::cout << count << std::endl;

  return 0;
}
