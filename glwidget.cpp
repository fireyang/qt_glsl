#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}


void GLWidget::initializeGL(){
    //glClearColor(1,1,0,1);
    //glClear(GL_COLOR_BUFFER_BIT);
}

void GLWidget::paintGL(){
    glClearColor(0.2,0.2,0.2,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    //glEnable(GL_MULTISAMPLE);
    //glHint (GL_MULTISAMPLE, GL_NICEST);
    //glEnable (GL_POLYGON_SMOOTH);
    //glHint (GL_POLYGON_SMOOTH, GL_NICEST);
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f(-0.5,-0.5,0);
        glColor3f(0,1,0);
        glVertex3f(0.5,-0.5,0);
        glColor3f(0,0,1);
        glVertex3f(0.0,0.5,0);
    glEnd();

}
void GLWidget::resizeGL(int w,int h){
    glViewport(0,0,w,h);
}
