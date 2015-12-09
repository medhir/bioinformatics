#include <iostream>
#include <string> 
#include <vector>
#include "ch3.h"

void printVector(std::vector<std::string> stringVector)
{
  for(const auto& string : stringVector)
  {
    std::cout << string << std::endl;
  }
}

std::vector<std::string> composition(std::string text, int k)
{
  std::vector<std::string> composition;
  for(int i = 0; i <= text.length()-k; ++i)
  { 
    composition.push_back(text.substr(i, k));
  }
  return composition;
}

std::string reconstructFromGenomePath(std::vector<std::string> patterns)
{
  std::string text = patterns[0];
  int length = patterns[0].length();
  for(int i = 1; i < patterns.size(); ++i)
  {
    text += patterns[i][length-1];
  }
  return text;
}

void printGraph(std::vector<std::string> patterns, bool** adjacencyMatrix, int n)
{
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      if(adjacencyMatrix[i][j] == 1)
      {
        std::cout << patterns[i] << " -> " << patterns[j] << std::endl;
      }
    }
  }
}

std::string Prefix(std::string kmer)
{
  int length = kmer.length()-1;
  return kmer.substr(0, length);
}

std::string Suffix(std::string kmer) 
{
  int length = kmer.length()-1;
  return kmer.substr(1, length);
}

bool** adjacencyMatrix(int n) 
{
  bool** matrix; matrix = new bool *[n];
  for(int i = 0; i < n; ++i)
  {
    matrix[i] = new bool[n];
    for(int j = 0; j < n; ++j)
    {
      matrix[i][j] = 0;
    }
  }
  return matrix;
}

bool** overlapGraph(std::vector<std::string> patterns)
{
  int n = patterns.size();
  bool** graph = adjacencyMatrix(n);

  for(int i = 0; i < n; ++i)
  {
    std::string suffix = Suffix(patterns[i]);
    for(int j = 0; j < n; ++j)
    {
      std::string prefix = Prefix(patterns[i]);
      if(suffix == prefix)
      {
        graph[i][j] = 1;
      }
    }
  }

  return graph;
}
