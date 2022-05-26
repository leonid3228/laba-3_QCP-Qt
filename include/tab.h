#ifndef TAB_H
#define TAB_H
#include "rand.h"
#include <QWidget>
#include <QTimer>
#include "QTabWidget"
#include "QGridLayout"
#include "mainwindow.h"
#include "QTabBar"
#include "QAction"
#include "QMenu"

class Tab: public QMainWindow
{
    Q_OBJECT
public:
    explicit Tab(QWidget *parent = nullptr);
    QTabWidget *tabWidget;
    Main* Maine;QLabel* label;
    QTimer * timer;QTabBar* tb;
    int tabSinus,tabTreyg,tabRand,tabVariant;
    QMenu *menu;
public slots:
    void drawTabColor();
};

#endif // TAB_H
