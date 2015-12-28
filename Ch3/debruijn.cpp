#include <iostream>
#include <string> 
#include <vector>
#include "ch3.h"

int main()
{
  int k; std::string text;
  std::cin >> k >> text;

  std::vector<std::string> nodes = Nodes(k, text);
  int** debruijn = DeBruijn(k, text, nodes);

  for(int i = 0; i < nodes.size(); ++i)
  {
    std::vector<std::string> list;
    for(int j = 0; j < nodes.size(); ++j)
    {
      int count = debruijn[i][j];
      while(count--)
      {
        list.push_back(nodes[j]);
      }
    }

    if(nodes.size() > 0)
    {
      int commas = list.size()-1;
      std::cout << nodes[i] << " -> ";
      for(const auto& node : list)
      {
        std::cout << node;
        if(commas--)
        {
          std::cout << ",";
        }
      }
      std::cout << std::endl;
    }
  }
}