/**
 * Given a sorted array of strings which interspersed with empty strings, 
 * write a method to fidn the location of a given string.
 * Example: find "ball" in 
 * ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""] 
 * will return 4
 * Example: find "ballcar" in 
 * ["at", "", "", "", "", "ball", "car", "", "", "dad", "", ""] will return -1
 */


#include <iostream>
#include <string>

int find(std::string &s, std::string array[], unsigned size) {  
  unsigned left = 0;
  unsigned right = size;
  
  while (left < right) {
    int mid = (right + left) / 2;
    
    while (array[mid] == "" && mid < right)
      mid++;
    
    if (mid != right) {
      if (array[mid] == s)
        return mid;
      else if (array[mid] < s)
        left = mid + 1;
      else
        right = mid;
    }
  
  }
  
  return -1;
}

int main(void) {
  std::string example1[] = {"at", "", "", "", "ball", "", "", "car", "", "",
    "dad", "", ""};
  
  std::string example2[] = {"at", "", "", "", "", "ball", "car", "", "",
    "dad", "", ""};
  
  std::string temp("ball");
  std::cout << "result of finding \"ball\" in example 1: " <<
  find(temp, example1, 13) << std::endl;
  
  temp = "ballcar";
  std::cout << "result of finding \"ballcar\" in example 2: " <<
  find(temp, example2, 12) << std::endl;
  
  return 0;
}