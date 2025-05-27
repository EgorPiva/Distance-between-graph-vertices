QT += core sql network
TARGET = DBServer
TEMPLATE = app
CONFIG += c++17

SOURCES += main.cpp DBServer.cpp
HEADERS += DBServer.h

CONFIG += console
CONFIG -= app_bundle
