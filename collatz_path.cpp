#include <iomanip>
#include <fstream>
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
	fstream fout;
	fout.open("collatz_numbers.txt");

	fout << "Starting Integer | length\n";
	fout << "-------------------------\n";
	
	for (int n = 1; n<10000; n++)
	{
		int length = -1;		
		collatz_path(n,length);
		if(length>200)
		{
			fout << left << setw(16) << n << " |  " << length;
			fout << endl;
		}
	}
	return 0;
}
