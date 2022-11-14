#include <graphics.h>

namespace gp{
    Window::Window(const char* title, int width, int height){
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        running = true;
        graph = new Graph(window, renderer);
    }
    Window::~Window(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    void Window::update(){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            }
        }

        graph->update();
    }
    void Window::clear(){
        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
        SDL_RenderClear(renderer);
    }
    void Window::draw(){

        graph->draw();

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderPresent(renderer);
    }
    void Window::close(){
        running = false;
    }
}

namespace gp{
    Graph::Graph(SDL_Window* window, SDL_Renderer* renderer){
        this->window = window;
        this->renderer = renderer;
        int w, h;
        // get window height and width
        SDL_GetWindowSize(window, &w, &h);
        this->width = w;
        this->height = h;
    }
    
    Graph::~Graph(){
    }
    void Graph::draw(){
        // draw the cartesian plane
        // draw the x and y axis
        // draw the x and y labels
        // draw the x and y ticks
        // draw the x and y tick labels
        // draw the graph

        // draw the x axis
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawLine(renderer, 0, height/2, width, height/2);
        // draw the y axis
        SDL_RenderDrawLine(renderer, width/2, 0, width/2, height);

        // draw the x ticks
        for(int i = 0; i < width; i += 10){
            SDL_RenderDrawLine(renderer, i, height/2 - 5, i, height/2 + 5);
        }

    }
    void Graph::update(){

    }
}