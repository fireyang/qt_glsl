#include "GL/glew.h"
#include "testCurl.h"


#include <QCoreApplication>



int main(int argc, char *argv[])
{
     glewInit();

    //testZlib();
    //testCurl();



    QCoreApplication a(argc, argv);

    return a.exec();
}


