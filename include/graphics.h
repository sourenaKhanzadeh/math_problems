#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

namespace gp{
    class GameObject{
    public:
        virtual void update() = 0;
        virtual void draw() = 0;
    };
}

namespace gp{
    class Graph : public GameObject{
    public:
        Graph(SDL_Window* window, SDL_Renderer* renderer);
        ~Graph();
        void draw();
        void update();
        void displayText(const char* text, int x, int y);
    private:
        SDL_Window* window;
        int width, height;
        SDL_Renderer* renderer;
        // font
        TTF_Font* font;
        SDL_Surface* surface;
        SDL_Texture* texture;
    };
}

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
        Graph* graph;

    };
}


#endif