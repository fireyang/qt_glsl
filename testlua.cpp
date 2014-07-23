#include "testlua.h"

TestLua::TestLua()
{
}

void TestLua::test()
{
    lua_State *L=lua_open();
    /*载入Lua基本库*/
    luaL_openlibs(L);
    luaL_dostring(L,"print(1+2)");
    //luaopen_io (L);
    lua_close(L);
    cout << "logString" << std::endl;
}
