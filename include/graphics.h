#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>

namespace gp{
    class Window{
    public:
        Window(const char* title, int width, int height);
        ~Window();
        void update();
        void clear();
        void draw();
        void close();
        bool isRunning(){return running;}
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool running;
    };
}

#endif