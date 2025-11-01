#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <array>
#include <float.h>
#include <algorithm>
#include <cmath>
#include "EVector3.h"

void algorithmSortWithSquareMag(int tPoints);
void algorithmSortWithMag(int tPoints);

int main()
{
	const auto start{ std::chrono::steady_clock::now() };
	std::srand(std::time({}));
	//const int totalPoints = std::rand() % 1001;
	const int totalPoints = 1000;
	std::cout << "Total Points: " << totalPoints << std::endl;
	//algorithmSortWithSquareMag(totalPoints);
	//algorithmSortWithMag(totalPoints);

	const auto finish{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsedSeconds{ finish - start };
	std::cout << "Elapsed Time: " << elapsedSeconds.count() << std::endl;

	return 0;
}

void algorithmSortWithSquareMag(int tPoints)
{
	std::vector<EVector3> points;

	for (int i = 0; i < tPoints; i++)
		points.push_back(EVector3((float)std::rand(), (float)std::rand(), (float)std::rand()));

	std::vector<float> squareDistances;

	for (int i = 0; i < tPoints; i++)
	{
		for (int j = 0; j < i; j++)
		{
			squareDistances.push_back((points[i] - points[j]).squareMagnitude());
		}

		for (int j = i + 1; j < tPoints; j++)
		{
			squareDistances.push_back((points[i] - points[j]).squareMagnitude());
		}
	}

	std::sort(squareDistances.begin(), squareDistances.end());
	for (int i = 0; i < 10; i++)
		std::cout << std::sqrt(squareDistances.at(i)) << std::endl;
}

void algorithmSortWithMag(int tPoints)
{
	std::vector<EVector3> points;

	for (int i = 0; i < tPoints; i++)
		points.push_back(EVector3((float)std::rand(), (float)std::rand(), (float)std::rand()));

	std::vector<float> distances;

	for (int i = 0; i < tPoints; i++)
	{
		for (int j = 0; j < i; j++)
		{
			distances.push_back((points[i] - points[j]).squareMagnitude());
		}

		for (int j = i + 1; j < tPoints; j++)
		{
			distances.push_back((points[i] - points[j]).squareMagnitude());
		}
	}

	std::sort(distances.begin(), distances.end());
	for (int i = 0; i < 10; i++)
		std::cout << distances.at(i) << std::endl;
}
