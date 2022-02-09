#include <SDL2/SDL.h>


#include "direction.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>




#include "application.hpp"
using namespace std;
Application::Application(){

    this->win = new MainSDLWindow();
    this->win -> Init("SNAKE",Size_w,Size_h);
    this->pg = new Playground(Size_w,Size_h);
    this->frame_rate_ms = frame_rate;
    this->pg->GenerateFruit();
    draw_fruit();
    
    
    while(1){   
        SDL_Event event;
        if (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                this->win->clean();
                break;    
            }    
        } 

        Uint32 frame_time_start = SDL_GetTicks();
        int score =this->pg->GetScore(); 
        this->pg->GetSnake()->Move();
        if(this->pg->Collide()==1){
            break;
        }
        if(this->pg->GetSnake()->Collide()==1){
            break;
        }
        if(this->pg->verif_MeetFruit()==1){
            this->pg->MeetFruit(); 
            score+=10;
       
        }


        SDL_SetRenderDrawColor(this->win->GetRenderer(),25,25,25, 255);
        SDL_RenderClear(this->win->GetRenderer());
        draw_fruit();
        draw_snake();
        SDL_RenderPresent(this->win->GetRenderer());


        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        SDL_Delay(this->frame_rate_ms - frame_time_interval);  
    }

    printf("END GAME\n");
    printf("SCORE: ");
    int score_print = this->pg->GetScore();
    printf("%d \n",&score_print);
}

Application::~Application(){

}

void Application::draw_fruit(){
    
    SDL_Rect fruit;
    fruit.x = this->pg->fruit_pos_x;
    fruit.y =this->pg->fruit_pos_y;
    fruit.w =PAS;
    fruit.h =PAS;
    
    SDL_SetRenderDrawColor(this->win->GetRenderer(), 0, 255, 85, 255); 
    SDL_RenderFillRect(this->win->GetRenderer(), &fruit);

}
void Application::draw_snake(){
    
    Segment * browsesnake = this->pg->GetSnake()->GetHead();
    while(1){       
            
            SDL_Rect snake;
            snake.x = browsesnake->GetPOS_X();
            snake.y = browsesnake->GetPOS_Y();
            snake.w =PAS; 
            snake.h =PAS; 
            
            SDL_SetRenderDrawColor(this->win->GetRenderer(), 255, 25, 25, 255); 
            SDL_RenderFillRect(this->win->GetRenderer(), &snake);

            if(browsesnake->GetNext()==NULL){
                break;
            }else{
                browsesnake=browsesnake->GetNext();         
            }
    }
}

int main(){

    printf("WELCOME TO SNAKE\n");
    Application * jeux = new Application();
    
    delete jeux;
    
}
