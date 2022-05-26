#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "sin.h"
#include "cmath"
class Triangle : public Sin
{
public:
    Triangle();
    bool  errorState() override;
private:
    void graphVariant() override;
    double y2;
};

#endif // TRIANGLE_H
