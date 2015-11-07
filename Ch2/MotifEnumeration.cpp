#include <iostream>
#include <string>
#include <vector>
#include "ch2.h"

int main() 
{
  int k, d; std::vector<std::string> Dna, motifs;
  std::cin >> k >> d;
  std::string line;
  while(std::cin >> line)
  {
    Dna.push_back(line);
  }

  motifs = MotifEnumeration(Dna, k, d);

  for(const auto& motif : motifs) 
  {
    std::cout << motif << " ";
  }
  std::cout << std::endl;
} 
