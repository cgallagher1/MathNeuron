#pragma once
#include "Connection.h"
#include <vector>

using namespace std;

class Neuron
{
public:
	Neuron();
	~Neuron();
	double value;
	vector<Connection> connections;
private:

};

