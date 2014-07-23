#include "mainwindow.h"
#include <QApplication>
#include "testlua.h"
#include "GL/glew.h"
#include "lua.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    TestLua* t;
    t= new TestLua();
    t->test();
    return a.exec();
}
