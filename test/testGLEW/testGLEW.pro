#-------------------------------------------------
#
# Project created by QtCreator 2014-08-21T10:32:00
#
#-------------------------------------------------

QT       += core opengl

QT       -= gui

TARGET = testGLEW
CONFIG   += console
CONFIG   -= app_bundle

#CONFIG   += c++11

#QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -stdlib=libc++
#QMAKE_LFLAGS += -lc++


TEMPLATE = app

LIBPATH = $$PWD/../../otherLib/


#DEFINES += GLEW_STATIC
INCLUDEPATH += $${LIBPATH}/glew-1.10.0/include
LIBS += -lglew32 -L$${LIBPATH}/glew-1.10.0/lib

#INCLUDEPATH += $${LIBPATH}/include
#LIBS += -lglew32 -L$${LIBPATH}/lib

#use curl lib
DEFINES += CURL_STATICLIB
INCLUDEPATH += $${LIBPATH}/curl-7.37.1/include
LIBS += -L$${LIBPATH}/curl-7.37.1/lib -lcurl -lws2_32 -lwldap32
#LIBS += $${LIBPATH}/curl-7.37.1/lib/libcurl.a
#LIBS += $${LIBPATH}/curl-7.37.1/lib/libcurldll.a

#INCLUDEPATH += $${LIBPATH}/include
#LIBS += -lglew32  -lopengl32 -L$${LIBPATH}/lib

#zlib
LIBS += $${LIBPATH}/zlib-1.2.8/libz.a
INCLUDEPATH += $${LIBPATH}/zlib-1.2.8/

#freetype
LIBS += $${LIBPATH}/freetype-2.5.3/objs/.libs/libfreetype.a
INCLUDEPATH += $${LIBPATH}/freetype-2.5.3/include


SOURCES += main.cpp

HEADERS += \
    testCurl.h