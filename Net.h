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
	void initializeInput(int first, int second);
	double sumWeightsAndValues();
	double sigmoid(double & sum);
	double derivate(double & sum);
	double error;
	void backProp(vector<vector<double>> & sigmoidData, vector<vector<double>> & outputData, vector<vector<double>> & inputData);
	vector<Neuron>outputVec;
	vector<Neuron>inputVec;
	vector<double>preActivationSum;
	double learningRate;
private:
	
};


