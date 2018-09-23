#include "Net.h"
#include "Connection.h"
#include "Neuron.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

const double e = 2.7182818284590452353602874713527; 

Net::Net(vector<Neuron>& inputNodeVec, vector<Neuron>& hiddenNodeVec, vector<Neuron>& outputNodeVec)
{
	outputVec = outputNodeVec;
	inputVec = inputNodeVec;
	if (hiddenNodeVec.size() == 0)
	{
		for (int i = 0; i < outputVec.size(); i++)
		{
			for (int j = 0; j < inputVec.size(); j++)
			{
				Connection temp;
				outputVec[i].connections.push_back(temp);
				outputVec[i].connections[j].neuronIndex = j;
			}
		}
	}
}


Net::~Net()
{
}

void Net::initializeInput(int first, int second)
{
	inputVec[0].value = first;
	inputVec[1].value = second;
}

void Net::sumWeightsAndValues()
{
	double sum = 0;
	for (int i = 0; i < outputVec.size(); i++)
	{
		for (int j = 0; j < outputVec[i].connections.size(); j++)
		{
			sum += outputVec[i].connections[j].weight * inputVec[outputVec[i].connections[j].neuronIndex].value;
		}
		outputVec[i].value = sigmoid(sum);
	}
}

double Net::sigmoid(double & sum)
{
	double afterSigmoid = (1 / (1 + pow(e, (sum * -1))));
	return afterSigmoid;
}
