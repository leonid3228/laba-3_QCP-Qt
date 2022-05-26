#include "mainwindow.h"
#include "QTabBar"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGridLayout"
#include "QDebug"
#include "tab.h"
#include "memory"
#include "variant.h"
Main::Main(QWidget *parent)
    : QWidget{parent}
{

    sinus = new Sin();
    tri = new Triangle();
    random = new Randome();
    variant = new Variant();
    getDelay = new QSlider;
    plotDelay = new QCustomPlot();
    customPlot = new QCustomPlot();
    QVBoxLayout *leftLayout  = new QVBoxLayout();
    QHBoxLayout *botLayout  = new QHBoxLayout();
    timer = new QTimer();

       getDelay = new QSlider(Qt::Vertical);
       getDelay->setMaximum(10);
       getDelay->setMinimum(0);
       getDelay->setValue(0);

        radioButtonSin = new QCheckBox("СИНУСОИДА");
        radioButtontri = new QCheckBox("ТРЕУГОЛЬНИК");
        radioButtonrand = new QCheckBox("РАНДОМ");
        radioButtonVar = new QCheckBox("Вариант");
        startButton = new QPushButton("START");
        stopButton = new QPushButton("STOP");



        botLayout->addWidget(customPlot);
        botLayout->addWidget(plotDelay);
        botLayout->addWidget(getDelay);

        leftLayout->addLayout(botLayout);
        leftLayout->addWidget(startButton);
        leftLayout->addWidget(stopButton);



//       leftLayout->addWidget(radioButtonSin);
//       leftLayout->addWidget(radioButtontri);
//       leftLayout->addWidget(radioButtonrand);
//        leftLayout->addWidget(radioButtonVar);

        graphPen.setWidth(1);
        graphPen.setColor(QColor(qrand()%255,qrand()%255,qrand()%255));
        graphPen2.setWidth(1);
        graphPen2.setColor(QColor(qrand()%255,qrand()%255,qrand()%255));
        graphPen3.setWidth(1);
        graphPen3.setColor(QColor(qrand()%255,qrand()%255,qrand()%255));
        graphPen4.setWidth(1);
        graphPen4.setColor(QColor(qrand()%255,qrand()%255,qrand()%255));

                maxXPlot = 10; x = 0;
              customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
              customPlot->yAxis->setBasePen(QPen(Qt::black, 1));
              customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
              customPlot->yAxis->setTickPen(QPen(Qt::black, 1));
              customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
              customPlot->yAxis->setSubTickPen(QPen(Qt::black, 1));
              customPlot->xAxis->setTickLabelColor(Qt::white);
              customPlot->yAxis->setTickLabelColor(Qt::black);
              customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
              customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
              customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
              customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
              customPlot->xAxis->grid()->setSubGridVisible(false);
              customPlot->yAxis->grid()->setSubGridVisible(false);
              customPlot->xAxis->setRange(0, maxXPlot);
              customPlot->yAxis->setRange(-10, 10);
              plotDelay->yAxis->setRange(-10, 10);
              customPlot->addGraph();
              customPlot->addGraph();
              customPlot->addGraph();
              customPlot->addGraph();
              customPlot->addGraph();
              plotDelay->addGraph();
              plotDelay->addGraph();

              setLayout(leftLayout);
              resize(600,600);


              connect(startButton,(&QPushButton::clicked), [&](){ timer->start(10);});
              connect(stopButton,(&QPushButton::clicked), [&](){ timer->stop();});
              connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

              state = States::Sin;
}

void Main::slotTimerAlarm()
{

    if(x>=maxXPlot){
        minXPlot = maxXPlot;
        maxXPlot+= 50;
        customPlot->xAxis->setRange(minXPlot-20, maxXPlot);
    }
    customPlot->graph(0)->addData(x,sinus->getY());
    customPlot->graph(0)->setPen(graphPen);
    customPlot->graph(1)->addData(x,tri->getY());
    customPlot->graph(1)->setPen(graphPen2);
    customPlot->graph(2)->addData(x,random->getY());
    customPlot->graph(2)->setPen(graphPen3);
    customPlot->graph(3)->addData(x,variant->getY());
    customPlot->graph(3)->setPen(graphPen4);
    customPlot->replot();

    x+=0.05;
    xDelay+=0.05;
    drawDelay();

}
void Main::drawDelay()
{
    if(x>=maxXPlotDelay){
        minXPlotDelay = maxXPlotDelay;
        maxXPlotDelay+= 50;
        plotDelay->xAxis->setRange(minXPlotDelay-20, maxXPlotDelay);
    }
    if(state == States::Sin){
        plotDelay->graph(0)->addData(x,sinus->getY());
        plotDelay->graph(0)->setPen(graphPen4);
        plotDelay->graph(1)->addData(x-(getDelay->value()),sinus->getY());
        plotDelay->graph(1)->setPen(graphPen3);
        plotDelay->replot();}

    if(state == States::Variant){
        plotDelay->graph(0)->addData(x,variant->getY());
        plotDelay->graph(0)->setPen(graphPen4);
        plotDelay->graph(1)->addData(x-(getDelay->value()),variant->getY());
        plotDelay->graph(1)->setPen(graphPen3);
        plotDelay->replot();}

    if(state == States::Treyg){
        plotDelay->graph(0)->addData(x,tri->getY());
        plotDelay->graph(0)->setPen(graphPen4);
        plotDelay->graph(1)->addData(x-(getDelay->value()),tri->getY());
        plotDelay->graph(1)->setPen(graphPen3);
        plotDelay->replot();}

    if(state == States::Rand){
        plotDelay->graph(0)->addData(x,random->getY());
        plotDelay->graph(0)->setPen(graphPen4);
        plotDelay->graph(1)->addData(x-(getDelay->value()),random->getY());
        plotDelay->graph(1)->setPen(graphPen3);
        plotDelay->replot();}

}


