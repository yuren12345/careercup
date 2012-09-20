/**
 * Write code to reverse a C-Style String  (C-String means that “abcd” is
 * represented as five characters, including the null character )
 */


#include <iostream>
#include <cstring>

void reverseStr(char *a) {
  unsigned len = strlen(a);
  
  if (len > 1) {
    unsigned mid = len / 2;
    for (int i = 0; i < mid; ++i) {
      char temp = a[i];
      a[i] = a[len - 1 - i];
      a[len - 1 - i] = temp;
    }
  }
}


int main(void) {
  std::cout << "Input the string: " << std::endl;

  std::string temp;
  std::cin >> temp;
  
  char *ctemp = new char[temp.size() + 1];
  strcpy(ctemp, temp.c_str());
  reverseStr(ctemp);
  
  std::cout << "Reversed string is: " << std::endl;
  printf("%s\n", ctemp);
  
  delete ctemp;
  return 0;
}
