#include "testcarre.hpp"
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

int move_x = 0;
int move_y = 0;



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

    this->window = SDL_CreateWindow( name , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , largeur , hauteur, SDL_WindowFlags());
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

void MainSDLWindow::clear()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void keyboard() {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP] &&  move_y !=10) {
        move_x = 0;
        move_y =-10;
        }
    if (keystates[SDL_SCANCODE_DOWN]  &&  move_y != -10){
        move_x = 0;
        move_y =10;
    }
    if (keystates[SDL_SCANCODE_LEFT]  &&  move_x != 10){
        move_x = -10;
        move_y = 0;
    }
    if (keystates[SDL_SCANCODE_RIGHT]  &&  move_x != -10){
        move_x = 10;
        move_y = 0;
    }
}

int main(void) {
    MainSDLWindow main_window;
    int largeur;
    int hauteur;
    main_window.Init("salut", largeur = 500,  hauteur = 600);

    SDL_Rect srcrect;
        
    srcrect.x = 250;
    srcrect.y = 350;
    srcrect.w = 20;
    srcrect.h = 20;
    while(true){
        SDL_Delay(20);
        int frame_time_start = SDL_GetTicks();

        srcrect.x = srcrect.x+move_x;
        srcrect.y = srcrect.y+move_y;

        SDL_SetRenderDrawColor( main_window.GetRenderer(), 25, 25, 25, 0 );


        SDL_RenderClear(  main_window.GetRenderer() );
        SDL_SetRenderDrawColor( main_window.GetRenderer(), 255, 0, 0, 255 );

        SDL_RenderFillRect(  main_window.GetRenderer(), &srcrect );
        SDL_RenderPresent( main_window.GetRenderer());
        SDL_SetRenderDrawColor( main_window.GetRenderer(), 25, 25, 25, 0 );
        keyboard();
  
   
        SDL_Event event;
        if (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){

                main_window.clear();
                break;                
            }      
        }    
        if (srcrect.x<0 ||srcrect.y<100 ||srcrect.x > largeur-srcrect.w || srcrect.y >hauteur-srcrect.h){
            break;
        }
    SDL_Delay(SDL_GetTicks() - frame_time_start );

    }
    main_window.~MainSDLWindow();
}
