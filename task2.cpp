#include<iostream>
#include<conio.h>
using namespace std;
int maximum(int a[])
{
	int  max = a[0];
	for(int i=1; i<10; i++)
	{
		if (max < a[i])
        {
            max = a[i];
        }
        else
        {
            continue;
        }
	}
	return max;
}     
int minimum(int a[])
{
	int min = a[0];
	for(int i=0; i<10; i++)
	{
		if(min > a[i])
        {
            min = a[i];
        }

        else
        {
            continue;
        }
	}
	return min;
}
int main()
{
	 int a[10],i,m;
	 cout<<"\nEnter 10 numbers :";
	 for(i=0;i<10;i++)
	 cin>>a[i];
	 m = maximum(a);   //function calling
	 cout<<"\nMaximum = "<<m;
	 m = minimum(a);
	 cout<<"\nMinimum = "<<m;
	 return 0;
	 
}