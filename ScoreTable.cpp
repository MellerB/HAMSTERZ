#include "ScoreTable.h"


void swap(Record *xp, Record *yp)
{
	Record temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubble_sort(Record arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (arr[j].points < arr[j + 1].points)
				swap(&arr[j], &arr[j + 1]);
}

void ScoreTable :: read()
{
	ifstream file(SCORETABLE_FILE);

	for (int i = 0; i < NUMRECORDS; i++)
	{
		file >> table[i].name;
		file >> table[i].points;
	}
	sort();
	file.close();
}

void ScoreTable :: sort()
{
	bubble_sort(table, NUMRECORDS);
}

int ScoreTable:: lowest_score()
{
	return table[NUMRECORDS - 1].points;
}

void ScoreTable:: push_record(string name, int score)
{
	table[NUMRECORDS - 1].name = name;
	table[NUMRECORDS - 1].points = score;

	sort();
	ofstream file(SCORETABLE_FILE);
	for (int i = 0; i < NUMRECORDS; i++)
	{
		file << table[i].name << ' ' << table[i].points << endl;
	}
	file.close();
}

void ScoreTable:: print()
{
	for (int i = 0; i < NUMRECORDS; i++)
	{
		cout << table[i].name << " " << table[i].points << endl;
	}
}