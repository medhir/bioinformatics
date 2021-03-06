#ifndef CH2_H
#define CH2_H

void printStrings(std::vector<std::string>& set);

bool patternExistsInString(std::string pattern, std::string text, int d);
bool patternExistsInSet(std::vector<std::string> Dna, std::string pattern, int d);
void removeDuplicates(std::vector<std::string> &set);

std::vector<std::string> MotifEnumeration(std::vector<std::string> dna, int k, int d);

void generateKmers(int depth, int k, std::string base, std::vector<std::string> &set); 
int distance(std::string pattern, std::vector<std::string> dna);
std::string medianString(std::vector<std::string> dna, int k);

double probability(std::string kmer, double **profile);
std::string profileMostProbableKmer(std::string text, int k, double **profile);

std::vector<std::string> extractMotifs(std::vector<std::string>& dna, int k);
double** initMatrix(int rows, int columns);
double** generateProfileMatrix(std::vector<std::string> motifs, int k);
std::string consensusString(double** profile, int k);
int score(std::vector<std::string> motifs, int k);
std::vector<std::string> greedyMotifSearch(std::vector<std::string> dna, int k, int t);

int generateRandomNumber(int min, int max);
std::vector<std::string> randomSelect(std::vector<std::string> dna, int k);
std::vector<std::string> generateMotifs(double** profile, std::vector<std::string> dna, int k);
std::vector<std::string> randomizedMotifSearch(std::vector<std::string> dna, int k, int t);

std::string profileRandomlyGeneratedKmer(std::string text, int k, double** profile);
std::vector<std::string> gibbsSampler(std::vector<std::string> dna, int k, int t, int N);

#endif
