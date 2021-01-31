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

void score(int pion, int *scoreBlanc, int *scoreNoir) { //changer le score de chaque joueur
    if (pion == NOIR) {
        (*scoreBlanc)--;
    }
    else {
        (*scoreNoir)--;
    }
}

bool vide(const int ligne, const int colonne, const int pions[10][10]) { //verifier si les cases sont vides ou non
    if (pions[ligne][colonne] == NOIR || pions[ligne][colonne] == BLANC) {
        return false;
    }
    else {
        return true;
    }
}

void Joueur_Verification(int *joueur, int *pion) { //verifier le joueur qui doit jouer
    if ((*joueur) == 1) {
        (*pion) = NOIR;
        (*joueur) = 2;
    }
    else if ((*joueur) == 2) {
        (*pion) = BLANC;
        (*joueur) = 1;
    }
}

 void posPion(const int positionX, const int positionY, const int ligne, const int colonne, int pions[10][10], const int pion, int *scoreBlanc, int *scoreNoir) {
    SDL_Texture *texture;
    if (pion == NOIR) {
        texture = loadImage("./graphiques/PionNoir.png");
        SDL_Rect dimension = {positionX, positionY, PION_WIDTH, PION_HEIGHT}; //dimension de chaque Pion et la position
        pions[ligne][colonne] = pion;
        SDL_RenderCopy(getrenderer(), texture, NULL, &dimension);

        SDL_DestroyTexture(texture);
        SDL_RenderCopy(getrenderer(), NULL, NULL, NULL);
        (*scoreNoir)++;
    }
    else if (pion == BLANC) {
        texture = loadImage("./graphiques/PionBlanc.png");
        SDL_Rect dimension = {positionX, positionY, PION_WIDTH, PION_HEIGHT}; //dimension de chaque Pion et la position
        pions[ligne][colonne] = pion;
        SDL_RenderCopy(getrenderer(), texture, NULL, &dimension);

        SDL_DestroyTexture(texture);
        SDL_RenderCopy(getrenderer(), NULL, NULL, NULL);
        (*scoreBlanc)++;
    }

    SDL_RenderPresent(getrenderer());

}

void pion_Update(const int ligne, const int colonne, int pions[10][10], const int pion, int *scoreBlanc, int *scoreNoir) {
    for (int i = ligne + 1; i <= 8; i++) {  //parcourir les cases sous-dessous pour identifier le premier pion de la meme coulour
        if (!vide(i, colonne, pions)) {  //verifier si les cases entres les deux pions ne sont pas vides
            if (pions[i][colonne] == pion) {
                for (int j = i; j >= ligne + 1; j--) {
                    int X = colonne*60 + 20;
                    int Y = j*60 + 20;
                    posPion(X, Y, j, colonne, pions, pion, scoreBlanc, scoreNoir); //changer les pions par la coulour de pion joueur
                    score(pion, scoreBlanc, scoreNoir);  //changemet de score pour le joueur et l'adversaire
                }
                break;
            }
        }
        else {
            break;
        }
    }
    for (int i = colonne + 1; i <= 8; i++) {  //parcourir les cases a gauche de pion
        if (!vide(ligne, i, pions)) { //verifier si les cases ne sont pas vides
            if (pions[ligne][i] == pion) {
                for (int j = i; j >= colonne + 1; j--) {
                    int X = j*60 + 20;
                    int Y = ligne*60 + 20;
                    posPion(X, Y, ligne, j, pions, pion, scoreBlanc, scoreNoir);  //changer les pions par la coulour de pion joueur
                    score(pion, scoreBlanc, scoreNoir); //changement de score pour le joueur et l'adversaire
                }
                break;
            }
        }
        else {
            break;
        }
    }
     if (ligne > 0) {  //verifier si le pion n'est pas a cote de bordure de l'othellier
        for (int i = ligne - 1; i >= 1; i--) {  //parcourir les cases au-dessus du pion
            if (!vide(i, colonne, pions)) { //verifier si les cases ne sont pas vides
                if (pions[i][colonne] == pion) {
                    for (int j = i; j <= ligne - 1; j++) {
                        int X = colonne*60 +20;
                        int Y = j*60 +20;
                        posPion(X, Y, j, colonne, pions, pion, scoreBlanc, scoreNoir); //changer les pions par la coulour de pion joueur
                        score(pion, scoreBlanc, scoreNoir); //changement de score pour le joueur et l'adversaire
                    }
                    break;
                }
            }
            else {
                break;
            }
        }
        for (int i = 1; i <=9; i++) { //parcourir les cases en diagonale a droite et sous-dessous
            if ((ligne - i > 0) && colonne + i <= 8) { //verifier si les deplacements ne sont pas au dela des bordures
                int L = ligne - i;
                int C = colonne + i;
                if (!vide(L, C, pions)) { //verifier si les cases ne sont pas vides
                    if (pions[L][C] == pion) {
                        for (int j = 1; j < i; j++) {
                            L ++;
                            C --;
                            int X = C*60 +20;
                            int Y = L*60 +20;
                            posPion(X, Y, L, C, pions, pion, scoreBlanc, scoreNoir); //changer les pions par la coulour de pion de joueur
                            score(pion, scoreBlanc, scoreNoir); //changement de score de joueur et de l'adversaire
                        }
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
    }
    if (colonne > 0) { //verifier si le pion n'est pas a cote de bordure de l'othellier
        for (int i = colonne - 1; i >= 1; i--) { //parcourir les cases a droite du pion
            if (!vide(ligne, i, pions)) { //verifier si les cases ne sont pas vides
                if (pions[ligne][i] == pion) {
                    for (int j = i; j <= colonne - 1; j++) {
                        int X = j*60 +20;
                        int Y = ligne*60 +20;
                        posPion(X, Y, ligne, j, pions, pion, scoreBlanc, scoreNoir); //changer les pions par la coulour de pion joueur
                        score(pion, scoreBlanc, scoreNoir); //changement de score pour le joueur et l'adversaire
                    }
                    break;
                }
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= 9; i++) { //parcourir les cases en diagonale a gauche au-dessus
            if ((colonne-i >0) && ligne + i <= 8) { //verifier si les deplacements sont possibles
                int L = ligne + i;
                int C = colonne - i;
                if (!vide(L, C, pions)) { //verifier si les cases ne sont pas vides
                    if (pions[L][C] == pion) {
                        for (int j = 1; j < i; j++) {
                            L--;
                            C++;
                            int X = C*60 +20;
                            int Y = L*60 +20;
                            posPion(X, Y, L, C, pions, pion, scoreBlanc, scoreNoir); //changer les pions par la coulour de pion joueur
                            score(pion, scoreBlanc, scoreNoir);//changement de score pour le joueur et l'adversaire
                        }
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }

    }
    for (int i = 1; i <= 9; i++) { //parcourir les cases en diagonales a droite au-dessus
        if (ligne + i <= 8 && colonne + i <= 8) { //verifier si les deplacements sont disponible
            int L = ligne + i;
            int C = colonne + i;
            if (!vide(L,C, pions)) {
                if (pions[L][C] == pion) { //verifier si les cases ne sont pas vides
                    for (int j = 1; j < i; j++) {
                        L --;
                        C --;
                        int X = C*60 +20;
                        int Y = L*60 +20;
                        posPion(X, Y, L, C, pions, pion, scoreBlanc, scoreNoir); //changer les pions par la coulour de pion joueur
                        score(pion, scoreBlanc, scoreNoir);//changement de score pour le joueur et l'adversaire
                    }
                    break;
                }
            }
            else {
                break;
            }
        }
    }

    if (colonne > 0 && ligne > 0) {
        for (int i=1; i <= 9; i++) { //parcourir les cases diagonales a gauche sous-dessous
            if ((ligne-i >0) && (colonne-i >0)) { //verifier si les deplacements sont possibles
                int L = ligne - i;
                int C = colonne - i;
                if (!vide(L, C, pions)) { //verifier si les cases ne sont pas vides
                    if (pions[L][C] == pion) {
                        for (int j = 1; j < i; j++) {
                            L++;
                            C++;
                            int X = C*60 +20;
                            int Y = L*60 +20;
                            posPion(X, Y, L, C, pions, pion, scoreBlanc, scoreNoir); //changer les pions par le pion joueur
                            score(pion, scoreBlanc, scoreNoir);//changement de score de joueur et de l'adversaire
                        }
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
    }

}


bool jeuTermine(int pions[10][10]) { // verifier si l'othellier est remplie ou non pour declarer le gagnant
    bool termine = false;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (pions[i][j] != 0) {
                termine = true;
            }
            else {
                termine = false;
                return termine;
            }
        }
    }
    return  termine;
}

void showGagnant (int scoreBlanc, int scoreNoir, bool *quit) { //afficher le joueur gagnant

    TTF_Font *font = TTF_OpenFont("./fonts/PTN77F.ttf", 85); //le genre et la taille de la police utilise

    SDL_Color color = {255, 255, 255};  //la coulour utilise pour l'ecriture (la coulour rouge)

    SDL_Rect dimension = {0, 0, 640, 80};

    if (scoreBlanc > scoreNoir) {

        SDL_Surface *surfaceBlanc = TTF_RenderText_Solid(font ," BLANC,  Vous avez gagne. Felicitation", color);//le texte a afficher si le
        SDL_Texture *textureBlanc = SDL_CreateTextureFromSurface(getrenderer(), surfaceBlanc);                 //joueur 2 est gagnant
        SDL_FreeSurface(surfaceBlanc);
        SDL_RenderCopy(getrenderer(), textureBlanc, NULL, &dimension);
        SDL_DestroyTexture(textureBlanc);

    }

    else if (scoreNoir > scoreBlanc) {

        SDL_Surface *surfaceNoir = TTF_RenderText_Solid(font, "NOIR, Vous avez gagne. Felicitation", color);//le texte a afficher si le
        SDL_Texture *textureNoir = SDL_CreateTextureFromSurface(getrenderer(), surfaceNoir);                //joueur 1 est gagnant
        SDL_FreeSurface(surfaceNoir);
        SDL_RenderCopy(getrenderer(), textureNoir, NULL, &dimension);
        SDL_DestroyTexture(textureNoir);

    }
    else {

        SDL_Surface *surface = TTF_RenderText_Solid(font, "Egalite", color);//le texte a afficher s'il ya egalite
        SDL_Texture *texture = SDL_CreateTextureFromSurface(getrenderer(), surface);
        SDL_FreeSurface(surface);
        SDL_RenderCopy(getrenderer(), texture, NULL, &dimension);
        SDL_DestroyTexture(texture);

    }

    SDL_RenderPresent(getrenderer());

    TTF_CloseFont(font);

    SDL_Delay(5000);

    start(quit);


}












