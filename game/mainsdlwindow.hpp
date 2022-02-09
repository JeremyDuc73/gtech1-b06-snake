#include <SDL2/SDL.h>
using namespace std;

class MainSDLWindow {
public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char *name, int largeur, int hauteur);
    SDL_Renderer * GetRenderer(void);
    void clean();
private:
    SDL_Window * window;
    SDL_Renderer * renderer; 
}; 