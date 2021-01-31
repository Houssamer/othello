#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "prototypes.h"
#include "structures.h"
#include "def.h"
#include <stdbool.h>
#include <math.h>


#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>


void gestion_inputs_machine(SDL_Event *event, bool *quit, int *joueur, int *positionX, int *positionY,
                            int position[10][10][3], int pions[10][10], int *scoreBlanc,int *scoreNoir) {

    //initialiser les textures necessaire pour les interfaces et les pions
    SDL_Texture *texture;
    SDL_Texture *pionNoir = loadImage("./graphiques/PionNoir.png");
    SDL_Texture *pionBlanc = loadImage("./graphiques/PionBlanc.png");
    SDL_Rect dimension = {0, 0, 640, 640};
    SDL_Rect dimensionPion1 = {260, 260, PION_WIDTH, PION_HEIGHT};
    SDL_Rect dimensionPion2 = {320, 320, PION_WIDTH, PION_HEIGHT};
    SDL_Rect dimensionPion3 = {260, 320, PION_WIDTH, PION_HEIGHT};
    SDL_Rect dimensionPion4 = {320, 260, PION_WIDTH, PION_HEIGHT};

    while (SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_QUIT:
                *quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event->key.keysym.sym) {
                    case SDLK_ESCAPE:
                        start(quit);
                        break;
                    case SDLK_0:
                        stopMusic();
                        break;
                    case SDLK_KP_0:
                        stopMusic();
                        break;
                    case SDLK_1:
                        playMusic();
                        break;
                    case SDLK_KP_1:
                        playMusic();
                        break;
                    case SDLK_b :
                        texture = loadImage("./graphiques/othellierM.png");

                        SDL_RenderCopy(getrenderer(), texture, NULL, &dimension);
                        //ajouter les quatres pions initials

                        SDL_RenderCopy(getrenderer(), pionNoir, NULL, &dimensionPion1);
                        SDL_RenderCopy(getrenderer(), pionNoir, NULL, &dimensionPion2);
                        SDL_RenderCopy(getrenderer(), pionBlanc, NULL, &dimensionPion3);
                        SDL_RenderCopy(getrenderer(), pionBlanc, NULL, &dimensionPion4);

                        SDL_DestroyTexture(pionNoir);
                        SDL_DestroyTexture(pionBlanc);

                        //affichage de l'image sur la fenetre
                        SDL_RenderPresent(getrenderer());

                        //supprimer la texture pour conserver la memoire
                        SDL_DestroyTexture(texture);

                        //joueur blanc et machine noir

                        *joueur = BLANC;
                        MachineNoir(positionX, positionY, position, pions, scoreBlanc, scoreNoir, joueur, quit, event);
                        break;
                    case SDLK_n :
                        texture = loadImage("./graphiques/othellierM.png");

                        SDL_RenderCopy(getrenderer(), texture, NULL, &dimension);
                        //ajouter les quatres pions initials

                        SDL_RenderCopy(getrenderer(), pionNoir, NULL, &dimensionPion1);
                        SDL_RenderCopy(getrenderer(), pionNoir, NULL, &dimensionPion2);
                        SDL_RenderCopy(getrenderer(), pionBlanc, NULL, &dimensionPion3);
                        SDL_RenderCopy(getrenderer(), pionBlanc, NULL, &dimensionPion4);

                        SDL_DestroyTexture(pionNoir);
                        SDL_DestroyTexture(pionBlanc);
                        //affichage de l'image sur la fenetre
                        SDL_RenderPresent(getrenderer());

                        //supprimer la texture pour conserver la memoire
                        SDL_DestroyTexture(texture);

                        //joueur noir et machine blanc

                        *joueur = NOIR;
                        MachineBlanc(positionX, positionY, position, pions, scoreBlanc, scoreNoir, joueur, quit, event);
                        break;
                    default:
                        printf("Wrong key\n");
                        break;
                }
    }
}
}
