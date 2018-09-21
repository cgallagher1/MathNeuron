#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Net.h"
#include "Connection.h"
#include "Neuron.h"

using namespace std;

class Net
{
public:
	Net(vector<Neuron> & inputNodeVec, vector<Neuron> & hiddenNodeVec, vector<Neuron> & outputNodeVec);
	~Net();

private:
	
};

