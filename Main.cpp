#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cmath>
#include "EVector3.h"

// Program configuration
const int MAX_POINTS = 1000;
const float MIN_PT_RANGE = -1000.0f;
const float MAX_PT_RANGE = 1000.0f;

// Function performance results
std::chrono::duration<double> generatePointsTimeElapsed;
std::chrono::duration<double> calculateSqrDistTimeElapsed;
std::chrono::duration<double> printDistancesTimeElapsed;

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
	// Start recording time
	const auto start{ std::chrono::steady_clock::now() };

	// Determine number of points to generate
	std::srand(std::time({}));
	const int totalPoints = std::rand() % (MAX_POINTS + 1);
	std::cout << "Total Points: " << totalPoints << "\n" << std::endl;

	// Generate points, calculate square distances, and print 10 shortest distances
	std::vector<EVector3> points{ generateRandomPoints(totalPoints) };
	std::vector<float> squareDistances{ calculateSquareDistances(points) };
	printShortestDistances(squareDistances);

	// Stop recording time and print time elapsed
	const auto finish{ std::chrono::steady_clock::now() };
	const std::chrono::duration<double> elapsedSeconds{ finish - start };

	std::cout << "\nGenerate Random Points Time Elapsed: " << generatePointsTimeElapsed.count() << std::endl;
	std::cout << "Calculate Square Distances Time Elapsed: " << calculateSqrDistTimeElapsed.count() << std::endl;
	std::cout << "Print Shortest Distances Time Elapsed: " << printDistancesTimeElapsed.count() << std::endl;

	std::cout << "\nTotal Time Elapsed: " << elapsedSeconds.count() << std::endl;

	return 0;
}

std::vector<EVector3> generateRandomPoints(int tPoints)
{
	const auto start{ std::chrono::steady_clock::now() };

	// Create random 3D points
	std::vector<EVector3> points;

	for (int i = 0; i < tPoints; i++)
		points.push_back(EVector3(
			randomFloat(MIN_PT_RANGE, MAX_PT_RANGE), 
			randomFloat(MIN_PT_RANGE, MAX_PT_RANGE),
			randomFloat(MIN_PT_RANGE, MAX_PT_RANGE)
		));

	const auto finish{ std::chrono::steady_clock::now() };
	generatePointsTimeElapsed = finish - start;
	
	return points;
}

std::vector<float> calculateSquareDistances(std::vector<EVector3>& points)
{
	const auto start{ std::chrono::steady_clock::now() };

	std::vector<float> squareDistances;
	
	// For each 3D point, evaluate the square distance for every point in front of it
	for (int i = 0; i < points.size(); i++)
	{
		for (int j = i + 1; j < points.size(); j++)
		{
			squareDistances.push_back((points.at(i) - points.at(j)).squareMagnitude());
		}
	}

	const auto finish{ std::chrono::steady_clock::now() };
	calculateSqrDistTimeElapsed = finish - start;

	return squareDistances;
}

void printShortestDistances(std::vector<float>& sDistances)
{
	const auto start{ std::chrono::steady_clock::now() };

	std::sort(sDistances.begin(), sDistances.end());

	for (int i = 0; i < 10; i++)
		std::cout << std::sqrt(sDistances.at(i)) << std::endl;

	const auto finish{ std::chrono::steady_clock::now() };
	printDistancesTimeElapsed = finish - start;
}

float randomFloat(float min, float max)
{
	return min + (max - min) * (float) (std::rand() / (RAND_MAX + 1.0));
}



