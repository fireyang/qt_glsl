#include "glprogram.h"

GLProgram::GLProgram()
{
}



bool GLProgram::compileShaderFromString(const string& source, GLSLShader::GLSLShaderType type )
{
    if( handle <= 0 ){
        handle = glCreateProgram();

        if( handle == 0){
            logString = "Unable to create shader program.";
            return false;
        }
    }
    GLuint shaderHandle = 0;

    switch(type) {
    case GLSLShader::VERTEX:
        shaderHandle = glCreateShader(GL_VERTEX_SHADER);
        break;
    case GLSLShader::FRAGMENT:
        shaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
        break;
    case GLSLShader::GEOMETRY:
        shaderHandle = glCreateShader(GL_GEOMETRY_SHADER);
        break;
    case GLSLShader::TESS_CONTROL:
        shaderHandle = glCreateShader(GL_TESS_CONTROL_SHADER);
        break;
    case GLSLShader::TESS_EVALUATION:
        shaderHandle = glCreateShader(GL_TESS_EVALUATION_SHADER);
        break;
    default:
        return false;
    }

    const char *c_code = source.c_str();
    glShaderSource( shaderHandle, 1, &c_code, NULL );

    // Compile the shader
    glCompileShader(shaderHandle);

    // Check for errors
    int result;
    glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &result);
    if( GL_FALSE == result)
    {
        // Compile failed, store log and return false
        int length = 0;
        logString = "";
        glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &length );

        if( length > 0 )
        {
            char *c_log = new char[length];
            int written = 0;
            glGetShaderInfoLog(shaderHandle, length, &written, c_log);
            logString = c_log;
            delete [] c_log;
        }

        return false;
    }

    else
    {
        // Compile succeeded, attach shader and return true
        glAttachShader(handle, shaderHandle);
        return true;
    }
}



bool GLProgram::link()
{
    if(linked) return true;

    if(handle <= 0) return false;

    glLinkProgram(handle);

    int status = 0;
    glGetProgramiv( handle, GL_LINK_STATUS, &status);

    if( GL_FALSE == status )
    {
        // Store log and return false
        int length = 0;
        logString = "";

        glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &length );

        if(length > 0)
        {
            char * c_log = new char[length];
            int written = 0;
            glGetProgramInfoLog(handle, length, &written, c_log);
            logString = c_log;
            delete [] c_log;
        }

        return false;
    }

    else
    {
        linked = true;
        return linked;
    }
}

void GLProgram::use()
{
    if(handle <= 0 || (! linked) ) return;
    glUseProgram( handle );
}

void GLProgram::bindAttribLocation( GLuint location, const char * name)
{
    glBindAttribLocation(handle, location, name);
}

void GLProgram::bindFragDataLocation( GLuint location, const char * name )
{
    glBindFragDataLocation(handle, location, name);
}


int GLProgram::getHandle()
{
    return handle;
}

bool GLProgram::isLinked()
{
    return linked;
}
