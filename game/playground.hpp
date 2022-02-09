#include <SDL2/SDL.h>
#include "snake.hpp"
using namespace std;
class Playground {
    private:
        Snake * litsnake;
        Segment * fruit;
        int score;
        int nbcol;
        int nbrow;

    public:
        Playground(int nbrow, int nbcol);
        ~Playground();
        Snake * GetSnake();
        int Collide();
        int GetScore();
        void MeetFruit();
        void GenerateFruit();
        void init(int dir);
        int fruit_pos_x = 25;
        int fruit_pos_y = 0;
        int verif_MeetFruit();
};