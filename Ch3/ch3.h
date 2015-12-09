#ifndef CH2_H
#define CH2_H

void printVector(std::vector<std::string> stringVector);
std::vector<std::string> composition(std::string text, int k);

std::string reconstructFromGenomePath(std::vector<std::string> patterns);

void printGraph(std::vector<std::string> patterns, bool** adjacencyMatrix, int n);
std::string Prefix(std::string kmer);
std::string Suffix(std::string kmer);
bool** adjacencyMatrix(int n);
bool** overlapGraph(std::vector<std::string> patterns);

#endif