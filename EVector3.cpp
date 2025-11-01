#include "EVector3.h"
#include <cmath>

float EVector3::squareMagnitude() const
{
    return x * x + y * y + z * z;
}

float EVector3::magnitude() const
{
    return std::sqrt(squareMagnitude());
}

EVector3 operator-(const EVector3& v, const EVector3& u)
{
    return EVector3(v.x - u.x, v.y - u.y, v.z - u.z);
}

std::ostream& operator<<(std::ostream& os, const EVector3& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}
