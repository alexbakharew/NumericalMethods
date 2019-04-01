TEMPLATE = app
CONFIG += console c++11
CONFIG += -std=c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    matrix.cpp \
    lu.cpp \
    tridiagonal.cpp

HEADERS += \
    matrix.h \
    lu.h \
    tridiagonal.h
