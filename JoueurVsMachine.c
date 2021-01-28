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

void JoueurVsMachine(bool *quit) {
    //lancement de la fenetre
    int joueur;
    int positionX;
    int positionY;
    int position[10][10][3];
    int pions[10][10] = {0};
    pions[4][4] = NOIR;
    pions[5][5] = NOIR;
    pions[4][5] = BLANC;
    pions[5][4] = BLANC;
    int scoreNoir = 2;
    int scoreBlanc = 2;

    SDL_Event event;

    startM(getrenderer());


    //la boucle de fonctionnement
    while (!(*quit)) {

        //faire appelle a la focntion qui gere les entrees aussi que la logique du jeu
        gestion_inputs_machine(&event, quit, &joueur, &positionX, &positionY, position, pions, &scoreBlanc, &scoreNoir);


   }

}
