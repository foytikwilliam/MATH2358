#include <iomanip>
#include <iostream>

using namespace std;

void collatz_path(int n)
{
	cout<< n << "==>";
	if(n==-2||n==-17||n==-5)
	{return;}
	if(n%2 == 0)
	{collatz_path(n/2);}
	else
	{collatz_path(3*n+1);}	
}

int main()
{
	for (int n = -1; n>-50; n--)
	{
		collatz_path(n);
		cout<<endl<<endl;
	}
	return 0;
}
