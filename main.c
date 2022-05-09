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
#include "Foundation.h"
#include "FoundationView.h"

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
    shuffleDeckRandom();
    print(0);
    loadCardTextureAndGenerateViews();

    setActiveList(1);
    initializeColumnLists();

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP || e.type == SDL_MOUSEMOTION) {
                columnHandleMouseEvent(&e);
            }
        }

        SDL_SetRenderDrawColor( gRenderer, 78, 106, 84, 0xFF );
        SDL_RenderClear( gRenderer );

        if (priv_column != 1 || !mouseButtonDown) drawColumn(1);
        if (priv_column != 2 || !mouseButtonDown) drawColumn(2);
        if (priv_column != 3 || !mouseButtonDown) drawColumn(3);
        if (priv_column != 4 || !mouseButtonDown) drawColumn(4);
        if (priv_column != 5 || !mouseButtonDown) drawColumn(5);
        if (priv_column != 6 || !mouseButtonDown) drawColumn(6);
        if (priv_column != 7 || !mouseButtonDown) drawColumn(7);

        drawFoundation(8);
        drawFoundation(9);
        drawFoundation(10);
        drawFoundation(11);
        columnUpdateMouse();

        SDL_RenderPresent( gRenderer );
    }

    closeWindow();
    return 0;
}