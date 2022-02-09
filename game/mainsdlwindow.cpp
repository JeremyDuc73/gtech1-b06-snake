#include "mainsdlwindow.hpp"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

MainSDLWindow::MainSDLWindow(void){
    this->window = NULL;
    this->renderer = NULL;
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
    if (this->window == NULL) {
        cout << "Error: SDL-CreateWindow() failed";
        return EXIT_FAILURE;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == NULL) {
        cout << "Error: SDL-CreateRenderer() failed";
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this->renderer;
}

void MainSDLWindow::clean(){
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

// void MainSDLWindow::draw_frui(int-x_pos,int y_pos){
    

// }
