#pragma once
#include <QLabel>
#include "sin.h"
#include <QSlider>
#include <qcustomplot.h>
#include <QString>
class Randome : public Sin
{
public:
    enum class states{
        OK,
        ERR,
        NEEDLOW
    };
    states state{states::OK};

    Randome();
    QSlider *minSlider;
    QLabel *minLabel;
    bool errorState() override;
   void graphVariant() override;
double _x;int _z {0};

};


