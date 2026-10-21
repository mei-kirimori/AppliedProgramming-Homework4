#include <iostream>
using namespace std;

static int mult(int a, int b)
{
    return a * b;
}

int main()
{
	int a, b;
	cout << "Please enter a value for a";
	cin >> a;
	cout << "Please enter a value for b";
	cin >> b;
	cout << "a * b = " << mult(a, b) << endl;
}