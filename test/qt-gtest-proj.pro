QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-gtest-proj
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

COMPILER = icpc
QMAKE_CC = $$COMPILER
QMAKE_CXX = $$COMPILER
QMAKE_LINK = $$COMPILER

LIBS += -lgtest

SOURCES += main.cc

HEADERS  += \
    configurations-test.h \
    enum-helper-test.h \
    hit-counter-test.h \
    registry-test.h \
    test.h \
    typed-configurations-test.h \
    utilities-test.h \
    helpers-test.h \
    write-all-test.h \
    easylogging++.h \
    global-configurations-test.h \
    loggable-test.h \
    logger-test.h \
    verbose-app-arguments-test.h \
    custom-format-specifier-test.h \
    syslog-test.h
