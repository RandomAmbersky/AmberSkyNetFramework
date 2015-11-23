#include ( AmberSkyNet.pri )
include (../../AmberSkyNet/Artemis-CPP/QtCreator/ArtemisCpp.pri )

QT -= core
QT -= gui

TARGET = ../bin/AmberSkyNetFramework
CONFIG += console
CONFIG -= app_bundle

SOURCES += \
    ../../main.cpp

TEMPLATE = app
