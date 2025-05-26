TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    source.cpp

HEADERS += \
    header.h
LIBS += -lgdi32
