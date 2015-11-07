#ifndef CH2_H
#define CH2_H

bool patternExistsInString(std::string pattern, std::string text, int d);
bool patternExistsInSet(std::vector<std::string> Dna, std::string pattern, int d);
void removeDuplicates(std::vector<std::string> &set);

std::vector<std::string> MotifEnumeration(std::vector<std::string> dna, int k, int d);

#endif
