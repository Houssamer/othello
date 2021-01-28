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


void startM(SDL_Renderer *renderer) {
        //telechargement de l'image

    //l'interface pour permettre au joueur de choisir la coulour

    SDL_Texture *textureChoix = loadImage("./graphiques/ChoixColor.png");
    SDL_Rect dim = {0, 0, 640, 640};

    SDL_RenderCopy(renderer, textureChoix, NULL, &dim);
    SDL_DestroyTexture(textureChoix);

    SDL_RenderPresent(renderer);

}
