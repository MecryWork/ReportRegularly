TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

unix {
    target.path = /usr/lib
    INSTALLS += target
    LIBS += -ldl -lpthread -luuid
}

SOURCES += main.cpp \
    Funtion.cpp \
    Thread.cpp

HEADERS += \
    Funtion.h \
    Thread.h \
    CallBackHelper.h

