#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "prototypes.h"
#include "structures.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

void JoueurVsJoueur(bool *quit) {


    //quelques variable importantes pour le fonctionnement

    int positionX;
    int positionY;
    int position[10][10][3];
    int pion = NOIR;
    int pions[10][10] = {0};
    pions[4][4] = NOIR;
    pions[5][5] = NOIR;
    pions[4][5] = BLANC;
    pions[5][4] = BLANC;
    int Joueur = 1;
    int scoreNoir = 2;
    int scoreBlanc = 2;

    //lancemanet de la fenetre

    startJ(getrenderer());


    //la fonction qui gere la memoire


    SDL_Event event;

    //la boucle de fonctionnement
    while (!(*quit)) {

        //faire appelle a la focntion qui gere les entrees aussi que la logique du jeu
        gestion_inputs_Joueur(&event, quit, &positionX, position, &positionY, &pion, pions, &Joueur, &scoreBlanc, &scoreNoir);

   }

}
