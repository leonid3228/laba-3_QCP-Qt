#include "sin.h"
#include "QSlider"
Sin::Sin(QWidget *parent)
    : QWidget{parent}
{
   // window = new QWidget();
    //window->setWindowTitle("СИНУСОИДА");
    setWindowTitle("СИНУСОИДА");
   // window->setStyleSheet("background-color: #4169E1");
    setStyleSheet("background-color: #4169E1");

    startButton = new QPushButton("Start");
    stopButton = new QPushButton("Stop");
    timer = new QTimer();

    startButton->setStyleSheet(myStyles.buttonStyle);
    stopButton->setStyleSheet(myStyles.buttonStyle2);

    labelG = new QLabel("АМПЛИТУДА");
    labelG->setStyleSheet(myStyles.labelStyle);
    labelG->setAlignment(Qt::AlignCenter);
    labelA = new QLabel("Макс. Граница");
    labelA->setStyleSheet(myStyles.labelStyle);
    labelT = new QLabel("ПЕРИОД");
    labelT->setStyleSheet(myStyles.labelStyle);
    label4 = new QLabel("все норм");
    label4->setStyleSheet(myStyles.labelStyle);
    label5 = new QLabel("ОШИБКА в графиках:");
    label5->setStyleSheet(myStyles.labelStyle);
    labelMin = new QLabel("Мин. Граница");
     labelMin->setStyleSheet(myStyles.labelStyle);
     labelVariant = new QLabel("Задержка");
      labelVariant->setStyleSheet(myStyles.labelStyle);



      amplitude = new QSlider(Qt::Vertical);
      amplitude->setMaximum(10);
      amplitude->setMinimum(1);
      amplitude->setValue(1);
      amplitude->setStyleSheet(myStyles.verticallSliderStyle);

      line = new QSlider(Qt::Vertical);
      line->setMaximum(10);
      line->setMinimum(-10);
      line->setValue(8);
      line->setStyleSheet(myStyles.verticallSliderStyle);

      freq  = new QSlider(Qt::Vertical);
      freq->setMaximum(10);
      freq->setMinimum(1);
      freq->setValue(1);
      freq->setStyleSheet(myStyles.verticallSliderStyle);

      axesWidth = new QSlider(Qt::Horizontal);
      axesWidth->setMaximum(10);
      axesWidth->setMinimum(1);
      axesWidth->setValue(1);
      axesWidth->setStyleSheet(myStyles.horizontalSliderStyle);

      customPlot = new QCustomPlot();
      customPlot->yAxis->setRange(-10, 10);
      customPlot->addGraph();
      customPlot->addGraph();
      customPlot->addGraph();

maxXPlot =axesWidth->value()*10;
drawErrorGraph();



      //Компоновка

    leftLayout = new QVBoxLayout();
    rightLayout = new QVBoxLayout();
    botLayout = new QGridLayout();
    topLayout = new QGridLayout();
    mainLayout = new QHBoxLayout();



topLayout->addWidget(line,1,0);
topLayout->addWidget(labelA,0,0);

topLayout->addWidget(amplitude,1,1);
topLayout->addWidget(labelG,0,1);

topLayout->addWidget(freq,1,2);
topLayout->addWidget(labelT,0,2);

botLayout->addWidget(startButton,0,0);
botLayout->addWidget(stopButton,0,1);
botLayout->addWidget(label5,1,0);
botLayout->addWidget(label4,1,1);

label4->setMinimumSize(80,100);
label5->setMinimumSize(80,100);
stopButton->setMinimumSize(75,75);
startButton->setMinimumSize(100,100);
rightLayout->addLayout(topLayout);
rightLayout->addLayout(botLayout);

      leftLayout->addWidget(customPlot,1);
      leftLayout->addWidget(axesWidth,2);

      mainLayout->addLayout(leftLayout);
      mainLayout->addLayout(rightLayout);


      lineMin = new QSlider(Qt::Vertical);
      lineMin->setMaximum(10);
      lineMin->setMinimum(-10);
      lineMin->setValue(-5);
      lineMin->setStyleSheet(myStyles.verticallSliderStyle);


      variantSlider = new QSlider(Qt::Vertical);
      variantSlider->setMaximum(10);
      variantSlider->setMinimum(0);
      variantSlider->setValue(0);
      variantSlider->setStyleSheet(myStyles.verticallSliderStyle);



/////////////////*Для визуальной части кастомплота*

errorPen.setWidth(5);
errorPen.setColor(Qt::red);
graphPen.setWidth(3);
graphPen.setColor(QColor(qrand()%255,qrand()%255,qrand()%255));

      customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
      customPlot->yAxis->setBasePen(QPen(Qt::black, 1));
      customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
      customPlot->yAxis->setTickPen(QPen(Qt::black, 1));
      customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
      customPlot->yAxis->setSubTickPen(QPen(Qt::black, 1));
     // customPlot->xAxis->setTickLabelColor(Qt::white);
      customPlot->yAxis->setTickLabelColor(Qt::black);
      customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
      customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
      customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
      customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
      customPlot->xAxis->grid()->setSubGridVisible(false);
      customPlot->yAxis->grid()->setSubGridVisible(false);




/////////////////*Для визуальной части кастомплота*

    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

    connect(startButton,(&QPushButton::clicked), [&](){ timer->start(10);});

    connect(stopButton,(&QPushButton::clicked), [&](){ timer->stop();});

    connect(line, SIGNAL(valueChanged(int)), this, SLOT(drawErrorGraph()));

    connect(axesWidth, SIGNAL(valueChanged(int)), this, SLOT(rescaleX()));

    connect(lineMin, SIGNAL(valueChanged(int)), this, SLOT(drawErrorGraph()));

    connect(variantSlider, SIGNAL(valueChanged(int)), this, SLOT(resizeVec()));



setLayout(mainLayout);
resize(900,500);
minXPlot=0;
maxXPlot=axesWidth->value()*10;
customPlot->xAxis->setRange(0, maxXPlot);
}




void Sin::slotTimerAlarm()
{

      if(x>=maxXPlot){

              minXPlot += 0.2;
              maxXPlot+= 0.2;
              customPlot->xAxis->setRange(minXPlot, maxXPlot);

              drawErrorGraph();

          }
x+=0.05;
    graphVariant();


     customPlot->graph(0)->addData(x,y);
     customPlot->graph(0)->setPen(graphPen);
     customPlot->replot();
     errorState();
     if(errorState()){
          label4->setStyleSheet(myStyles.labelErrorStyle); //обновлять LAbel
     }
     else{
         label4->setStyleSheet(myStyles.labelNoErrorStyle);
     }
}


void Sin::drawErrorGraph()
{
      customPlot->removeGraph(2);
      customPlot->addGraph();
      customPlot->graph()->addData(minXPlot-1,line->value());
      customPlot->graph()->addData(maxXPlot,line->value());
      customPlot->graph()->setPen(errorPen);
      customPlot->replot();

    if(zz ==1){
    customPlot->removeGraph(1);
    customPlot->addGraph();
    customPlot->graph()->addData(0,lineMin->value());
    customPlot->graph()->addData(maxXPlot,lineMin->value());
    customPlot->graph()->setPen(errorPen);
    customPlot->replot();}

}


void Sin::rescaleX()
{
    if(x>20){
  minXPlot = (x)-10;
  maxXPlot = (x)+axesWidth->value()*10;
  customPlot->xAxis->setRange(minXPlot, maxXPlot);
  drawErrorGraph();}

}

void Sin::resizeVec()
{

}

double Sin::getX() const
{
    return x;
}


double Sin::getY() const
{
    return y;
}


bool Sin::errorState()
{
  if(y>line->value()){
      label4->setText("OШИБКА");
      return true;
      }
  label4->setText("НЕТ ОШИБКИ");

  return false;
}


void Sin::graphVariant()
{
    y = sin(x*freq->value())*amplitude->value();
}

void Sin::graphVariant2()
{

}


void Sin::addFourthSlider()
{
     topLayout->addWidget(lineMin,1,3);
     topLayout->addWidget(labelMin,0,3);
}
void Sin::addFiveSlider()
{
     topLayout->addWidget(variantSlider,1,4);
     topLayout->addWidget(labelVariant,0,4);
}

void Sin::showWindow()
{
window->show();
}

