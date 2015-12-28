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

void printOverlapGraph(std::vector<std::string> patterns, int** adjacencyMatrix)
{
  int n = patterns.size();
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

int** adjacencyMatrix(int n) 
{
  int** matrix; matrix = new int *[n];
  for(int i = 0; i < n; ++i)
  {
    matrix[i] = new int[n];
    for(int j = 0; j < n; ++j)
    {
      matrix[i][j] = 0;
    }
  }
  return matrix;
}

int** overlapGraph(std::vector<std::string> patterns)
{
  int n = patterns.size();
  int** graph = adjacencyMatrix(n);

  for(int i = 0; i < n; ++i)
  {
    std::string suffix = Suffix(patterns[i]);
    for(int j = 0; j < n; ++j)
    {
      std::string prefix = Prefix(patterns[j]);
      if(suffix == prefix)
      {
        graph[i][j] = 1;
      }
    }
  }

  return graph;
}

void printPathGraph(int k, std::vector<std::string>& nodes, int** pathGraph)
{
  int spaces = k; 
  while(spaces--)
  {
    std::cout << " ";
  }

  for(int i = 0; i < nodes.size(); ++i)
  {
    std::cout << nodes[i] << " ";
  }

  std::cout << std::endl;

  for(int i = 0; i < nodes.size(); ++i)
  {
    std::cout << nodes[i] << " ";
    for(int j = 0; j < nodes.size(); ++j)
    {
      std::cout << " " << pathGraph[i][j] << "  ";
    }
    std::cout << std::endl;
  }
}

std::vector<std::string> Nodes(int k, std::string text)
{
  std::vector<std::string> nodes;
  for(int i = 0; i <= text.length()-k+1; ++i)
  { 
    nodes.push_back(text.substr(i, k-1));
  } 
  return nodes;
}

int** glueNodes(int first, int second, std::vector<std::string>& nodes, int** pathGraph)
{
  int numNodes = nodes.size()-1;
  int** newGraph = adjacencyMatrix(numNodes);

  //combine columns
  for(int i = 0; i < nodes.size(); ++i)
  {
    pathGraph[i][first] += pathGraph[i][second];
  }

  //combine rows 
  for(int i = 0; i < nodes.size(); ++i)
  {
    pathGraph[first][i] += pathGraph[second][i];
  }

  //place values in new graph
  for(int i = 0, ii = 0; i < numNodes; ++i, ++ii)
  {
    if(i == second) ++ii;
    for(int j = 0, jj = 0; j < numNodes; ++j, ++jj)
    {
      if(j == second) ++jj;
      newGraph[i][j] = pathGraph[ii][jj];
    }
  }

  // delete node from vector
  nodes.erase(nodes.begin()+second);

  return newGraph;
}

int** PathGraph(int numNodes)
{
  int** graph = adjacencyMatrix(numNodes);

  for(int i = 0; i < numNodes-1; ++i)
  {
    graph[i][i+1] = 1;
  }

  return graph;
}


int** DeBruijn(int k, std::string text, std::vector<std::string>& nodes)
{
  //create path graph
  int** pathGraph = PathGraph(nodes.size());

  for(int i = 0; i < nodes.size(); ++i)
  {
    for(int j = 0; j < nodes.size(); ++j)
    {
      if(nodes[i] == nodes[j] && i != j)
      {
        pathGraph = glueNodes(i, j, nodes, pathGraph);
      }
    }
  }

  return pathGraph;
}