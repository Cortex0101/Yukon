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
#include "CardLinkedList.h"
#include "Column.h"
#include "ColumnMouseInteraction.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main( int argc, char* args[]) {
    executable_location = args[0];
    resources_folder = getRessourcesFolder(executable_location);

    printf(resources_folder);
    if( !initWindow(SCREEN_WIDTH, SCREEN_HEIGHT) ) {
        printf( "Failed to initialize!\n" );
        return -1;
    }
    createDeck();
    print(0);
    loadCardTextureAndGenerateViews();

    CardView card1 = getCard(1, Hearts);
    CardView card2 = getCard(2, Clubs);
    CardView card3 = getCard(3, Spades);
    CardView card4 = getCard(4, Hearts);
    CardView card5 = getCard(5, Clubs);
    CardView card6 = getCard(6,Spades);
    CardView card7 = getCard(7, Clubs);
    CardView card8 = getCard(8, Hearts);
    CardView card9 = getCard(9, Diamonds);
    CardView card10 = getCard(10, Hearts);
    CardView card11 = getCard(11, Diamonds);
    CardView card12 = getCard(12, Clubs);
    CardView card13 = getCard(13, Diamonds);

    CardView column[13] = {card1, card2, card3, card4, card5, card6, card7, card8, card9, card10, card11, card12, card13};

    /*Driver code to test the implementation*/
    setActiveList(1);
    initializeColumnLists();

    moveCardsWithoutRules(2, 3, 5);
    moveCardsWithoutRules(3, 4, 6);

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || SDL_MOUSEMOTION) {
                columnHandleMouseEvent(&e);
            }
        }



        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        if (priv_column != 1 || !mouseButtonDown) drawColumn(1);
        if (priv_column != 2 || !mouseButtonDown) drawColumn(2);
        if (priv_column != 3 || !mouseButtonDown) drawColumn(3);
        if (priv_column != 4 || !mouseButtonDown) drawColumn(4);
        if (priv_column != 5 || !mouseButtonDown) drawColumn(5);
        if (priv_column != 6 || !mouseButtonDown) drawColumn(6);
        if (priv_column != 7 || !mouseButtonDown) drawColumn(7);

        columnUpdateMouse();

        //Update screen
        SDL_RenderPresent( gRenderer );


    }

    closeWindow();
    return 0;
}