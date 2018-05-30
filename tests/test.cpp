#include <iostream>
#include <string>
#include "battleship.hpp"
#include <stdio.h>

bool negative_test()
{
  std::string str1[] = {"0", "a", "*", "+", "dfshgh", "15"};
  for (int i = 0; i< 6; ++ i){
    if(!valid_input(str1[i])) {
      std::cout << "The negative test passed with no errors. " << std::endl;
      return true;
    } else {
      std::cout << "The negative test passed with  errors. " << std::endl;
      return false;
    }
  }
}
bool positive_test()
{
  std::string str2[] = {"1", "10", "3", "7"};
  for (int i = 0; i < 6; ++ i){
    if(valid_input(str2[i])) {
      std::cout << "The positive test passed with no errors. " << std::endl;
      return true;
    } else {
      std::cout << "The positive test passed with no errors. " << std::endl;
      return false;
    }
  }
}
void write_test_results()
{
  FILE * myFile;
  myFile = fopen ("/home/student/Documents/Battleship/test_result/tests_result.txt","w");
  if (myFile != NULL)
  {
    if(negative_test()) {
      fputs ("valid_input() negative_test pass\n",myFile);
    } else {
      fputs ("valid_input() negative_test fail\n",myFile);
    }
  if(positive_test()) {
      fputs ("valid_input() positive_test pass\n",myFile);
    } else {
      fputs ("valid_input() positive_test fail\n",myFile);
    }
    fclose (myFile);
  }
}

int main()
{
 
  write_test_results();

  return 0;
}


