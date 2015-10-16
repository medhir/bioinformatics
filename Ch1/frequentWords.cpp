#include <iostream>
#include <string>
#include <vector>

std::string extract(int i, std::string Text, int patternLength) {
  //return a string to be returned
  std::string compare;

  //starting at i, add chars to compare until it is |pattern|
  for(int j = i, k = 0; k < patternLength; ++j, ++k) {
    compare += Text[j];
  }
  return compare;
}

int PatternCount(std::string Text, std::string Pattern) {
  int count = 0; 
  for(int i = 0; i < Text.length() - Pattern.length(); ++i) {
    if(extract(i, Text, Pattern.length()) == Pattern) {
      ++count;
    }
  }
  return count;
}

std::vector<std::string> frequentWords(std::string genome, int k) {
  std::vector<std::string> frequent_patterns;

  int traversalLength = genome.length() - k;
  int count[traversalLength];

  for(int i = 0; i <= traversalLength; ++i) {
    std::string pattern = extract(i, genome, k);
    count[i] = PatternCount(genome, pattern);
  }

  int maxCount;
  for(int i = 0; i < traversalLength; ++i) {
    if(count[i] > maxCount) {
      maxCount = count[i];
    }
  }

  for(int i = 0; i <= traversalLength; ++i) {
    if(count[i] == maxCount) {
      frequent_patterns.push_back(extract(i, genome, k));
    }
  }

  //remove duplicates from frequent patterns
  std::sort(frequent_patterns.begin(), frequent_patterns.end());
  auto last = std::unique(frequent_patterns.begin(), frequent_patterns.end());
  frequent_patterns.erase(last, frequent_patterns.end());

  return frequent_patterns;
}

int main() {
  std::string genome; int k;
  std::cin >> genome >> k;

  std::vector<std::string> frequentPatterns = frequentWords(genome, k);

  for( const auto& i : frequentPatterns ) {
    std::cout << i << " ";   
  }
  std::cout << std::endl;
}
