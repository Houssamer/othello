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


SDL_Window *screen = NULL;
SDL_Renderer *renderer = NULL;
Mix_Music *music = NULL;

SDL_Renderer *getrenderer() {
    return renderer;
}


void Init(char *titre) {
    //initialisation de la sdl
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    //creation de la fenetre et le renderer

    screen = SDL_CreateWindow(titre, SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    //initialisation de la sdl_image (biblio permet l'importation des images autre que bmp)

    IMG_Init(IMG_INIT_PNG);

    //initialsation de la sdl_ttf (biblio permet l'ecriture sur la fenetre)

    TTF_Init();

    //initialisation de mixer (biblio permet de jouer de la musique)

    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(4400, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_AllocateChannels(32);

}

void playMusic() {

    //telecharger la musique
    music = Mix_LoadMUS("./audio/Music.mp3");

    //jouer la musique
    Mix_PlayMusic(music, -1);
}

void stopMusic() {

    //faire une pause a la musique
    Mix_PauseMusic();

}

SDL_Texture *loadImage(char *name) {

    //on va d'abord creer les surface et les texture necessaire
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;


    //telecharger l'image

    surface = IMG_Load(name);

    texture = SDL_CreateTextureFromSurface(getrenderer(), surface);
    SDL_FreeSurface(surface);
    surface = NULL;

    return texture;

}

void cleanUp() {

    //fermeture de la biblio sdl_mixer

    Mix_CloseAudio();
    Mix_Quit();

    //fermeture de la biblio sdl_ttf

    TTF_Quit();

    //fermeture de la sdl

    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;

    SDL_Quit();
}

void Welcome(SDL_Renderer *renderer) {

    //telechargement de l'image de bienvenue
    SDL_Texture *texture = loadImage("./graphiques/Accueill.png");
    SDL_Rect dimension = {0, 0, 640, 640};

    SDL_RenderCopy(renderer, texture, NULL, &dimension);
    //afficher l'image sur la fenetre
    SDL_RenderPresent(renderer);
    //fermeture de la texture (des raison de memoire)
    SDL_DestroyTexture(texture);
    SDL_RenderCopy(renderer, NULL, NULL, NULL);
}

void start(bool *quit) {
    Welcome(getrenderer()); //lancer l'interface du jeu

    SDL_Event event;

    while (!(*quit)) {   //la boucle de fonctionnement du Jeu
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    *quit = true;  //quitter la fenetre du jeu
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_0 :  //faire appelle a la fonction qui stop la musique
                            stopMusic();
                            break;
                        case SDLK_KP_0:
                            stopMusic();
                            break;
                        case SDLK_1: //faire appelle a la fonction qui joue de la musique
                            playMusic();
                            break;
                        case SDLK_KP_1:
                            playMusic();
                            break;
                        case SDLK_2:  //faire appelle a la fonction qui lance le jeu dans le cas de deux joueurs
                            JoueurVsJoueur(quit);
                            break;
                        case SDLK_KP_2:
                            JoueurVsJoueur(quit);
                            break;
                        case SDLK_3: //faire appelle a la fonction qui lance le jeu dans le cas de joueur et machine
                            JoueurVsMachine(quit);
                            break;
                        case SDLK_KP_3:
                             JoueurVsMachine(quit);
                            break;
                        default :
                            printf("wrong button\n"); //si l'utilisateur est appuyé sur un bouton autre que les mentionnées
                            break;

                    }
            }
        }
    }
}
