#include "segment.hpp"
using namespace std;
class Snake {
    private:
        Segment * head = NULL;
        Segment * tail = NULL;
    public:
        Snake(int pos_x, int pos_y, int dir);
        ~Snake();
        Segment * GetHead();
        int Collide();
        void Keyboard();
        void Move();
        void Eat();
        
};