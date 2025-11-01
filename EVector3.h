#ifndef EVECTOR3_H
#define EVECTOR3_H

#include <iostream>

class EVector3
{
public:
	float x;
	float y;
	float z;

	EVector3(float xCoord = 0.0f, float yCoord = 0.0f, float zCoord = 0.0f) : x(xCoord), y(yCoord), z(zCoord) {}

	float squareMagnitude();
	float magnitude();
};

EVector3 operator-(const EVector3& v, const EVector3& u);
std::ostream& operator<<(std::ostream& os, const EVector3& v);

#endif