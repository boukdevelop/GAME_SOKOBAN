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

    int winH, winW;
    SDL_Window *window = SDL_CreateWindow(
        "SOKOBAN - GAME",
        800,
        600,
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
        }

        // Rendu Graphique
        SDL_SetRenderDrawColor(renderer, 100, 95, 90, 255);
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}