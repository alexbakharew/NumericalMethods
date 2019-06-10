TEMPLATE = app
CONFIG += console c++17
QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        boostedmatrix.cpp \
        main.cpp

HEADERS += \
    boostedmatrix.h
