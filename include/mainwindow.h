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
#include <QWidget>
#include <cmath>
#include <QTimer>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QString>
#include <sin.h>
#include <QPen>
#include <QCheckBox>
#include <triangle.h>
#include <rand.h>
#include <QRadioButton>
#include <memory>
#include <QSlider>
#include "variant.h"

class Main : public QWidget
{
    Q_OBJECT
public:
    enum class States{
        Sin,
        Treyg,
        Rand,
        Variant
    };
explicit Main(QWidget *parent = nullptr);
States state;
 Sin *sinus;Triangle *tri; Variant *variant ;
 Randome *random;
 QPen graphPen,graphPen2,graphPen3,graphPen4;
 QCustomPlot *customPlot,*plotDelay;
 int maxXPlot,minXPlot; double x;
 int maxXPlotDelay,minXPlotDelay; double xDelay;
 QTimer *timer;QSlider * getDelay;

 QCheckBox  *radioButtonSin,*radioButtontri,*radioButtonrand,*radioButtonVar ;

 QPushButton *startButton,*stopButton ;

private slots:
void slotTimerAlarm();
void drawDelay();
};
