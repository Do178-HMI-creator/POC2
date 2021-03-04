#include "agtTypPoint.h"
#include <GL/glut.h>

agtTypPoint::agtTypPoint(float x_in, float y_in, float z_in)
{
    this->x = x_in;
    this->y = y_in;
    this->z = z_in;
}

agtTypPoint agtTypPoint::operator+=(agtTypPoint pnt)
{
    (*this).x += pnt.x;
    (*this).y += pnt.y;
    (*this).z += pnt.z;
    return (*this);
}

agtTypPoint agtTypPoint::operator+(agtTypPoint pnt)
{
    agtTypPoint temp;
    temp.x = (*this).x + pnt.x;
    temp.y = (*this).y + pnt.y;
    temp.z = (*this).z + pnt.z;
    return temp;
}

agtTypPoint agtTypPoint::operator+=(float num)
{
    (*this).x += num;
    (*this).y += num;
    (*this).z += num;
    return (*this);
}

agtTypPoint agtTypPoint::operator+(float num)
{
    agtTypPoint temp;
    temp.x = (*this).x + num;
    temp.y = (*this).y + num;
    temp.z = (*this).z + num;
    return temp;
}

agtTypPoint agtTypPoint::operator-=(agtTypPoint pnt)
{
    (*this).x -= pnt.x;
    (*this).y -= pnt.y;
    (*this).z -= pnt.z;
    return (*this);
}

agtTypPoint agtTypPoint::operator-(agtTypPoint pnt)
{
    agtTypPoint temp;
    temp.x = (*this).x - pnt.x;
    temp.y = (*this).y - pnt.y;
    temp.z = (*this).z - pnt.z;
    return temp;
}

agtTypPoint agtTypPoint::operator-=(float num)
{
    (*this).x -= num;
    (*this).y -= num;
    (*this).z -= num;
    return (*this);
}

agtTypPoint agtTypPoint::operator-(float num)
{
    agtTypPoint temp;
    temp.x = (*this).x - num;
    temp.y = (*this).y - num;
    temp.z = (*this).z - num;
    return temp;
}