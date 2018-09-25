#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime> 
#include "Neuron.h"
#include "Net.h"

using namespace std;

double calcError(vector<vector<double>> & sigmoidData, vector<vector<double>> & outputData);

int main()
{
	srand((unsigned)time(0));

	//Where to get data
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
	cout << "Please enter how many output nodes you want: ";
	cin >> outputNode;

	double threshold;
	cout << "Please enter your threshold: ";
	cin >> threshold;

	vector<Neuron>outputNodeVec;

	for (int i = 0; i < outputNode; i++)
	{
		Neuron temp;
		outputNodeVec.push_back(temp);
	}

	//Create network with random weights
	Net myNet(inputNodeVec, hiddenNodeVec, outputNodeVec);

	double currentError = 100.00;


	//Vectors to hold inputs and desired outputs from the data file
	vector<vector<double>> inputData;
	vector<vector<double>> outputData;
	vector<vector<double>> sigmoidData;

	//Keeps tracks of how many tests
	int numDataSet = 0;

	//Gets all the inputs and Outputs from the file
	//Works only for 2 input 1 output right now
	while (!testData.eof())
	{
		cout << "Data set: " << numDataSet << endl;

		string inputs;
		getline(testData, inputs);

		inputs.erase(0, 7);
		cout << "Inputs: " << inputs << endl;
		
		string firstInput = inputs.substr(0, 1);
		string secondInput = inputs.substr(4, 5);

		int firstInputVal = stoi(firstInput);
		int secondInputVal = stoi(secondInput);

		//Saves 2 inputs
		vector<double> tempInput;
		tempInput.push_back((double)firstInputVal);
		tempInput.push_back((double)secondInputVal);
		inputData.push_back(tempInput);

		string output;
		getline(testData, output);
		
		output.erase(0, 8);

		int targetValue = stoi(output);
		
		//Saves 1 output
		vector <double> tempOutput;
		tempOutput.push_back((double)targetValue);
		outputData.push_back(tempOutput);

		cout << "Outputs: " << output << endl;

		numDataSet++;
	}

	testData.close();

	int numTests = 0;

	while (currentError > threshold)
	{
		numTests++;

		cout << "Test number: " << numTests << endl;
		sigmoidData.clear();

		//For each data set
		for (int i = 0; i < numDataSet; i++)
		{
			//Initializes the inputs
			myNet.initializeInput(inputData[i][0], inputData[i][1]);

			//gets the sigmoid(w * inputs)
			vector<double> tempSig;
			tempSig.push_back(myNet.sumWeightsAndValues());
			sigmoidData.push_back(tempSig);
		}

		//Calcs the current error
		currentError = calcError(sigmoidData, outputData);
		cout << "First test guess " << sigmoidData[0][0] << " should be " << outputData[0][0] << endl;
		cout << "Second test guess " << sigmoidData[1][0] << " should be " << outputData[1][0] << endl;
		cout << "Current Error: " << currentError << endl;

		//If error too large backpropogate and then go through again
		if (currentError > threshold)
		{
			myNet.backProp(sigmoidData, outputData, inputData);
		}
	}

	//Maybe test it now

	cin.get();
	cout << "Please hit enter to continue" << endl;
	cin.ignore();
	return 0;
}

double calcError(vector<vector<double>> & sigmoidData, vector<vector<double>> & outputData)
{
	double runningDifference = 0;
	for (unsigned int i = 0; i < sigmoidData.size(); i++)
	{
		double tempDifference = sigmoidData[i][0] - outputData[i][0];
		runningDifference += pow(tempDifference, 2);
	}

	runningDifference = runningDifference * (1.00/sigmoidData.size());

	return runningDifference;
}