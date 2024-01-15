#pragma once
#include "figure.h"

class circle : public figure
{
    double d;
    double r;
public:
    circle()
    {

    }

    circle(double r)
    {
        this->r = r;
        d = 0;
    }

    void workCircle()
    {
        d = r * 2;
        area = 3.14 * pow(r, 2);
        perimeter = 3.14 * 2 * r;
    }

    double getD()
    {
        return d;
    }
};