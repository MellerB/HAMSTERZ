#include <iostream>
#include "CONSTANTS.h"
#include "GRAPHICS.h"

using namespace std;

struct Hamster {
	int status = HIDDEN;
	float prob = PROBABILITY;
	int timeout = HAMSTER_TIMEOUT;

	int get_status();
	void print_line(int);

	void _hit();
	void _up();
	void _hide();
	void _miss();

	void tidy();
	void peek_a_boo();
	bool check_for_timeout();
	bool punch();
};