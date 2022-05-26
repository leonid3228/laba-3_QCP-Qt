#pragma once
#include <QGridLayout>
#include <QMainWindow>
#include <qcustomplot.h>
#include <QSlider>
#include <Style.cpp>
#include <QLabel>
#include <QString>
#include "QPushButton"
#include <QGridLayout>
#include <qcustomplot.h>
#include <QWidget>
#include <cmath>
#include <QTimer>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QString>
#include <QPen>
class Sin : public QWidget
{
    Q_OBJECT
public:
    explicit Sin(QWidget *parent = nullptr);

    virtual bool  errorState();

    double getY() const;

    void setY(double newY);

    virtual void graphVariant();

    virtual void graphVariant2();

    void addFourthSlider();
    void addFiveSlider();

    virtual void showWindow();

public slots:
    void  slotTimerAlarm();

    virtual void drawErrorGraph();

    void rescaleX();

    virtual void resizeVec();

public:
    //Buttons
    QPushButton *startButton,*stopButton;
    //Scroll
    QSlider * amplitude,*freq,*line,*axesWidth,*lineMin,*variantSlider;
    //PLOTS
    QCustomPlot *customPlot;

    //WIDGET
    QWidget *window;
    //TIMERS
    QTimer *timer;
    //LABELS
    QLabel *label4,*labelG,*labelA,*label5,*labelT,*labelMin,*labelVariant;
    //variables
    double x = 0,y;

    double maxXPlot = 40;
    double minXPlot = 0; int zz {0}; //zz - добавление графика нижней ошибки
    //Layout
    QVBoxLayout *leftLayout ;
    QVBoxLayout *rightLayout ;
    QGridLayout *botLayout ;
    QGridLayout *topLayout ;
    QHBoxLayout *mainLayout ;
    QTimer * timerFordelay;
    //Pen+styles
    QPen graphPen,errorPen;Style myStyles;
    double getX() const;
};


