#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>
#include "EVector3.h"

/// <summary>
/// Generates the given number of random 3D points.
/// </summary>
/// <param name="tPoints">Number of points to generate.</param>
/// <returns>Vector containing 3D points.</returns>
std::vector<EVector3> generateRandomPoints(int tPoints);

/// <summary>
/// Calculates the square distance of all 3D point pairs in the given vector.
/// </summary>
/// <param name="points">Vector containing the 3D points.</param>
/// <returns>Vector containing the square distances of each 3D point pair.</returns>
std::vector<float> calculateSquareDistances(std::vector<EVector3>& points);

/// <summary>
/// Sorts a list of squared distances and prints the 10 shortest distances.
/// </summary>
/// <param name="sDistances">Squared distances.</param>
void printShortestDistances(std::vector<float>& sDistances);

/// <summary>
/// Returns a random float within the specified range.
/// </summary>
/// <param name="min">Min possible float value (inclusive).</param>
/// <param name="max">Max possible float value (inclusive).</param>
/// <returns></returns>
float randomFloat(float min, float max);

int main()
{
	const auto start{ std::chrono::steady_clock::now() };
	std::srand(std::time({}));

	const int totalPoints = std::rand() % 1001;
	std::cout << "Total Points: " << totalPoints << std::endl;

	std::vector<EVector3> points{ generateRandomPoints(totalPoints) };
	std::vector<float> squareDistances{ calculateSquareDistances(points) };
	printShortestDistances(squareDistances);

	const auto finish{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsedSeconds{ finish - start };
	std::cout << "Total Time Elapsed: " << elapsedSeconds.count() << std::endl;

	return 0;
}

std::vector<EVector3> generateRandomPoints(int tPoints)
{
	const auto start{ std::chrono::steady_clock::now() };
	std::vector<EVector3> points;

	for (int i = 0; i < tPoints; i++)
		points.push_back(EVector3(randomFloat(-1000.0f, 1000.0f), randomFloat(-1000.0f, 1000.0f), randomFloat(-1000.0f, 1000.0f)));

	const auto finish{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsedSeconds{ finish - start };
	std::cout << "Generate Random Points Time Elapsed: " << elapsedSeconds.count() << std::endl;
	return points;
}

std::vector<float> calculateSquareDistances(std::vector<EVector3>& points)
{
	const auto start{ std::chrono::steady_clock::now() };
	std::vector<float> squareDistances;

	for (int i = 0; i < points.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			squareDistances.push_back((points[i] - points[j]).squareMagnitude());
		}

		for (int j = i + 1; j < points.size(); j++)
		{
			squareDistances.push_back((points[i] - points[j]).squareMagnitude());
		}
	}

	const auto finish{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsedSeconds{ finish - start };
	std::cout << "Calculate Square Distances Time Elapsed: " << elapsedSeconds.count() << std::endl;

	return squareDistances;
}

void printShortestDistances(std::vector<float>& sDistances)
{
	const auto start{ std::chrono::steady_clock::now() };

	std::sort(sDistances.begin(), sDistances.end());

	for (int i = 0; i < 10; i++)
		std::cout << std::sqrt(sDistances.at(i)) << std::endl;

	const auto finish{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsedSeconds{ finish - start };
	std::cout << "Print Shortest Distances Time Elapsed: " << elapsedSeconds.count() << std::endl;
}

float randomFloat(float min, float max)
{
	return min + (max - min) * std::rand() / (RAND_MAX + 1.0);
}



