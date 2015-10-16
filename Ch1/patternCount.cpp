#include <iostream>
#include <string>

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

int main() {
  std::string genome, pattern;

  int pCount = PatternCount(genome, pattern);
  std::cout << pCount << std::endl;

  return 0;
}
