#include "Net.h"
#include "Connection.h"
#include "Neuron.h"
#include <iostream>
#include <vector>

using namespace std;

Net::Net(vector<Neuron>& inputNodeVec, vector<Neuron>& hiddenNodeVec, vector<Neuron>& outputNodeVec)
{
	if (hiddenNodeVec.size() == 0)
	{
		for (int i = 0; i < outputNodeVec.size(); i++)
		{
			for (int j = 0; j < inputNodeVec.size(); j++)
			{
				Connection temp;
				outputNodeVec[i].numConnections.push_back(temp);
			}
		}
	}
}


Net::~Net()
{
}