#include "App.hpp"

int main()
{
    App app;
    int modelBind = app.LoadModel("../res/objs/diablo.obj", "../res/textures/diablo.tga");
    while(!app.ShouldClose())
        app.DrawFrame();

    return EXIT_SUCCESS;
}