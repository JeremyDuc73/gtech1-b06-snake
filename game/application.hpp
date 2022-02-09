#include <SDL2/SDL.h>
#include "playground.hpp"
#include "mainsdlwindow.hpp"
using namespace std;
class Application {
    private:
        MainSDLWindow * win;
        Playground * pg;
        Uint32 frame_rate_ms;
    public:
        Application();
        ~Application();
        void draw_fruit();
        void draw_snake();

};