#include "Connection.h"
#include <iostream>


Connection::Connection()
{
	double r = ((double)rand() / (RAND_MAX));
	weight = r;
}

Connection::~Connection()
{
}