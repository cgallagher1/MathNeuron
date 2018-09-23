#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime> 
#include "Neuron.h"
#include "Net.h"

using namespace std;

int main()
{

	srand((unsigned)time(0));

	ifstream testData;
	testData.open("C:/Users/chuck_000/Documents/Math Thesis/TestData.txt");

	int inputNodes;
	cout << "Please enter how many input nodes you want: ";
	cin >> inputNodes;

	vector<Neuron>inputNodeVec;

	for (int i = 0; i < inputNodes; i++)
	{
		Neuron temp;
		inputNodeVec.push_back(temp);
	}

	vector<Neuron>hiddenNodeVec;

	int outputNode;
	cout << "PLease enter how many output nodes you want: ";
	cin >> outputNode;

	vector<Neuron>outputNodeVec;

	for (int i = 0; i < outputNode; i++)
	{
		Neuron temp;
		outputNodeVec.push_back(temp);
	}

	int numTests = 0;

	Net myNet(inputNodeVec, hiddenNodeVec, outputNodeVec);

	while (!testData.eof())
	{
		numTests++;
		cout << "Test: " << numTests << endl;

		string inputs;
		getline(testData, inputs);

		inputs.erase(0, 7);
		cout << "Inputs: " << inputs << endl;
		
		string firstInput = inputs.substr(1, 1);
		string secondInput = inputs.substr(5, 5);

		int firstInputVal = stoi(firstInput);
		int secondInputVal = stoi(secondInput);

		myNet.initializeInput(firstInputVal, secondInputVal);
		myNet.sumWeightsAndValues();

		string output;
		getline(testData, output);
		
		string correctValue = output.substr(1, 1);
		int targetValue = stoi(correctValue);

		output.erase(0, 8);
		cout << "Outputs: " << output << endl;
	}

	cin.get();
	return 0;
}