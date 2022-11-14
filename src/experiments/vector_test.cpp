#include <almat.h>
#include <graphics.h>

int main(){
    gp::Window window("Vector Test", 800, 600);

    // update the window
    while(window.isRunning()){
        window.update();
        window.clear();
        window.draw();
    }
    return 0;
}