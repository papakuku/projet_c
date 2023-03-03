#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TILE_SIZE = 32;
const int PLAYER_WIDTH = 32;
const int PLAYER_HEIGHT = 64;
const int MAX_JUMP_HEIGHT = 128;
const int GRAVITY = 8;

typedef struct {
    int x, y, vx, vy;
    bool isOnGround;
} Player;

void handleInput(Player* player) {
    const Uint8* state = SDL_GetKeyboardState(NULL);
    player->vx = (state[SDL_SCANCODE_LEFT] - state[SDL_SCANCODE_RIGHT]) * 4;
    if (state[SDL_SCANCODE_SPACE] && player->isOnGround) {
        player->isOnGround = false;
        player->vy = -MAX_JUMP_HEIGHT;
    }
}

void updatePlayer(Player* player) {
    player->vy += GRAVITY;
    player->x += player->vx;
    player->y += player->vy;
    player->isOnGround = false;
}

void handleCollisions(Player* player, int level[], int levelWidth, int levelHeight) {
    int playerLeft = player->x;
    int playerRight = player->x + PLAYER_WIDTH;
    int playerTop = player->y;
    int playerBottom = player->y + PLAYER_HEIGHT;
    int tileLeft, tileRight, tileTop, tileBottom;
    for (int y = 0; y < levelHeight; y++) {
        for (int x = 0; x < levelWidth; x++) {
            if (level[y * levelWidth + x] != 0) {
                tileLeft = x * TILE_SIZE;
                tileRight = (x + 1) * TILE_SIZE;
                tileTop = y * TILE_SIZE;
                tileBottom = (y + 1) * TILE_SIZE;
                if (playerRight > tileLeft && playerLeft < tileRight && playerBottom > tileTop && playerTop < tileBottom) {
                    if (player->vy > 0) {
                        player->y = tileTop - PLAYER_HEIGHT;
                        player->vy = 0;
                        player->isOnGround = true;
                    }
                    else if (player->vy < 0) {
                        player->y = tileBottom;
                        player->vy = 0;
                    }
                }
            }
        }
    }
}





int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Jeu de plateforme", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* playerSurface = SDL_LoadBMP("player.bmp");
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
    SDL_FreeSurface(playerSurface);
    SDL_Surface* tileSurface = SDL_LoadBMP("tile.bmp");
    SDL_Texture* tileTexture = SDL_CreateTextureFromSurface(renderer, tileSurface);
    SDL_FreeSurface(tileSurface);

    int level[] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 
    
    };

    const int levelWidth = 11;
    const int levelHeight = 3;
    Player player = { 0, 0, 0, 0, false };

    bool quit = false;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        handleInput(&player);
        updatePlayer(&player);
        handleCollisions(&player, level, levelWidth, levelHeight);

        SDL_RenderClear(renderer);
        for (int y = 0; y < levelHeight; y++) {
            for (int x = 0; x < levelWidth; x++) {
                if (level[y * levelWidth + x] != 0) {
                    SDL_Rect tileRect = { x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE };
                    SDL_RenderCopy(renderer, tileTexture, NULL, &tileRect);
                }
            }
        }
        SDL_Rect playerRect = { player.x, player.y, PLAYER_WIDTH, PLAYER_HEIGHT };
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(playerTexture);
    SDL_DestroyTexture(tileTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}