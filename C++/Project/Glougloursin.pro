QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GlougloursinCreator
TEMPLATE = app

RESOURCES += Resources/icon.png \
             Resources/upgrade.png

SOURCES += main.cpp\
           Sources/Core/grid.cpp \
           Sources/Core/powersquare.cpp \
           Sources/Core/square.cpp \
           Sources/Window/mainwindow.cpp \
           Sources/Window/view.cpp

HEADERS += Sources/Core/grid.h \
           Sources/Core/powersquare.h \
           Sources/Core/square.h \
           Sources/Window/mainwindow.h \
           Sources/Window/view.h

DEFINES += #QT_NO_DEBUG_OUTPUT

RC_FILE = app.rc
