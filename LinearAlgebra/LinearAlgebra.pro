TEMPLATE = app
CONFIG += console c++17
CONFIG += -std=c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    matrix.cpp \
    lu.cpp \
    tridiagonal.cpp \
    logger.cpp \
    eigenvalues.cpp \
    equtationsolver.cpp

HEADERS += \
    matrix.h \
    lu.h \
    tridiagonal.h \
    logger.h \
    eigenvalues.h \
    equtationsolver.h
