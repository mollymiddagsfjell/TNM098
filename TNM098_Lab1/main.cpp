/*
Lab 1 - Ad. visual data analysis
Written by: Molly Middagsfjell
1/4-2019 at Linköpings University
Course lead by Matthew Cooper
*/
//#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
//using namespace std;

int main() {

	//Variables
	std::string readLine;
	std::ifstream file;
	std::vector<std::string> dataFromFile;
	std::vector<std::string> randomNumberGenerator;
	std::vector<int> peopleData;
	std::vector<int> id;
	//For sol.1
	int head, tails;
	const int MAXFORHEAD = 110;
	const int MINFORTAIL = 90;

	//for Sol.2
	int numberOfHeads, seqHead, numberOfTails;
	numberOfHeads = seqHead = numberOfTails = 0;
	int repNumber = 7;


	file.open("CoinToss.txt");
	if (file.is_open())
	{
		while (getline(file, readLine))
		{
			dataFromFile.push_back(readLine);
		}
		file.close();
	}

	std::cout << "Length of data: " << dataFromFile.size() << std::endl;

	//for both



	// Deviation Function:

	for (int i = 0; i < dataFromFile.size(); i++)
	{
		head = 1;
		tails = 0;
		std::string data = dataFromFile[i];
		std::string::iterator start = data.begin();
		std::string::iterator done = data.end();

		for (start; start != done; start++)
		{
			if (*start == '1') head++;
			else tails++;
		}

		std::cout << (i + 1) << ". " << head << " / " << tails << std::endl;

		if (head > MAXFORHEAD || head < MINFORTAIL)
		{
			peopleData.push_back(i);
		}
		else
		{
			randomNumberGenerator.push_back(data);
			id.push_back(i);
		}

	}

	std::cout << "peopleData lenght:  " << peopleData.size() << std::endl;


	// Look at pattern

	for (int i = 0; i < randomNumberGenerator.size(); i++)
	{
		std::string dataSol2 = randomNumberGenerator[i];
		std::string::iterator startSol2 = dataSol2.begin();
		std::string::iterator doneSol2 = dataSol2.end();

		for (startSol2; startSol2 != doneSol2; startSol2++)
		{
			if (*startSol2 == '1')
			{
				if (numberOfTails >= repNumber)
				{
					peopleData.push_back(id[i]);
					break;
				}

				numberOfTails = 0;
				numberOfHeads++;
			}
			else if (*startSol2 == '0')
			{
				if (numberOfHeads >= repNumber)
				{
					peopleData.push_back(id[i]);
					break;
				}

				numberOfHeads = 0;
				numberOfTails++;
			}

			if (++startSol2 == randomNumberGenerator[i].end())
			{
				if (numberOfHeads >= repNumber || numberOfTails >= repNumber)
				{
					peopleData.push_back(id[i]);
				}
			}
		}
	}
	std::cout << "peopleData lenght after sol2:  " << peopleData.size() << std::endl;

	//Total data points that are human

	std::sort(peopleData.begin(), peopleData.end());
	std::cout << "total: ";

	for (int i = 0; i < peopleData.size() - 1; i++)
	{
		std::cout << peopleData[i] + 1 << ", " << std::endl;
	}

	std::cout << peopleData[peopleData.size() - 1];

	return 0;
}

