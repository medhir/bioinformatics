#include <iostream>
#include <string> 
#include <vector>
#include "ch3.h"

int main()
{
  std::string text; std::vector<std::string> patterns;
  while(std::cin >> text)
  {
    patterns.push_back(text);
  }

  std::cout << reconstructFromGenomePath(patterns) << std::endl;
}