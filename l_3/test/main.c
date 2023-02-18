Voici un exemple simple de jeu de plateforme en utilisant la bibliothèque SDL2:

scss
Copy code
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 480
#define GRAVITY 0.5

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Platformer");

    float x = WIDTH / 2;
    float y = HEIGHT - 50;
    float yVelocity = 0;
    bool onGround = false;

    while (true) {
        // Gestion des entrées
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                goto cleanup;
            }
        }

        const Uint8* state = SDL_GetKeyboardState(NULL);
        if (state[SDL_SCANCODE_LEFT]) {
            x -= 3;
        }
        if (state[SDL_SCANCODE_RIGHT]) {
            x += 3;
        }
        if (state[SDL_SCANCODE_UP] && onGround) {
            yVelocity = -10;
            onGround = false;
        }

        // Mettre à jour la position du joueur en fonction de la gravité
        yVelocity += GRAVITY;
        y += yVelocity;
        if (y > HEIGHT - 50) {
            y = HEIGHT - 50;
            yVelocity = 0;
            onGround = true;
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dessiner le joueur
        SDL_Rect player = {(int) x - 25, (int) y - 50, 50, 50};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &player);

        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);
    }

cleanup:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
Ce code initialise SDL, crée une fenêtre et un renderer, gère les entrées utilisateur, met à jour la position du joueur en fonction de la gravité et dessine le joueur dans la fenêtre à chaque tour de boucle. Notez que ce code n'inclut pas la gestion des collisions ou la dessin des plates-formes, mais il peut être utilisé comme base pour développer un jeu de plateforme plus complet.




papaku@mailfence.com
peut tu maintenant le diviser en plusieur exercisse avec intituler afin que je puisse apprendre a le faire petit a petit
Bien sûr, voici une division en plusieurs étapes pour comprendre la construction d'un jeu de plateforme simple en utilisant SDL2 :

Initialisation de SDL et création de la fenêtre et du renderer
c
Copy code
#include <SDL2/SDL.h>
#include <stdbool.h>

#define WIDTH 640
#define HEIGHT 480

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    // Initialisation de SDL et création de la fenêtre et du renderer
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Platformer");
}
Gestion des entrées utilisateur
scss
Copy code
while (true) {
    // Gestion des entrées
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            goto cleanup;
        }
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT]) {
        // Code pour déplacer le joueur vers la gauche
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        // Code pour déplacer le joueur vers la droite
    }
    if (state[SDL_SCANCODE_UP]) {
        // Code pour faire sauter le joueur
    }
}
Mise à jour de la position du joueur en fonction de la gravité
c
Copy code
#define GRAVITY 0.5

float x = WIDTH / 2;
float y = HEIGHT - 50;
float yVelocity = 0;
bool onGround = false;

while (true) {
    // ... gestion des entrées ...

    // Mettre à jour la position du joueur en fonction de la gravité
    yVelocity += GRAVITY;
    y += yVelocity;
    if (y > HEIGHT - 50) {
        y = HEIGHT - 50;
        yVelocity = 0;
        onGround = true;
    }
}
Effacer l'écran et dessiner le joueur
scss
Copy code
while (true) {
    // ... gestion des entrées ...
    // ... mise à jour de la position du joueur ...

    // Effacer l'écran
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Dessiner le joueur
    SDL_Rect player = {(int) x - 25, (int) y - 50, 50, 50};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &player);

    //
