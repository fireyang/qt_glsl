#ifndef GLSLPROGRAM_H
#define GLSLPROGRAM_H

#include "GL/glew.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;

namespace GLSLShader {
    enum GLSLShaderType {
        VERTEX, FRAGMENT, GEOMETRY,
        TESS_CONTROL, TESS_EVALUATION
    };
}

class GLSLProgram
{
public:
    GLSLProgram();
    bool compileShaderFromString(const string& source, GLSLShader::GLSLShaderType type );
private:
    int  handle;
    string logString;
};

#endif // GLSLPROGRAM_H
