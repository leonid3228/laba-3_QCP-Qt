#include "triangle.h"
#include "QDebug"
#include "QSlider"

Triangle::Triangle()
{
   // window->setWindowTitle("Треугольник");

       setWindowTitle("Треугольник");
y2 = 0;
::Sin::line->setValue(-5);
}

void Triangle::graphVariant()
{

    if(y2==0){
        y2 = 0.05*freq->value();}
    if((y2+y)>=1*amplitude->value())
        y2 = -0.05*freq->value();
    if((y2+y)<=-1*amplitude->value())
        y2 = 0.05*freq->value();
    y =(y2+y);

}

bool Triangle::errorState()
{

      if(!(y>line->value())){
          label4->setText("OШИБКА");
          return true;
          }
       label4->setText("НЕТ ОШИБКИ");

      return false;

}
