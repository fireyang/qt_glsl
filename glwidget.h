#ifndef GLWIDGET_H
#define GLWIDGET_H
#include "glslprogram.h"
#include <QGLWidget>


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);\
    void initializeGL();
    void paintGL();
    void resizeGL(int w,int h);

private:
     GLSLProgram shader;

};

#endif // GLWIDGET_H
