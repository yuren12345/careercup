#include <iostream>

/**
 * Implement an algorithm to print all valid (e.g., properly opened and closed)
 * combinations of n-pairs of parentheses.
 * EXAMPLE:
 * input: 3 (e.g., 3 pairs of parentheses)
 * output: ()()(), ()(()), (())(), ((()))
 */

void printParatheses(unsigned num, std::string *existing = NULL) {
  std::string *temp;
  if (existing != NULL)
    temp = existing;
  else
    temp = new std::string();
  
  if (num == 0) {
    std::cout << *temp << ", ";
  } else {
    unsigned left = 0;
    for (int i = num - 1; i >= 0; --i) {
      left++;
      for (unsigned j = 0; j < left; ++j)
        *temp += "(";
      for (unsigned j = 0; j < left; ++j)
        *temp += ")";        
      printParatheses(i, temp);
      
      *temp = temp->substr(0, temp->size() - 2 * left);
    }
  }
}

int main() {
  unsigned num;
  std::cout << "Enter the pairs of paratheses you want:" << std::endl;
  std::cin >> num;
  
  printParatheses(num);
  std::cout << std::endl;
  
  return 0;
}