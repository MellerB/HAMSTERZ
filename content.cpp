#include <conio.h>
#include "content.h"
#include "CONSTANTS.h"
#include "Hamster.h"
#include "external.h"



int get_key_index(char key)
{
	for (int i = 0; i < AMOUNT; i++)
	{
		if (KEYBINDING[i] == key)
			return i;
	}
	return -1;
}

char get_key()
{
	if (_kbhit())
		return _getch();
	return NULL;
}

void print_base()
{
	goToXY(0, LINES);

	setColor(6);
	for (int i = 0; i < BASE_LINES; i++)
	{

		for (int j = 0; j < AMOUNT; j++)
		{
			if (j % 2)
				setColor(8);
			else
				setColor(6);
			cout << base[i];
		}

		cout << endl;
	}
	setColor(2);
	for (int i = 0; i < GRASS_LINES; i++)
	{
		for (int j = 0; j < AMOUNT; j++)
		{
			cout << GRASS;
		}
		cout << endl;
	}
}

int print_menu(int c)
{
	int n = 3;
	c = c % n;
	if (c < 0)
		c = n - 1;

	cout << endl << endl;


	if (c == 0)
		cout << endl << "                                     > - - - - - - - - - PLAY - - - - - - - - - <";
	else
		cout << endl << "                                       - - - - - - - - - PLAY - - - - - - - - -";


	if (c == 1)
		cout << endl << endl << "                                     > - - - - - - - - - SCOREBOARD - - - - - - <";
	else
		cout << endl << endl << "                                       - - - - - - - - - SCOREBOARD - - - - - -";



	if (c == 2)
		cout << endl << endl << "                                     > - - - - - - - - - EXIT - - - - - - - - - <";
	else cout << endl << endl << "                                       - - - - - - - - - EXIT - - - - - - - - -";


	cout << endl;
	return c;
}