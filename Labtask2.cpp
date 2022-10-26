#include <iostream>
using namespace std;
int main()
{
   int randArray[10];
   for(int i=0; i<10; i++)
   {
        randArray[i]=rand()%100;
   }
    
   cout<<"\nElements of the array::"<<endl;
  
   for(int i=0; i<10; i++)
   {
        cout << randArray[i]<<endl;
   }
      
   return 0;
}