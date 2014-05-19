#-------------------------------------------------
#
# Project created by QtCreator 2014-05-19T14:37:05
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_glsl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui

#glew类库
win32{
    INCLUDEPATH += $$PWD/otherLib/include
    LIBS += -lglew32 -L$$PWD/otherLib/lib
}
