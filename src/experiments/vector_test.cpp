#include <almat.h>
#include <graphics.h>

int main(){
    gp::Window window("Vector Test", 800, 600);
    gp::addLine(1, 0);
    gp::addLine(1, 1);
    gp::addLine(1, 2, new gp::Color(255, 0, 0, 255));
    gp::addLine(1, 3, new gp::Color(0, 255, 0, 255));
    gp::addLine(1, 4, new gp::Color(0, 0, 255, 255));

    // update the window
    while(window.isRunning()){
        window.update();
        window.clear();
        window.draw();
    }
    return 0;
}