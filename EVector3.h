#ifndef EVECTOR3_H
#define EVECTOR3_H

#include <iostream>

/// <summary>
/// Simple 3D Vector implementation.
/// </summary>
class EVector3
{
public:
	float x;
	float y;
	float z;

	EVector3(float xCoord = 0.0f, float yCoord = 0.0f, float zCoord = 0.0f) : x(xCoord), y(yCoord), z(zCoord) {}

	/// <summary>
	/// Returns the squared length of the vector.
	/// </summary>
	/// <returns>Squared length of the vector.</returns>
	float squareMagnitude() const;

	/// <summary>
	/// Returns the length of the vector.
	/// </summary>
	/// <returns>Squared length.</returns>
	float magnitude() const;
};

EVector3 operator-(const EVector3& v, const EVector3& u);
std::ostream& operator<<(std::ostream& os, const EVector3& v);

#endif