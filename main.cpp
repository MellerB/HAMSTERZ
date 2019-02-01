#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>

#include "Hamster.h"
#include "external.h"
#include "ScoreTable.h"
#include "content.h"

using namespace std;


int shoot(int index, Hamster tab[])
{
	if (index == -1)
		return 0;
	if (tab[index].punch())
		return 1;
	return -1;
}


int main()
{

	setFontSize(20);
	setWindowSize(114,12);
	
	ScoreTable scoretable;
	scoretable.read();
	int lifes = BEGIN_LIFES;
	int points = 0;
	hideCursor();
	const int h = 8;
	const int n = 6;
	srand(time(NULL));
	Hamster hamster[n];
	int menu_cursor = 0;

	
	
	int tmp = 0;
	int btn = 0;
	
one:
	setColor(11);
	system("cls");
	print_menu(menu_cursor);


		btn = _getch();
		

		
		while (btn != 13)
		{


			btn = _getch();
			system("cls");

			if (btn == 72)
				menu_cursor--;
			else if (btn == 80)
				menu_cursor++;
			menu_cursor = print_menu(menu_cursor);
		}
		system("cls");

		if (menu_cursor == 2)
			return 0;

		if (menu_cursor == 1)
			scoretable.print();

		if (menu_cursor == 0)
		{
			lifes = BEGIN_LIFES;
			points = NULL;
			print_base();
			Sleep(500);

			while (lifes > 0) {
				setColor(7);

				tmp = shoot(get_key_index(get_key()), &*hamster);
				get_key();										//czyœci bufor w razie gdy zosta³y naciœniête dwa przyciski na raz

				if (tmp == 1)
					points++;
				else if (tmp == -1)
					lifes--;

				goToXY(0, 0);
				for (int i = 0; i < LINES; i++)
				{

					for (int j = 0; j < n; j++)
					{
						hamster[j].print_line(i);
					}
					cout << endl;

				}

				for (int i = 0; i < n; i++)
				{
					lifes -= hamster[i].check_for_timeout();
					hamster[i].tidy();
					hamster[i].peek_a_boo();

				}
				cout << endl << endl << endl << endl << endl << endl;
				setColor(12);
				cout << "lifes: ";
				if (lifes < 10)
					cout << "0";
				cout << lifes << "/" << BEGIN_LIFES;
				setColor(10);
				cout << "    " << "points: " << points << endl;

				Sleep(DELAY);
			}

			system("cls");
			cout << endl << endl << endl << endl;
			if (points > scoretable.lowest_score())
			{
				setColor(10);
				
				cout << " CONGRATULATIONS! YOU ARE IN TOP 8!" << endl;
				cout << " Input Your Name: ";
				string name;
				getline(cin, name);
				scoretable.push_record(name, points);
			}
			else
			{
				setColor(12);
				cout << endl;
				cout << " YOU LOST! ;-;" << endl;
			}
		}

	

	system("pause");
	goto one;

	return 0;
}