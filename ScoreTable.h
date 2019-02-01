#include <iostream>
#include <fstream>
#include "CONSTANTS.h"

using namespace std;


struct Record
{
	string name{};
	int points{};
};

void swap(Record*, Record*);

void bubble_sort(Record [], int);


struct ScoreTable
{
	Record table[NUMRECORDS];

	void read();
	void sort();
	int lowest_score();
	void push_record(string name, int score);
	void print();
};

