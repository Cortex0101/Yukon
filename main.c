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
#include "ColumnView.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main( int argc, char* args[]) {
    if( !initWindow(SCREEN_WIDTH, SCREEN_HEIGHT) ) {
        printf( "Failed to initialize!\n" );
        return -1;
    }

    loadCardTextureAndGenerateViews();

    CardView card1 = getCard(1, Hearts);
    CardView card2 = getCard(2, Hearts);
    CardView card3 = getCard(3, Spades);
    CardView card4 = getCard(4, Spades);
    CardView card5 = getCard(5, Clubs);
    CardView card6 = getCard(6, Clubs);
    CardView card7 = getCard(7, Diamonds);
    CardView card8 = getCard(8, Diamonds);
    CardView card9 = getCard(9, Diamonds);
    CardView card10 = getCard(10, Diamonds);
    CardView card11 = getCard(11, Diamonds);
    CardView card12 = getCard(12, Diamonds);
    CardView card13 = getCard(13, Diamonds);

    CardView column[13] = {card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13};

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

        drawColumn(column, 13, 0);
        drawColumn(column, 13, 1);
        drawColumn(column, 13, 2);
        drawColumn(column, 13, 3);
        drawColumn(column, 13, 4);
        drawColumn(column, 13, 5);
        drawColumn(column, 13, 6);

        //Update screen
        SDL_RenderPresent( gRenderer );


    }

    closeWindow();
    return 0;
}