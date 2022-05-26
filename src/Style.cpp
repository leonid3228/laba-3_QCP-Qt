#pragma once
#include <QString>
#include <QPushButton>


class Style{
    public:
    QString buttonStyle{"QPushButton{"
                        "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #98FB98, stop:1 #006400);"
                         "font: bold 14px;"
                        "border-color: rgb(0, 0, 0);"
                        "border-width : 4px;}"
                            "QPushButton:hover{"
                            "background-color: rgb(255,130,00);} "
                             "QPushButton:pressed  {"
                             "background-color: rgb(232,95,76); } "};

    QString buttonStyle2{"QPushButton{"
                        "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFA07A, stop:1 #800000);"
                    " border-style: outset;"
                        "border-width: 3px;"
                         "border-radius: 10px;"
                        "border-color: black;"
                         "font: bold 14px;"
                         "min-width: 10em;"
                         "padding: 6px;}"
                            "QPushButton:hover{"
                            "background-color: rgb(255,130,00);} "
                             "QPushButton:pressed  {"
                             "background-color: rgb(232,95,76); } "};

QString verticallSliderStyle {"QSlider::groove:vertical { ""border: 1px solid #999999;  ""background-color: white; ""margin: 2px 0; ""} ""QSlider::handle:vertical { ""background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #0000FF, stop:1 #002137); ""border: 1px solid #5c5c5c; ""height: 80px; ""margin: -2px 0px; ""} "};


QString horizontalSliderStyle {"QSlider::groove:horizontal { ""border: 1px solid #999999; ""height: 20px; ""background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4); ""margin: 2px 0; ""} ""QSlider::handle:horizontal { ""background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f); ""border: 1px solid #5c5c5c; ""width: 30px; ""margin: -2px 0px; ""} "};

QString labelStyle{"QLabel{""background-color:#4169E1;"
                   "color: white;"
                   "font: bold 14px;}"};
QString labelErrorStyle{"QLabel{""background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFA07A, stop:1 #800000);"
                   "color: white;"
                   "font: bold 14px;}"};
QString labelNoErrorStyle{"QLabel{""background-color: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #98FB98, stop:1 #006400);"
                   "color: white;"
                   "font: bold 14px;}"};




};
