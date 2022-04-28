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

    setupCardView();

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

        // do stuff
        /*
        int h, w;
        SDL_Texture *img = IMG_LoadTexture(gRenderer, "D:\\Development\\Yukon\\ressources\\card_deck.bmp");
        SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
        SDL_Rect texr; texr.x = SCREEN_WIDTH/2; texr.y = SCREEN_HEIGHT/2; texr.w = w*2; texr.h = h*2;

        SDL_RenderCopy(gRenderer, img, NULL, &texr);
        */

        //SDL_Rect *textureRects = getTextureRectsForDeck();
        //SDL_RenderCopy(gRenderer, gCardDeck, textureRects, &card);

        CardView cardd = getCard();
        drawCard(&cardd);

        //Update screen
        SDL_RenderPresent( gRenderer );


    }

    closeWindow();
    return 0;
}