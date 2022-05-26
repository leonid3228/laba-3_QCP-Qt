#include "tab.h"
#include "QTabWidget"
#include "QGridLayout"
#include "mainwindow.h"
#include "QDebug"
#include "QTabBar"
Tab::Tab(QWidget *parent)
    : QMainWindow{parent}

{
menu = new QMenu;
    tabWidget = new QTabWidget;
    tabWidget->setTabShape(QTabWidget::Rounded);
    tabWidget->setTabPosition(QTabWidget::West);
    tabWidget->setTabPosition(QTabWidget::North);
    label = new QLabel;

    Maine = new Main();
    tabRand = tabWidget->addTab(Maine->random, "Рандом");
    tabTreyg =  tabWidget->addTab(Maine->tri, "Треугольник");
    tabSinus =  tabWidget->addTab(Maine->sinus, "Синусоида");
    tabVariant =  tabWidget->addTab(Maine->variant, "По Варианту");

    tb = new QTabBar;
    tabWidget->addTab(Maine, "Главное окно");
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(tabWidget);
    timer = new QTimer;
    timer->start(20);
    setCentralWidget(tabWidget);

    menu = new QMenu("Меню");
    QAction *actionsin = new QAction;
    actionsin->setText("Синусоида");
    //actionsin->setCheckable(true);
    //actionsin->setChecked(true);

    QAction *actionTreyg = new QAction;
    actionTreyg->setText("Треугольник");
   // actionTreyg->setCheckable(true);
    //actionTreyg->setChecked(false);

    QAction *actionRand = new QAction;
    actionRand->setText("Рандом");
    //actionRand->setCheckable(true);
    //actionRand->setChecked(false);

    QAction *actionVariant = new QAction;
    actionVariant->setText("Вариант");
   // actionVariant->setCheckable(true);
    //actionVariant->setChecked(false);



label->setText("Сейчас Ничего");

    menu->addAction(actionsin);
    menu->addAction(actionTreyg);
    menu->addAction(actionRand);
    menu->addAction(actionVariant);
statusBar()->addWidget(label);
    //menu->addAction(actionExit);QQQQQQQQQQQQQQQQQQQQQQQQQQQ
    menuBar()->addMenu(menu);

    connect(actionsin, (&QAction::triggered), this, [&](){ Maine->state = Maine->States::Sin;label->setText("Сейчас Синусоида");});
    //connect(actionsin, (&QAction::triggered), [&](){ Maine->state = Maine->States::Sin;actionVariant->setChecked(false);actionRand->setChecked(false);actionTreyg->setChecked(false);});

    connect(actionTreyg, (&QAction::triggered), this, [&](){ Maine->state = Maine->States::Treyg;label->setText("СейчасТреугольник");});
    //connect(actionTreyg, (&QAction::triggered), [&](){ Maine->state = Maine->States::Treyg;actionVariant->setChecked(false);actionRand->setChecked(false);actionsin->setChecked(false);});

    connect(actionRand, (&QAction::triggered), this, [&](){ Maine->state = Maine->States::Rand;label->setText("Сейчас Рандом");});
    //connect(actionRand, (&QAction::triggered),  [&](){ Maine->state = Maine->States::Rand;actionVariant->setChecked(false);actionsin->setChecked(false);actionTreyg->setChecked(false);});

   //connect(actionVariant, (&QAction::triggered), [&](){ Maine->state = Maine->States::Variant;actionRand->setChecked(false);actionsin->setChecked(false);actionTreyg->setChecked(false);});
     connect(actionVariant, (&QAction::triggered), this, [&](){ Maine->state = Maine->States::Variant;label->setText("Сейчас по Варианту");});
   resize(900, 520);

}

       void Tab::drawTabColor()
       {
       if( Maine->random->errorState() ==true)
        tabWidget->tabBar()->setTabTextColor(tabRand,Qt::red);
       else
           tabWidget->tabBar()->setTabTextColor(tabRand,Qt::black);
       if( Maine->tri->errorState() ==true)
        tabWidget->tabBar()->setTabTextColor(tabTreyg,Qt::red);
       else
           tabWidget->tabBar()->setTabTextColor(tabTreyg,Qt::black);
       if( Maine->sinus->errorState() ==true)
        tabWidget->tabBar()->setTabTextColor(tabSinus,Qt::red);
       else
           tabWidget->tabBar()->setTabTextColor(tabSinus,Qt::black);

       if( Maine->variant->errorState() ==true)
        tabWidget->tabBar()->setTabTextColor(tabVariant,Qt::red);
       else
           tabWidget->tabBar()->setTabTextColor(tabVariant,Qt::black);

       }
