#ifndef TESTLUA_H
#define TESTLUA_H
#include <string>
using std::string;
#include <iostream>
using std::cout;

extern "C"{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"
}

class TestLua
{
public:
    TestLua();
    void test();
};

#endif // TESTLUA_H
