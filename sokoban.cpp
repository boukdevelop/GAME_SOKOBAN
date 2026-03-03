#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
// #include <SDL3_mixer/SDL_mixer.h>
#include <iostream>

// https : // youtu.be/1NLGd32iVY0?si=tVI055A-N2LR5YMG

int main(int argc, char *argv[])
{

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "Erreur lors de l'initialisation de la fenêtre : " << SDL_GetError();
        return 1;
    }

    int winW = 800, winH = 600;
    SDL_Window *window = SDL_CreateWindow(
        "SOKOBAN - GAME",
        winW,
        winH,
        SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    SDL_Event event;
    bool run = true;

    // Creation du personnage
    SDL_FRect play{300.0f, 200.0f, 70.0f, 70.0f};
    float speed = 5.0f;       // Vitesse de deplacement
    bool Isfollowing = false; // Vérifit si le rect suit la souris

    while (run)
    {
        // Gestion des éléments
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                run = false;
            if (event.type == SDL_WINDOW_RESIZABLE)
            {
                winW = event.window.data1;
                winH = event.window.data2;
            }

            // Gestion des mouvements du rectangle
            if (event.type == SDL_EVENT_KEY_DOWN)
            {
                switch (event.key.scancode)
                {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                {
                    play.y -= speed;
                    break;
                }
                case SDL_SCANCODE_Z:
                case SDL_SCANCODE_DOWN:
                {
                    play.y += speed;
                    break;
                }
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                {
                    play.x -= speed;
                    break;
                }
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                {
                    play.x += speed;
                    break;
                }
                case SDL_SCANCODE_ESCAPE:
                {
                    run = false;
                    std::cout << "Sortie par la touche 'ESCAPE'.";
                    break;
                }
                default:
                    break;
                }
            }

            // Gestion du rectangle par le motion du curseur (Glisser le rectangle)
        }

        // Rendu Graphique
        SDL_SetRenderDrawColor(renderer, 100, 200, 90, 255);
        SDL_RenderClear(renderer);

        // Rendu du rectangle
        SDL_SetRenderDrawColor(renderer, 200, 100, 99, 255);
        SDL_RenderFillRect(renderer, &play);

        // Présentation du graphique
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}