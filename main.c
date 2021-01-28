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

int main(int argc, char *argv[])
{

    Init("Othello");  //Initialisation de tous qu'on a besoin

    bool quit = false;
    start(&quit); //lancer l'interface de Bienvenue



    atexit(cleanUp); //si le programme exit appele la fonction cleanUp


    exit(0);
    return 0;
}
