#include <iostream>
#include <string> 
#include <vector>
#include "ch3.h"

int main()
{
  int k; std::string text;
  std::cin >> k >> text;
  printVector(composition(text, k));
}