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
		for (unsigned int i = 0; i < outputVec.size(); i++)
		{
			for (unsigned int j = 0; j < inputVec.size(); j++)
			{
				Connection temp;
				outputVec[i].connections.push_back(temp);
				outputVec[i].connections[j].neuronIndex = j;
			}
		}
	}

	learningRate = .1;
}


Net::~Net()
{
}

void Net::initializeInput(int first, int second)
{
	inputVec[0].value = first;
	inputVec[1].value = second;
}

double Net::sumWeightsAndValues()
{
	double sum = 0;
	for (unsigned int i = 0; i < outputVec.size(); i++)
	{
		for (unsigned int j = 0; j < outputVec[i].connections.size(); j++)
		{
			sum += outputVec[i].connections[j].weightOld * inputVec[outputVec[i].connections[j].neuronIndex].value;
		}
		preActivationSum.push_back(sum);
		outputVec[i].value = sigmoid(sum);
	}

	return outputVec[0].value;
}

double Net::sigmoid(double & sum)
{
	double afterSigmoid = (1 / (1 + pow(e, (sum * -1))));
	return afterSigmoid;
}

double Net::derivate(double & sum)
{
	double afterDer = (pow(e, -sum)) / pow((1 + pow(e, -sum)), 2);
	return afterDer;
}

void Net::backProp(vector<vector<double>>& sigmoidData, vector<vector<double>>& outputData, vector<vector<double>> & inputData)
{
	for (int i = 0; i < outputVec.size(); i++)
	{
		for (int j = 0; j < outputVec[i].connections.size(); j++)
		{
			for (int k = 0; k < sigmoidData.size(); k++)
			{
				outputVec[i].connections[j].weightDelta += (sigmoidData[k][0] - outputData[k][0]) * derivate(preActivationSum[k]) * inputData[k][j];
			}
			outputVec[i].connections[j].weightOld = outputVec[i].connections[j].weightOld * learningRate * -1 + outputVec[i].connections[j].weightDelta;
		}
	}
}




