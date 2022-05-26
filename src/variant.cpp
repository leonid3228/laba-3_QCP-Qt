#include "variant.h"
#include "array"

Variant::Variant()
{
    zz=1;
Sin::addFourthSlider();
//Sin::addFiveSlider();
y1=0;


}
void Variant::graphVariant()
{

    y = std::sqrt(y1);

    y1=y1+(1.3-freq->value()*0.1)*amplitude->value()*0.1;
    if(y>=amplitude->value()*0.8+2){
        y=0;
        y1=0;}

    }

bool Variant::errorState()
{

      if((y>line->value())){
          label4->setText("OШИБКА");
          return true;
          }

      if((y<lineMin->value())){
          label4->setText("OШИБКА");
          return true;
          }
       label4->setText("НЕТ ОШИБКИ");

      return false;

}

double Variant::getDelay() const
{

    return variantSlider->value()*1;

}





