#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
// #include <SDL3_mixer/SDL_mixer.h>
#include <iostream>

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

    while (run)
    {
        // Gestion des éléments
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                run = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE)
            {
                run = false;
                std::cout << "Sortie par la touche 'ESCAPE'." << std::endl;
            }
            if (event.type == SDL_WINDOW_RESIZABLE)
            {
                winW = event.window.data1;
                winH = event.window.data2;
            }
        }

        // Rendu Graphique
        SDL_SetRenderDrawColor(renderer, 100, 200, 90, 255);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}