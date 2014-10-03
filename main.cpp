#include <iostream>
#include <string>
#include <sstream>
#include "tree.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

void main()
{
	Tree<int> mytree, mytree2;

	srand(time(NULL));
	int random;
	int n;
	cout << "Enter insertion : ";
	cin >> n;
	mytree.data = new int[n];

	for (int i = 0; i < n; i++)
	{
		random = rand() % 100 + 1;
		cout << random << " ";
		mytree.insert(random);
	}

	
	
	cout << "--------->Old height : " << mytree.Height() << "  (Not balance)" << endl;
	mytree.inorder();
	for (int i = 0; i < n; i++)
	{
		cout << mytree.data[i] << " ";
	}
	cout << "--------->Balance";
	cout << endl;
	
	mytree2.balance(mytree.data, 0, n-1);
	cout << "--------->New height : " << mytree2.Height() <<"  (Balance)"<< endl;
	cout << endl;
	

	
}
