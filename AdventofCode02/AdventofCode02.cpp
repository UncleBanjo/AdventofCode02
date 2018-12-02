// AdventofCode02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>

void readBoxID(std::string boxID, int param[]);
void fillVector(std::vector<std::string>& param, std::string line);
void compareBoxID(const std::vector<std::string>& param, std::vector<std::string>& correctIDs);
int compareChars(std::string str1, std::string str2);
void printVector(std::vector<std::string>& param);
void aocPart1();
void aocPart2();

int main()
{
	aocPart1();

	aocPart2();

	std::getchar();
}

void aocPart1()
{
	int entryArr[2];
	std::ifstream readFile;
	std::string readLine;
	readFile.open("boxID.txt");
	entryArr[0] = 0;
	entryArr[1] = 0;
	while (std::getline(readFile, readLine))
	{
		readBoxID(readLine, entryArr);
	}
	std::cout << "Total occuring 2: " << entryArr[0] << '\n';
	std::cout << "Total occuring 3: " << entryArr[1] << '\n';
	std::cout << "Answer: " << entryArr[0] << " * " << entryArr[1] << " = " << entryArr[0] * entryArr[1] << '\n';
}

void aocPart2()
{
	std::ifstream readFile;
	std::string readLine;

	std::vector<std::string> boxIDList;
	std::vector<std::string> correctBoxIDs;

	readFile.open("boxID.txt");

	while (std::getline(readFile, readLine))
	{
		fillVector(boxIDList, readLine);
	}

	compareBoxID(boxIDList, correctBoxIDs);

	std::cout << "Correct BoxIDs:" << '\n';

	printVector(correctBoxIDs);
	
}

void readBoxID(std::string boxID, int param[])
{
	bool foundExactlyTwo = false, foundExactlyThree = false;
	int counter = 1;
	for (int i = 0; i < boxID.length(); i++)
	{
		if (i == boxID.length())
			break;

		for (int j = i+1; j < boxID.length(); j++)
		{
			if (boxID[i] == boxID[j])
			{
				counter++;
			}
		}

		if (counter == 2)
			foundExactlyTwo = true;

		if (counter == 3)
			foundExactlyThree = true;

		else
			counter = 1;

		if (foundExactlyTwo && foundExactlyThree)
			break;
	}
	if (foundExactlyTwo)
	{
		param[0]++;
		std::cout << "I added 2 occuring!" << '\n';
	}

	if (foundExactlyThree)
	{
		param[1]++;
		std::cout << "I added 3 occuring!" << '\n';
	}
}

void compareBoxID(const std::vector<std::string>& paramVec, std::vector<std::string>& correctIDs)
{
	for (int i = 0; i < paramVec.size(); i++)
	{
		if (i == paramVec.size()-1)
			break;

		for (int j = i + 1; j < paramVec.size(); j++)
		{
			std::cout << "Comparing: " << paramVec[i] << " with " << paramVec[j] << '\n';
			if (compareChars(paramVec[i], paramVec[j]) == 1)
			{
				std::cout << "Found diff 1!" << '\n';
				correctIDs.push_back(paramVec[i]);
				correctIDs.push_back(paramVec[j]);
			}
		}
	}
}

int compareChars(std::string str1, std::string str2)
{
	int diff = 0;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
			diff++;
	}
	return diff;
}

void fillVector(std::vector<std::string>& param, std::string line)
{
	param.push_back(line);
}

void printVector(std::vector<std::string>& param)
{
	for (std::string correctID : param)
	{
		std::cout << correctID << '\n';
	}
}
