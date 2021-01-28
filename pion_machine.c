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

void pion_machine(int pionMachine, int pions[10][10], int *scoreBlanc, int *scoreNoir) {

    int bestScore = 0;
    bestPosition bestmove;

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (vide(i, j, pions)) {
                int currentScore = 0;
                pions[i][j] = pionMachine;

                //sous_dessous du pion
                for (int l = i+1; l <= 8; l++) {
                    if (!vide(l, j, pions)){
                        if (pions[l][j] == pionMachine) {
                            for (int k = l; k >= i+1; k--) {
                                currentScore++;
                            }
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }

                //au_dessus du pion
                for (int l = i-1; l >= 1; l--) {
                    if (!vide(l, j, pions)) {
                        if (pions[l][j] == pionMachine) {
                            for (int k = l; k <= i-1; k++) {
                                currentScore++;
                            }
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }

                //a droite du pion
                for (int c = j+1; c <= 8; c++) {
                    if (!vide(i, c, pions)) {
                        if (pions[i][c] == pionMachine) {
                            for (int k = c; k >= j + 1; k--) {
                                currentScore++;
                            }
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }

                //a gauche du pion
                for (int c = j-1; c >= 1; c--) {
                    if (!vide(i, c, pions)) {
                        if (pions[i][c] == pionMachine) {
                            for (int k = c; k <= j-1; k++) {
                                currentScore++;
                            }
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }

                //diagonale a droite haute
                for (int l = 1; l <= 9; l++) {
                    if ((i + l <= 8) && (j + l <= 8)) {
                        int L = i+l;
                        int C = j+l;
                        if (!vide(L, C, pions)) {
                            if (pions[L][C] == pionMachine) {
                                for (int k = 1; k < l; k++) {
                                    L--;
                                    C--;
                                    currentScore++;
                                }
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }

                //diagonale a droite bas
                for (int l = 1; l <= 9; l++) {
                    if ((i - l <= 8 && i - l > 0) && (j + l <= 8)) {
                        int L = i-l;
                        int C = j+l;
                        if (!vide(L, C, pions)) {
                            if (pions[L][C] == pionMachine) {
                                for (int k = 1; k < l; k++) {
                                    L++;
                                    C--;
                                    currentScore++;
                                }
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }

                //diagonale a gauche haut
                for (int l = 1; l <= 9; l++) {
                    if ((i + l <= 8) && (j - l <= 8 && j - l > 0)) {
                        int L = i+l;
                        int C = j-l;
                        if (!vide(L, C, pions)) {
                            if (pions[L][C] == pionMachine) {
                                for (int k = 1; k < l; k++) {
                                    L--;
                                    C++;
                                    currentScore++;
                                }
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }

                //diagonale a gauche bas
                for (int l = 1; l <= 9; l++) {
                    if ((i-l<=8 && i-l>0) && (j-l<=8 && j-l>0)) {
                        int L = i-l;
                        int C = j-l;
                        if (!vide(L, C, pions)) {
                            if (pions[L][C] == pionMachine) {
                                for (int k = 1; k < l; k++) {
                                    L++;
                                    C++;
                                    currentScore++;
                                }
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
                if (bestScore < currentScore) {
                    bestScore = currentScore;
                    bestmove.ligne = i;
                    bestmove.colonne = j;
                    }
                pions[i][j] = 0;

            }

        }
    }


    int positionY = bestmove.ligne*60 +20;
    int positionX = bestmove.colonne*60 +20;
    posPion(positionX, positionY, bestmove.ligne, bestmove.colonne, pions, pionMachine, scoreBlanc, scoreNoir);
    pion_Update(bestmove.ligne, bestmove.colonne, pions, pionMachine, scoreBlanc, scoreNoir);
}
