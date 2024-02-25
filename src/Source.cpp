#include "Levels.h"
#include "Foo.h"
#include "MapCreator.h"
#include <vector>

#include <iostream>
extern int pLives = 3;
using namespace std;
int main()
{
	HideCursor();
	bool isend = false;
	while (!isend)
	{
		SetCur(0, 0);
		cout << "Main Menu\n\n1 - Play\n2 - Map Creator\n3 - Exit\n";
		switch (getchar())
		{
		case '1':
			playMenu();
			break;
		case '2':
			system("cls");
			mapCreator();
			break;
		case '3':
			isend = true;
			break;
		default:
			cout << "There is no action\n";
		}
	}
	return 0;
}
