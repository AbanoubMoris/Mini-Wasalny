#include <iostream>
#include "stac.h"
using namespace std;
void InOrder(int numofelement)
{
	stac s;
	int  num;
	int *b = new int[numofelement];
	cout << "Enter the element:\n";
	for (int i = 0; i < numofelement; i++)
	{
		cin >> num;
	    s.push(num);
		b[i]=s.pop();
	}
	cout << "\n the output:   ";
	for (int i = 0; i < numofelement; i++)
		cout << b[i];
}
int main()
{
	cout << "Enter numofelement :" ;
	int n ;
	cin >> n;
	InOrder(n);
	system("pause");
	return 0;
}