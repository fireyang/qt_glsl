#include "glwidget.h"


// Shader sources
const GLchar* vertexSource =
    "#version 150 core\n"
    "in vec2 position;"
    "void main() {"
    "   gl_Position = vec4(position, 0.0, 1.0);"
    "}";
const GLchar* fragmentSource =
    "#version 150 core\n"
    "out vec4 fragColor;"
    "void main() {"
    "   fragColor = vec4(1.0, 1.0, 1.0, 1.0);"
    "}";


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}


void GLWidget::initializeGL(){
    //glClearColor(1,1,0,1);
    glewInit();
    //glClearColor(1,1,0,1);
    //glClear(GL_COLOR_BUFFER_BIT);
    // Create Vertex Array Object


    GLuint vao;
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object and copy the vertex data to it
    GLuint vbo;
    glGenBuffers(1, &vbo);

    GLfloat vertices[] = {
        0.0f, 0.5f,
        0.5f, -0.5f,
        -0.5f, -0.5f
    };


    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Create and compile the vertex shader
    //const string &str = vertexSource;
   // shader.compileShaderFromString(str,GLSLShader::VERTEX);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    // Create and compile the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    // Link the vertex and fragment shader into a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    //glBindFragDataLocation(shaderProgram, 0, "fragColor");
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    // Specify the layout of the vertex data
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // Clear the screen to black
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   // Draw a triangle from the 3 vertices
   glDrawArrays(GL_TRIANGLES, 0, 3);

   glDeleteProgram(shaderProgram);
   glDeleteShader(fragmentShader);
   glDeleteShader(vertexShader);

   glDeleteBuffers(1, &vbo);

   glDeleteVertexArrays(1, &vao);

}

void GLWidget::paintGL(){

    //glClearColor(1,1,0,1);
    //glClear(GL_COLOR_BUFFER_BIT);

    // Clear the screen to black
  // glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
   //glClear(GL_COLOR_BUFFER_BIT);

   // Draw a triangle from the 3 vertices
  // glDrawArrays(GL_TRIANGLES, 0, 3);

    /*
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
    */
}
void GLWidget::resizeGL(int w,int h){
    glViewport(0,0,w,h);
}
