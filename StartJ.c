#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "prototypes.h"
#include "structures.h"
#include "def.h"
#include <stdbool.h>


#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>


void startJ(SDL_Renderer *renderer) {
    //telechargement de l'image
    SDL_Texture *texture = loadImage("./graphiques/othellier.png");
    SDL_Rect dimension = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT}; //dimension de l'image

    SDL_RenderCopy(renderer, texture, NULL, &dimension);



    //supprimer la texture pour conserver la memoire
    SDL_DestroyTexture(texture);
    SDL_RenderCopy(renderer, NULL, NULL, NULL);

    //ajouter les quatres pions initials
    SDL_Texture *pionNoir = loadImage("./graphiques/PionNoir.png");
    SDL_Texture *pionBlanc = loadImage("./graphiques/PionBlanc.png");

    SDL_Rect dimensionPion1 = {260, 260, PION_WIDTH, PION_HEIGHT};
    SDL_Rect dimensionPion2 = {320, 320, PION_WIDTH, PION_HEIGHT};
    SDL_Rect dimensionPion3 = {260, 320, PION_WIDTH, PION_HEIGHT};
    SDL_Rect dimensionPion4 = {320, 260, PION_WIDTH, PION_HEIGHT};

    SDL_RenderCopy(renderer, pionNoir, NULL, &dimensionPion1);
    SDL_RenderCopy(renderer, pionNoir, NULL, &dimensionPion2);
    SDL_RenderCopy(renderer, pionBlanc, NULL, &dimensionPion3);
    SDL_RenderCopy(renderer, pionBlanc, NULL, &dimensionPion4);

    SDL_DestroyTexture(pionNoir);
    SDL_DestroyTexture(pionBlanc);

    //affichage de l'image sur la fenetre
    SDL_RenderPresent(renderer);

}
