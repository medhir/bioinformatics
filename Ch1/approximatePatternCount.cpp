#include <iostream>
#include <string>
#include <vector>
#include "computingFrequencies.h"

int main() 
{
  std::string pattern, text; int d;
  std::cin >> pattern >> text >> d;

  int count = 0;
  for(int i = 0; i <= (text.length() - pattern.length()); ++i)
  {
    std::string compare = text.substr(i, pattern.length());
    if(hammingDistance(pattern, compare) <= d) 
    {
      ++count;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
