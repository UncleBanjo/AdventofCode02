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

int main()
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
	std::getchar();
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
