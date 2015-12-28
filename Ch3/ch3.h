#ifndef CH2_H
#define CH2_H

void printVector(std::vector<std::string> stringVector);
std::vector<std::string> composition(std::string text, int k);

std::string reconstructFromGenomePath(std::vector<std::string> patterns);

void printOverlapGraph(std::vector<std::string> patterns, int** adjacencyMatrix);
std::string Prefix(std::string kmer);
std::string Suffix(std::string kmer);
int** adjacencyMatrix(int n);
int** overlapGraph(std::vector<std::string> patterns);

void printPathGraph(int k, std::vector<std::string>& nodes, int** pathGraph);
std::vector<std::string> Nodes(int k, std::string text);
int** glueNodes(int first, int second, std::vector<std::string>& nodes, int** pathGraph);
int** PathGraph(int numNodes);
int** DeBruijn(int k, std::string text, std::vector<std::string>& nodes);

#endif