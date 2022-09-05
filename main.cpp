#include "Headers/Window.h"
#include <string>

int main() 
{
    Window window(1920,1080,"Test #1");
    window.gameLoop();

    return 0;
}