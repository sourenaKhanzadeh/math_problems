#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include <alvec.h>

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
        void zoomIn();
        void zoomOut();
        static bool zoom;
    private:
        SDL_Window* window;
        int width, height;
        SDL_Renderer* renderer;
        // font
        TTF_Font* font;
        SDL_Surface* surface;
        SDL_Texture* texture;
        int zoom_level;
    };
}

namespace gp{
    class Color{
    public:
        Color(int r, int g, int b, int a);
        ~Color();
        int getR(){return r;}
        int getG(){return g;}
        int getB(){return b;}
        int getA(){return a;}
    private:
        int r, g, b, a;
    };
}

namespace gp{
    class Line : public GameObject{
    public:
        Line(SDL_Renderer *renderer ,int x1, int y1, int x2, int y2);
        Line(SDL_Renderer *renderer ,int x1, int y1, int x2, int y2, Color *color);
        ~Line();
        void update();
        void draw();
        void zoomIn();
        void zoomOut();
    private:
        int x1, y1, x2, y2;
        Color *color;
        SDL_Renderer* renderer;
        int zoom_level;
    };
}

namespace gp{
    void addLine(int m, int b, Color *color);
    // add line using mx + b
    void addLine(int m, int b);
    // add a line using a vector
    template <typename T>
    void addLine(ALVec<T> &v){
        // get the slope
        double m = v[1] / v[0];
        // get the y-intercept
        double b = v[1] - m * v[0];
        // add the line
        addLine(m, b);
    }

    template <typename T>
    void addLine(ALVec<T> &v, Color *color){
        // get the slope
        double m = v[1]/ v[0];
        // get the y-intercept
        double b = v[1] - m * v[0];
        // add the line
        addLine(m, b, color);
    }
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
        static SDL_Renderer* renderer;
        static Vector<gp::Line*> lines;
        static int width, height;
    private:
        SDL_Window* window;
        bool running;
        Graph* graph;

    };
}

#endif