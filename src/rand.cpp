#include "rand.h"
#include "QPen"
#include <QColor>
#include <QDebug>

Randome::Randome()
{
    setWindowTitle("РАНДОМ");
    Sin::addFourthSlider();
    _x = (freq->value());
    zz=1;
}

void Randome::graphVariant()
{
    _x+=0.01;
    if(_x<=x){
        y = (qrand()%201-100)*(0.01*amplitude->value());
        _x = (freq->value())*0.1+x;}
}

bool Randome::errorState()
{
    label4->setStyleSheet(myStyles.labelNoErrorStyle);

    if(y>line->value()){
        state = states::ERR;
    }
    if(y>lineMin->value()&&state == states::ERR){
        state = states::NEEDLOW;
    }
    if(state == states::NEEDLOW&&y<lineMin->value()){
        state = states::OK;
    }

    if(state == states::ERR){
        label4->setText("OШИБКА");

        return true;
    }
    if(state == states::NEEDLOW){
        label4->setText("ОШИБКА");
        label4->setStyleSheet(myStyles.labelErrorStyle);
        return true;
    }
    if(state == states::OK){

        label4->setText("НЕТ ОШИБКИ");
        return false;
    }
}
