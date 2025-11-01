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


int main()
{
	const auto start{ std::chrono::steady_clock::now() };
	std::srand(std::time({}));
	const int totalPoints = std::rand() % 1001;
	std::cout << "Total Points: " << totalPoints << std::endl;

	std::vector<EVector3> points;

	for (int i = 0; i < totalPoints; i++)
		points.push_back(EVector3((float)std::rand(), (float)std::rand(), (float)std::rand()));

	EVector3 v{ 1.0f, 2.0f, 4.0f };
	EVector3 u{ 5.0f, 6.0f, 7.0f };

	EVector3 result = v - u;
	float distance = result.magnitude();

	std::cout << "Distance between: v" << v << " and u" << u << ": " << distance << std::endl;


	/*std::vector<float> squareDistances;

	for (int i = 0; i < totalPoints; i++)
	{
		for (int j = 0; j < i; j++)
		{
			squareDistances.push_back((points[i] - points[j]).squareMagnitude());
		}

		for (int j = i + 1; j < totalPoints; j++)
		{
			squareDistances.push_back((points[i] - points[j]).squareMagnitude());
		}
	}

	std::sort(squareDistances.begin(), squareDistances.end());
	for (int i = 0; i < 10; i++)
		std::cout << std::sqrt(squareDistances[i]) << std::endl;*/

	const auto finish{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsedSeconds{ finish - start };
	std::cout << "Elapsed Time: " << elapsedSeconds.count() << std::endl;

	return 0;
}

