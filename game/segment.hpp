using namespace std;
#include <iostream>
#include <stdio.h>
class Segment {
    private :
        int pos_x;
        int pos_y;
        int dir;
    public :
        Segment(int pos_x, int pos_y, int dir);
        ~Segment();
        Segment * next;
        int GetPOS_X(void);
        int GetPOS_Y(void);
        int GetDir(void);
        Segment * GetNext(void);
        void SetDir(int dir);
        void SetPOS_X(int pos_x);
        void SetPOS_Y(int pos_y);
        void SetNext(Segment * next);
};