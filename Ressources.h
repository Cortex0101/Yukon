//
// Created by ldeir on 28-04-2022.
//

#ifndef YUKON_RESSOURCES_H
#define YUKON_RESSOURCES_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

SDL_Texture *gCardDeck = NULL;

const char* getWorkingDirectory() {
    static char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return cwd;
    } else {
        perror("getcwd() error");
        return "";
    }
}

// returns 13 * 4 = 52 rect's
SDL_Rect (*getTextureRectsForDeck(void))[13] {
    int TEXTURE_WIDTH;
    int TEXTURE_HEIGHT;
    SDL_QueryTexture(gCardDeck, NULL, NULL, &TEXTURE_WIDTH, &TEXTURE_HEIGHT);
    const int NUM_SUITS = 4;
    const int NUM_VALUES = 13;
    const int CARD_WIDTH = TEXTURE_WIDTH / NUM_VALUES;
    const int CARD_HEIGHT = TEXTURE_HEIGHT / NUM_SUITS;

    static SDL_Rect rects[4][13];
    for (int i = 0; i < NUM_SUITS; ++i) {
        for (int j = 0; j < NUM_VALUES; ++j) {
            SDL_Rect rect;
            rect.x = CARD_WIDTH * j;
            rect.y = CARD_HEIGHT * i;
            rect.w = CARD_WIDTH;
            rect.h = CARD_HEIGHT;
            rects[i][j] = rect;
        }
    }

    return rects;
}

void loadCardDeckImage() {
    gCardDeck = IMG_LoadTexture(gRenderer, "D:\\Development\\Yukon\\ressources\\card_deck.bmp"); // TODO: Use relative path
}



#endif //YUKON_RESSOURCES_H
