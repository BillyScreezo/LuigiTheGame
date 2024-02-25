#include <iostream>
#include <conio.h>
#include <vector>

#include "Foo.h"
#include "MapCreator.h"

extern int pLives = 3;

int main()
{
	HideCursor();
	bool isend = false;
	while (!isend)
	{
		SetCur(0, 0);
		std::cout << "Main Menu\n\n1 - Play\n2 - Map Creator\n3 - Exit\n";
		switch (_getch())
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
			std::cout << "There is no action\n";
			system("pause");
			system("cls");
		}
	}
	return 0;
}