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
        // init font
        TTF_Init();
        font = TTF_OpenFont("../res/fonts/arial/arial.ttf", 10);
        if(font == NULL){
            std::cout << "Failed to load font " << TTF_GetError() << std::endl;
        }

    }
    
    Graph::~Graph(){
        TTF_CloseFont(font);

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
        // draw the y ticks
        for(int i = 0; i < height; i += 10){
            SDL_RenderDrawLine(renderer, width/2 - 5, i, width/2 + 5, i);
        }

        // draw the x text
        displayText("x", width - 20, height/2 + 20);
        // draw the y text
        displayText("y", width/2 + 20, 20);

        // draw the x tick labels
        for(int i = 0; i < width; i += 50){
            displayText(std::to_string(i - width/2).c_str(), i, height/2 + 20);
        }
        // draw the y tick labels
        for(int i = 0; i < height; i += 50){
            displayText(std::to_string(height/2 - i).c_str(), width/2 + 20, i);
        }




    }
    void Graph::displayText(const char* text, int x, int y){
        SDL_Color color = {0, 0, 0, 255};
        surface = TTF_RenderText_Solid(font, text, color);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = 20;
        rect.h = 20;
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        
    }
    void Graph::update(){

    }
}