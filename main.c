#include <SDL.h>
#include <SDL_render.h>
#include <stdio.h>
#include <stdbool.h>
#include "Window.h"
#include "Ressources.h"
#include "CardView.h"
#include "ColumnView.h"
#include "CardLinkedList.h"
#include "Column.h"
#include "ColumnMouseInteraction.h"
#include "Foundation.h"
#include "FoundationView.h"
#include "gameLogic.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main( int argc, char* args[]) {
    executable_location = args[0];
    resources_folder = getRessourcesFolder(executable_location);

    if( !initWindow(SCREEN_WIDTH, SCREEN_HEIGHT) ) {
        printf( "Failed to initialize!\n" );
        return -1;
    }

    //initializes the game.
    createDeck();
    shuffleDeckRandom();
    print(0);
    loadCardTextureAndGenerateViews();
    initializeColumnLists();

    //checks for mouse updates
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

        //draws the window
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

        if (checkIfAllFoundationsAreFull()) {quitGame();}

        columnUpdateMouse();
        SDL_RenderPresent( gRenderer );
    }
    closeWindow();
    return 0;
}