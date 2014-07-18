#include "glwidget.h"

static const char gVertexShader[] = "attribute vec4 vPosition;\n"
        "void main() {\n"
         "  gl_Position = vPosition;\n"
        "}\n";

static const char gFragmentShader[] = "precision mediump float;\n"
        "void main() {\n"
         "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
        "}\n";

static GLfloat const vs[] = {
    1.0f,1.0f,0.0f,
    -1.0f,1.0f,0.0f,
    -1.0f,-1.0f,0.0f
};

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}


void GLWidget::initializeGL(){
    shader.compileShaderFromString(gVertexShader,GLSLShader::VERTEX);
    shader.compileShaderFromString(gFragmentShader,GLSLShader::FRAGMENT);
    if(!shader.link())
    {
        std::cerr << "Shader failed to link\n";
        return;
    }

    shader.use();

    int handle =  shader.handle;
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
