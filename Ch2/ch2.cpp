#include <iostream>
#include <vector> 
#include <string>
#include <limits>
#include "../Ch1/computingFrequencies.h"
#include "ch2.h"

bool patternExistsInString(std::string pattern, std::string text, int d) 
{
  for(int i = 0; i <= text.length()-pattern.length(); ++i)
  {
    std::string compare = text.substr(i, pattern.length());
    if(hammingDistance(pattern, compare) <= d)
    {
      return true;
    }
  }
  return false;
}

bool patternExistsInSet(std::vector<std::string> Dna, std::string pattern, int d)
{
  for(int i = 0; i < Dna.size(); ++i)
  {
    if(!patternExistsInString(pattern, Dna[i], d))
    {
      return false;
    }
  }
  return true;
}

void removeDuplicates(std::vector<std::string> &set)
{
  std::sort(set.begin(), set.end());
  auto last = std::unique(set.begin(), set.end());
  set.erase(last, set.end());
}

std::vector<std::string> MotifEnumeration(std::vector<std::string> Dna, int k, int d)
{
  std::vector<std::string> patterns;

  for(int i = 0; i < Dna.size(); ++i) 
  {
    for(int j = 0; j <= Dna[i].length()-k; ++j)
    {
      std::string pattern = Dna[i].substr(j, k);
      std::vector<std::string> neighbors = Neighbors(pattern, d);
      for(int k = 0; k < neighbors.size(); ++k) 
      {
        if(patternExistsInSet(Dna, neighbors[k], d))
        {
          patterns.push_back(neighbors[k]);
        }
      }
    }
  }

  removeDuplicates(patterns);
  return patterns;
}

void generateKmers(int depth, int k, std::string base, std::vector<std::string> &set) 
{
  //adapted from http://stackoverflow.com/questions/5569453/c-output-all-possible-dna-kmers-of-a-given-length
  //recursively generate all possible sequences of length k
  if(depth == k)
  {
    set.push_back(base);
  }
  else 
  {
    char bases[] = {'A','C','G','T'};
    for(int i = 0; i < 4; ++i)
    {
      generateKmers(depth+1, k, base + bases[i], set);
    }
  }
}

int distance(std::string pattern, std::vector<std::string> dna)
{
  int sum = 0;
  for(const auto& text : dna) 
  {
    int min = std::numeric_limits<int>::max(), length = pattern.length();
    for(int i = 0; i <= (text.length()-length); ++i) 
    { 
      int hDist = hammingDistance(text.substr(i, length), pattern);
      if(hDist < min)
      {
        min = hDist;
      }
    }
    sum += min;
  }
  return sum;
}

std::string medianString(std::vector<std::string> dna, int k)
{
  int minDistance = std::numeric_limits<int>::max();
  std::vector<std::string> kmers; generateKmers(0, k, "", kmers);
  std::string medianString;

  for(const auto& kmer : kmers) 
  {
    int d = distance(kmer, dna);

    if(d < minDistance)
    {
      minDistance = d; medianString = kmer;
    }
  }

  return medianString;
}

double probabilty(std::string kmer, double **profile)
{
  double prob = 1;
  for(int i = 0; i < kmer.length(); ++i)
  {
    prob *= profile[SymbolToNum(kmer[i])][i];
  }
  return prob;
}

std::string profileMostProbableKmer(std::string text, int k, double **profile)
{
  double mostProbable = 0; std::string mostProbableKmer;
  for(int i=0; i <= text.length()-k; ++i)
  {
    std::string kmer = text.substr(i, k);
    double prob = probabilty(kmer, profile);
    if(prob > mostProbable)
    {
      mostProbable = prob;
      mostProbableKmer = kmer;
    }
  }
  return mostProbableKmer;
}

std::vector<std::string> extractMotifs(std::vector<std::string>& dna, int k)
{
  std::vector<std::string> motifs;
  for(int i = 0; i < dna.size(); ++i)
  {
    motifs.push_back(dna[i].substr(0, k));
  }
  return motifs;
}

double** initMatrix(int rows, int columns)
{
  double** matrix; matrix = new double *[rows];
  for(int i = 0; i < 4; ++i)
  {
    profile[i] = new double[columns];
    for(int j = 0; j < columns; ++j)
    {
      profile[i][j] = 0;
    }
  }
  return profile;
}

double** generateProfileMatrix(std::vector<std::string> motifs, int k)
{
  double** profile = initMatrix(4, k);
  int rows = motifs.size();

  //generate count matrix
  for(int i = 0; i < rows; ++i)
  {
    for(int j = 0; j < k; ++j)
    {
      profile[SymbolToNum(motifs[i][j])][j]++;
    }
  }

  //generate profile matrix from count matrix
  for(int i = 0; i < rows; ++i)
  {
    for(int j = 0; j < k; ++j)
    {
      profile[i][j] = profile[i][j] / rows;
    }
  }

  return profile;
}

std::string consensusString(double** profile, int k)
{
  std::string consensus;
  for(int j = 0; i < k; ++j) 
  { 
    double maxProb = 0; int consensusIndex;
    for(int i = 0; i < 4; ++i)
    {
      if(profile[i][j] > maxProb)
      {
        maxProb = profile[i][j];
        consensusIndex = i;
      }
    }
    consensus.push_back(NumToSymbol(consensusIndex));
  }
  return consensus;
}

int score(std::vector<std::string> motifs, int k)
{
  double** profile = generateProfileMatrix(motifs, k);
  std::string consensus = consensusString(profile, k);
  int score;

  for(int i = 0; i < motifs.size(); ++i)
  {
    score += hammingDistance(motifs[i], consensus);
  }

  return score;
}

std::vector<std::string> greedyMotifSearch(std::vector<std::string> dna, int k, int t)
{
  std::vector<std::string> bestMotifs = extractMotifs(dna, k);
  std::string firstString = dna[0];

  for(int i = 0; i <= firstString.length()-k; ++i)
  {
    std::vector<std::string> motifs;
    motifs.push_back(firstString.substr(i, k));
    for(int j = 2; j <= t; ++j)
    {
      double** profile = generateProfileMatrix(motifs, k);
      motifs.push_back(profileMostProbableKmer(motifs[j], k, profile));
    }

    if(score(motifs, k) < score(bestMotifs, k))
    {
      bestMotifs = motifs;
    }
  }

  return motifs;
}
