TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tree.cpp \
    treenode.cpp \
    triangle.cpp \
    rectangle.cpp \
    fsquare.cpp

HEADERS += \
    figure.h \
    tree.h \
    treenode.h \
    triangle.h \
    rectangle.h \
    fsquare.h
