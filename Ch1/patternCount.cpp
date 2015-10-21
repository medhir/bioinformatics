#include <iostream>
#include <string>

int PatternCount(std::string Text, std::string Pattern) {
  int count = 0; 
  for(int i = 0; i < Text.length() - Pattern.length(); ++i) {
    if(Text.substr(i, Pattern.length()) == Pattern) {
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
