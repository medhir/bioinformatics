#include <iostream>
#include <string>
#include <math.h>

char NumToSymbol(int num) 
{
  if (num == 0) return 'A';
  else if (num == 1) return 'C';
  else if (num == 2) return 'G';
  else if (num == 3) return 'T';
}

int SymbolToNum(char symbol) 
{
  if (symbol == 'A') return 0;
  else if (symbol == 'C') return 1;
  else if (symbol == 'G') return 2;
  else if (symbol == 'T') return 3;
  else return -1;
}

std::string NumToPattern(int index, int k)
{
  if (k == 1) 
  {
    std::string symbol = "";
    symbol += NumToSymbol(index);
    return symbol;
  }

  int prefixIndex = index/4;
  int r = index - prefixIndex*4;
  char symbol = NumToSymbol(r);

  std::string PrefixPattern = NumToPattern(prefixIndex, k-1);
  return PrefixPattern + symbol;
}


int PatternToNum(std::string pattern) 
{
  //compute number based on sequence pattern
  if(pattern.length() == 0) 
  {
    return 0; 
  }

  char symbol = pattern.back();
  std::string prefix = pattern.substr(0, pattern.length()-1);
  return 4 * PatternToNum(prefix) + SymbolToNum(symbol);
}

int computeFrequencies(std::string Text, int k) 
{
  int length = pow(4, k);
  int frequencyArray[length];
  for(int i = 0; i < length; ++i)
  {
    frequencyArray[i] = 0;
  }
}

int main()
{
  int index, k; std::cin >> index >> k;
  std::cout << NumToPattern(index, k) << std::endl;
  return 0;
}
