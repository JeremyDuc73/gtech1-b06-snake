#include "exercice1.hpp"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

MainSDLWindow::MainSDLWindow(void){
    window = NULL;
    renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(void){

}

int MainSDLWindow::Init(const char *name, int largeur,int hauteur){
    
    if (SDL_Init(SDL_INIT_VIDEO)<0)
    {
        cout << "Error: INIT() function failed";
        return EXIT_FAILURE;
    }

    this->window = SDL_CreateWindow( name , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , largeur,hauteur, SDL_WindowFlags());
    if (window == NULL) {
        cout << "Error: SDL-CreateWindow() failed";
        return EXIT_FAILURE;
    }

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        cout << "Error: SDL-CreateRenderer() failed";
        return EXIT_FAILURE;
    }


    SDL_SetRenderDrawColor(renderer,0,0,0, SDL_ALPHA_OPAQUE);

    
    
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this->renderer;
}

int main(void) {
    MainSDLWindow main_window;
    main_window.Init("salut", 200,200);
}