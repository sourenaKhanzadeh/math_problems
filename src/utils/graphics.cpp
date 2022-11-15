#include <graphics.h>

namespace gp{
    SDL_Renderer* Window::renderer = nullptr;
    Vector<Line*> Window::lines;
    int Window::width = 0;
    int Window::height = 0;
    Window::Window(const char* title, int width, int height){
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        Window::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        running = true;
        graph = new Graph(window, renderer);
        Window::width = width;
        Window::height = height;
    }
    Window::~Window(){
        SDL_DestroyRenderer(Window::renderer);
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

        for(int i = 0; i < lines.size(); i++){
            lines[i]->update();
        }
        graph->update();
    }
    void Window::clear(){
        SDL_SetRenderDrawColor(Window::renderer, 0xff, 0xff, 0xff, 255);
        SDL_RenderClear(Window::renderer);
    }
    void Window::draw(){

        graph->draw();
        for(int i = 0; i < lines.size(); i++){
            lines[i]->draw();
        }

        SDL_SetRenderDrawColor(Window::renderer, 255, 255, 255, 255);
        SDL_RenderPresent(Window::renderer);
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
        for(int i = 0; i < width; i += 100){
            SDL_RenderDrawLine(renderer, i, height/2 - 5, i, height/2 + 5);
        }
        // draw the y ticks
        for(int i = 0; i < height; i += 100){
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

namespace gp{
    Color::Color(int r, int g, int b, int a){
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
    Color::~Color(){

    }
}
namespace gp{
    Line::Line(SDL_Renderer *renderer ,int x1, int y1, int x2, int y2){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->color = new Color(0, 0, 0, 255);
        this->renderer = renderer;
    }

    Line::Line(SDL_Renderer *renderer ,int x1, int y1, int x2, int y2, Color *color){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->color = color;
        this->renderer = renderer;
    }

    Line::~Line(){
        
    }

    void Line::draw(){
        SDL_SetRenderDrawColor(renderer, color->getR(), color->getG(), color->getB(), color->getA());
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
    
    void Line::update(){

    }
}

namespace gp{
    void addLine(int m, int b){
        // get the window width and height
        int w = Window::width;
        int h = Window::height;
        // draw a line from the center of the screen to the edge of the screen

        // get the x and y coordinates of the line on the cartesian plane
        int x1 = -w/2;
        int y1 = m * x1 + b * 100;
        int x2 = w/2;
        int y2 = m * x2 + b * 100;

        // flip vertically
        y1 = -y1;
        y2 = -y2;

        // translate to the center of the screen
        x1 += w/2;
        y1 += h/2;
        x2 += w/2;
        y2 += h/2;


        // create the line
        Window::lines.add(new Line(Window::renderer, x1, y1, x2, y2));
    }

    void addLine(int m, int b, Color *color){
        // get the window width and height
        int w = Window::width;
        int h = Window::height;
        // draw a line from the center of the screen to the edge of the screen

        // get the x and y coordinates of the line on the cartesian plane
        int x1 = -w/2;
        int y1 = m * x1 + b * 100;
        int x2 = w/2;
        int y2 = m * x2 + b * 100;

        // flip vertically
        y1 = -y1;
        y2 = -y2;

        // translate to the center of the screen
        x1 += w/2;
        y1 += h/2;
        x2 += w/2;
        y2 += h/2;


        // create the line
         Window::lines.add(new Line(Window::renderer, x1, y1, x2, y2, color));
    }
}