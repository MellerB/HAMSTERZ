#include "Hamster.h"

int Hamster :: get_status()
{
	return status;
}

void Hamster :: print_line(int line)
{
	if (line < 0 || line >= LINES)
	{
		cout << "    ERR0    ";
	}

	else
	{
		if (status == HIDDEN)
		{
			cout << hidden[line];
		}
		if (status == SHOWN)
		{
			cout << shown[line];
		}
		if (status == DEAD)
		{
			cout << dead[line];
		}
		if (status == MISS)
		{
			cout << miss[line];
		}
	}
}

void Hamster :: _hit()
{
	status = DEAD;
}

void Hamster:: _up()
{
	status = SHOWN;
}

void Hamster:: _hide()
{
	status = HIDDEN;
}

void Hamster:: _miss()
{
	status = MISS;
}

void Hamster:: tidy()
{
	if (status == DEAD || status ==  MISS)
	{
		_hide();
	}
}

void Hamster:: peek_a_boo()
{
	if (float(rand()) / RAND_MAX < prob && status == HIDDEN)
	{
		_up();
	}
}

bool Hamster:: check_for_timeout()
{
	if(status==SHOWN)
	timeout--;
	if (timeout <= 0)
	{
		timeout = HAMSTER_TIMEOUT;
		_hide();
		return 1;
	}
	return 0;
}

bool Hamster::punch()
{
	if (status == SHOWN)
	{
		_hit();
		return 1;
	}
		_miss();
		return 0;
}