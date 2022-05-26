QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/qcustomplot.cpp \
    src/rand.cpp \
    src/sin.cpp \
    src/Style.cpp \
    src/tab.cpp \
    src/triangle.cpp \
    src/variant.cpp \


HEADERS += \
    include/mainwindow.h \
    include/qcustomplot.h \
    include/rand.h \
    include/sin.h \
    include/tab.h \
    include/triangle.h \
    include/variant.h

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/src
FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
