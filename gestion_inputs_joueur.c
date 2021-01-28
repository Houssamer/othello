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


void gestion_inputs_Joueur(SDL_Event *event, bool *quit, int *positionX, int position[10][10][3], int *positionY,
                           int *pion, int pions[10][10], int *Joueur, int *scoreBlanc, int *scoreNoir) {


    while (SDL_WaitEvent(event)) {
        switch (event->type) {
            case SDL_QUIT:
                *quit = true;
                break;
                //quelque basiques entrees pour gerer l'interface
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
                    default:
                        printf("Wrong key\n");
                        break;
                }
            //partie de la gestion de la souris aussi que la logique du jeu

            case SDL_MOUSEBUTTONDOWN:
                    if (event->button.button == SDL_BUTTON_LEFT) {
                       double x = event->button.x;
                       double y = event->button.y;
                       int ligne = 1;
                       int colonne = 1;

                        //la gestion des collision avec les bordures de l'othellier
                        if (x < 80 || x > 560 || y < 80 || y > 560) {
                            printf("erreur, vous etes hors du plateau othellier\n");
                        }
                        else {
                                ligne = floor(y/60);
                                colonne = floor(x/60);
                            switch (colonne) {
                                case 1:
                                    *positionX = 80;
                                    break;
                                case 2:
                                    *positionX = 140;
                                    break;
                                case 3:
                                    *positionX = 200;
                                    break;
                                case 4:
                                    *positionX = 260;
                                    break;
                                case (int) 5:
                                    *positionX = 320;
                                    break;
                                case 6:
                                    *positionX = 380;
                                    break;
                                case 7:
                                    *positionX = 440;
                                    break;
                                case 8:
                                    *positionX = 500;
                                    break;
                            }
                        switch (ligne) {
                            case 1:
                                *positionY = 80;
                                break;
                            case 2:
                                *positionY = 140;
                                break;
                            case 3:
                                *positionY = 200;
                                break;
                            case 4:
                                *positionY = 260;
                                break;
                            case 5:
                                *positionY = 320;
                                break;
                            case 6:
                                *positionY = 380;
                                break;
                            case 7:
                                *positionY = 440;
                                break;
                            case 8:
                                *positionY = 500;
                                break;
                        }
                        position[ligne][colonne][0] = *positionX;
                        position[ligne][colonne][1] = *positionY;
                        if (vide(ligne, colonne, pions)) {
                            Joueur_Verification(Joueur, pion);
                            posPion(*positionX, *positionY, ligne, colonne, pions, *pion, scoreBlanc, scoreNoir);
                            pion_Update(ligne, colonne, pions, *pion, scoreBlanc, scoreNoir);
                        }
                        if (jeuTermine(pions)) {
                            showGagnant(*scoreBlanc, *scoreNoir);
                        }

                    }

                }
                break;
        }
    }
}
