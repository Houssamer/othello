#include "structures.h"
#include <stdbool.h>

#ifndef PROTOTYPES

extern void cleanUp(void);
extern void Init(char *titre);
extern void playMusic(void);
extern void stopMusic(void);
extern void JoueurVsJoueur(bool *quit);
extern SDL_Renderer *getrenderer(void);
extern void JoueurVsMachine(bool *quit);
extern SDL_Texture *loadImage(char *name);
extern void Welcome(SDL_Renderer *renderer);
extern void gestion_inputs_Joueur(SDL_Event *event, bool *quit, int *positionX, int position[10][10][3], int *positionY,
                                    int *pion, int pions[10][10], int *Joueur, int *scoreBlanc, int *scoreNoir);
extern void updatescoreJ(int scoreBlanc, int scoreNoir);
extern void startJ(SDL_Renderer *renderer);
extern void gestion_inputs_machine(SDL_Event *event, bool *quit, int *joueur, int *positionX, int *positionY,
                                   int position[10][10][3], int pions[10][10], int *scoreBlanc, int *scoreNoir);
extern void updateM(void);
extern void startM(SDL_Renderer *renderer);
extern void start(bool *quit);
extern bool vide(const int ligne, const int colonne, const int pions[10][10]);
extern void Joueur_Verification(int *joueur, int *pion);
extern void posPion(const int positionX, const int positionY, const int ligne, const int colonne, int pions[10][10], const int pion,
                    int *scoreBlanc, int *scoreNoir);
extern void pion_Update(const int ligne, const int colonne, int pions[10][10], const int pion, int *scoreBlanc, int *scoreNoir);
extern void score(int pion, int *scoreBlanc, int *scoreNoir);
extern bool jeuTermine(int pions[10][10]);
extern void showGagnant(int scoreBlanc, int scoreNoir);
extern void pion_machine(int pionMachine, int pions[10][10], int *scoreBlanc, int *scoreNoir);

#endif // PROTOTYPES

