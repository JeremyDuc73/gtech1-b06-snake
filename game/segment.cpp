#include "segment.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;

Segment::Segment(int pos_x, int pos_y, int dir){
    this->pos_x=pos_x;
    this->pos_y=pos_y;
    this->dir=dir;
    this->next=NULL;
}

Segment::~Segment(void){
}

int Segment::GetPOS_X(void){
    return this->pos_x;

}

int Segment::GetPOS_Y(void){
    return this->pos_y;
}

int Segment::GetDir(void){
    return this->dir;
}

Segment * Segment::GetNext(void){
    return this->next;
}

void Segment::SetDir(int dir_){
    this->dir = dir_;
}

void Segment::SetPOS_X(int pos_x_){
    this->pos_x = pos_x_;
}

void Segment::SetPOS_Y(int pos_y_){
    this->pos_y = pos_y_;
}
void Segment::SetNext(Segment* next){
    this->next = next;
}