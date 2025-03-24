#include <iostream>  
#include <stdlib.h>  
using namespace std;  
   
int main()  
{  
     // variable declaration
  int var_len = 10;
     
    // pointer variable declaration
  int *ptr;
   
  // allocating memory to the pointer variable using malloc()
  ptr = (int*) malloc(sizeof(int)*var_len);    
  for(int i=0;i<var_len;i++)  
  {  
      cout << "Enter a number : " << endl;  
      cin >> *(ptr+i);  
  }  
  cout << "Entered elements are : " << endl;  
   for(int i=0;i<var_len;i++)  
  {  
     cout << *(ptr+i) << endl;  
  }  
free(ptr);  
    return 0;  
}