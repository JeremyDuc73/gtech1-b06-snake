#include <SDL2/SDL.h>
#include "direction.h"
#include "playground.hpp"
using namespace std;

Playground::Playground(int nbrow ,int nbcol){

    this->nbcol = nbcol;
    this->nbrow = nbrow;
    this->litsnake = new Snake(nbcol/2,nbrow/2,RIGHT);
    this->score = 0;
}

Playground::~Playground(){
}

Snake * Playground::GetSnake(){
    return this->litsnake;
}

void Playground::GenerateFruit(void){

    fruit_pos_x =  (rand() %  (this->nbcol-40)/20)*20;
    fruit_pos_y =  (rand() % (this->nbrow-40)/20)*20;

    Segment * browsnake = this->litsnake->GetHead();

    while (browsnake!= NULL){

        if(browsnake->GetPOS_X()== fruit_pos_x && browsnake->GetPOS_Y()== fruit_pos_y ){
            
            fruit_pos_x = (rand() %  (this->nbcol-PAS)/PAS)*PAS;
            fruit_pos_y = (rand() % (this->nbrow-PAS)/PAS)*PAS ;

        }else{

            browsnake= browsnake->next;

        }
    }       

    this->fruit = new Segment(fruit_pos_x,fruit_pos_y,DOWN);
}


int Playground::Collide(){
    Segment * head_tpm = this->litsnake->GetHead() ;
    
    if ( head_tpm->GetPOS_X()<0 || head_tpm->GetPOS_Y()<0 || head_tpm->GetPOS_X()> this->nbcol-PAS || head_tpm->GetPOS_Y()> this->nbrow-PAS ){
        return 1;
    }
    return 0;
}

int Playground::GetScore(){
    return this->score;
}

void Playground::MeetFruit(){

    this->score = score + 10;
    this->litsnake->Eat();
    delete this->fruit;
    GenerateFruit();

}
int Playground::verif_MeetFruit(){

    int snake_x = this->litsnake->GetHead()->GetPOS_X();
    int snake_y = this->litsnake->GetHead()->GetPOS_Y();
    int fruit_x = this->fruit->GetPOS_X();
    int fruit_y = this->fruit->GetPOS_Y();

    if( snake_x == fruit_x && snake_y == fruit_y){
 
        return 1;

    }
    return 0;
}


