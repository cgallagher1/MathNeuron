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
	testData.open("C:/Users/chuck/Documents/Math Thesis/testingData.txt");

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

	Net myNet(inputNodeVec,hiddenNodeVec,outputNodeVec);

	int numTests = 0;

	while (!testData.eof())
	{
		numTests++;
		cout << "Test: " << numTests << endl;

		string inputs;
		getline(testData, inputs);

		inputs.erase(0, 7);
		cout << "Inputs: " << inputs << endl;

		string output;
		getline(testData, output);
		
		output.erase(0, 8);
		cout << "Outputs: " << output << endl;
	}

	cin.get();
	return 0;
}