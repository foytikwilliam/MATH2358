#include <iomanip>
#include <iostream>

using namespace std;

void collatz_path(int n,int &length)
{
	length++;
	if(n==1)
	{return;}
	if(n%2 == 0)
	{collatz_path(n/2,length);}
	else
	{collatz_path(3*n+1,length);}	
}

int main()
{

	cout << "Starting Integer | length\n";
	cout << "-------------------------\n";
	
	for (int n = 1; n<31; n++)
	{
		int length = -1;		
		collatz_path(n,length);
		cout << left << setw(16) << n << " |  " << length;
		cout << endl;
	}
	return 0;
}
