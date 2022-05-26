#pragma once
#include "sin.h"
#include "queue"
#include "QTimer"


class Variant:public Sin
{

public:
    Variant();
    bool  errorState() override;
private:
    void graphVariant() override;
    double y1;
    double getDelay() const;
};
