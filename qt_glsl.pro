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
    glwidget.cpp \
    glprogram.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    glprogram.h

FORMS    += mainwindow.ui

#glew类库
INCLUDEPATH += $$PWD/otherLib/include
win32{
    LIBS += -lglew32 -L$$PWD/otherLib/lib
}

unix {
    LIBS += -lGLEW -L$$PWD/otherLib/lib/mac
}
