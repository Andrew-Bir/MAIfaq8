TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread

SOURCES += main.cpp \
    rectangle.cpp \
    tree.cpp \
    triangle.cpp \
    square.cpp \
    node.cpp

HEADERS += \
    figure.h \
    rectangle.h \
    tree.h \
    triangle.h \
    node.h \
    iterator.h \
    square.h
