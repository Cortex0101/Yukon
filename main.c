/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_image.h>
#include <SDL_keyboard.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "Card.h"
#include "Window.h"
#include "Ressources.h"
#include "CardView.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main( int argc, char* args[]) {
    if( !initWindow(SCREEN_WIDTH, SCREEN_HEIGHT) ) {
        printf( "Failed to initialize!\n" );
        return -1;
    }

    loadCardTextureAndGenerateViews();

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = true;
            }
        }



        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        CardView card = getCard();
        drawCard(&card);

        //Update screen
        SDL_RenderPresent( gRenderer );


    }

    closeWindow();
    return 0;
}