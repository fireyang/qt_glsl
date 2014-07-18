#ifndef GLPROGRAM_H
#define GLPROGRAM_H
#include "GL/glew.h"

namespace GLSLShader {
    enum GLSLShaderType {
        VERTEX, FRAGMENT, GEOMETRY,
        TESS_CONTROL, TESS_EVALUATION
    };
}

class GLProgram
{
public:
    GLProgram();
    bool   compileShaderFromString(const string& source, GLSLShader::GLSLShaderType type);
    bool   link();
    void   use();
    void   bindAttribLocation( GLuint location, const char *name);
    void   bindFragDataLocation( GLuint location, const char *name);
    int    getHandle();
    bool   isLinked();
private:
    int  handle;
    bool linked;
    string logString;
};

#endif // GLPROGRAM_H
