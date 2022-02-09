#include "snake.hpp"
#include "direction.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
using namespace std;

Snake::Snake(int pos_x, int pos_y, int dir){
    this->head=  new Segment(pos_x, pos_y, dir);
}

Snake::~Snake(){
}

int Snake::Collide(){
    Segment * head_tpm= GetHead();
    Segment * browsesnake = GetHead();
    while(browsesnake->GetNext() != NULL){

        if (head_tpm->GetPOS_X() == browsesnake->GetNext()->GetPOS_X() && head_tpm->GetPOS_Y() == browsesnake->GetNext()->GetPOS_Y()){
            return 1;
            break;
        }
        browsesnake = browsesnake->GetNext();
    }
    return 0;
}

Segment * Snake::GetHead(){
    return this->head;
}

int keyboard(int dir) {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        dir = UP;
        }
    if (keystates[SDL_SCANCODE_DOWN]){
        dir = DOWN;
    }
    if (keystates[SDL_SCANCODE_LEFT]){
        dir = LEFT;
    }
    if (keystates[SDL_SCANCODE_RIGHT]){
        dir = RIGHT;
    }
    return dir;
}

void Snake::Eat(){
    Segment * browsesnake = this->head;
    while (browsesnake->next != NULL){
        browsesnake = browsesnake->next;
    }
    int lastposx = browsesnake->GetPOS_X();
    int lastposy = browsesnake->GetPOS_Y();
    int lastdir = browsesnake->GetDir();
    switch(lastdir){
        case UP:
        lastposy += 20;
        break;

        case DOWN:
        lastposy -= 20;
        break;

        case LEFT:
        lastposx += 20;
        break;

        case RIGHT:
        lastposx -=20;
        break;
    } 
    Segment * last_segment = new Segment(lastposx,lastposy,lastdir);
    browsesnake->next = last_segment;
}

void Snake::Move(){
    int pos_x, pos_y;
    Segment * old_head = this->head;

    pos_x = old_head->GetPOS_X();
    pos_y = old_head->GetPOS_Y();
    int new_dir = keyboard(this->head->GetDir());
    if(new_dir != - this->head->GetDir()){
        this->head->SetDir(new_dir);
    }
    switch(new_dir){
        case UP:
        pos_y -= 20;
        break;

        case DOWN:
        pos_y += 20;
        break;

        case LEFT:
        pos_x -= 20;
        break;

        case RIGHT:
        pos_x +=20;
        break;
    }
    
    this->head = new Segment(pos_x, pos_y, new_dir); 
    this->head->SetNext(old_head);

    Segment * cur_head = this->head;
    while(cur_head->GetNext()->GetNext() != NULL) {
        cur_head = cur_head->GetNext();
    }
    cur_head->SetNext(NULL);
}
