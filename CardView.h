#ifndef YUKON_CARDVIEW_H
#define YUKON_CARDVIEW_H

#include <SDL.h>

#include "Card.h"
#include "Ressources.h"

SDL_Texture *gCardDeck = NULL;
SDL_Rect (*gCardViewRects)[13] = NULL;

const int CARDVIEW_WIDTH = 88;
const int CARDVIEW_HEIGHT = 120;

typedef struct {
    int width;
    int height;

    int xPos;
    int yPos;

    Card card;
} CardView;

// returns 13 * 4 = 52 rect's for each card in the card deck texture
SDL_Rect (*getTextureRectsForDeck(void))[13] {
    int LEFT_PADDING = 2;
    int TOP_PADDING = 0;
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
            rect.x = CARD_WIDTH * j + LEFT_PADDING;
            rect.y = CARD_HEIGHT * i + TOP_PADDING;
            rect.w = CARD_WIDTH;
            rect.h = CARD_HEIGHT;
            rects[i][j] = rect;
        }
    }

    return rects;
}

// Make sure to call in main early.
void loadCardTextureAndGenerateViews() {
    char* cardDeck = "card_deck.bmp";
    char* cardDeckPath = malloc(strlen(resources_folder) + strlen(cardDeck));
    strcpy(cardDeckPath, resources_folder);
    strcat(cardDeckPath, cardDeck);
    printf(cardDeckPath);
    gCardDeck = loadTexture(cardDeckPath);
    gCardViewRects = getTextureRectsForDeck();
}

CardView getCardView(Card card) {
    CardView cardView;
    cardView.width = CARDVIEW_WIDTH;
    cardView.height = CARDVIEW_HEIGHT;
    cardView.xPos = 0;
    cardView.yPos = 0;
    cardView.card = card;
    return cardView;
}

void copyArray(CardView arr[], CardView copy[], int size)
{
    // loop to iterate through array
    for (int i = 0; i < size; ++i)
    {
        copy[i] = arr[i];
    }
}

// Draws a card to the screen
void drawCard(const CardView* cardView) {
    SDL_Rect cardDimension;
    cardDimension.w = cardView->width;
    cardDimension.h = cardView->height;
    cardDimension.x = cardView->xPos;
    cardDimension.y = cardView->yPos;

    if (cardView->card.visible) {
        SDL_RenderCopy(gRenderer, gCardDeck, &gCardViewRects[cardView->card.suit][cardView->card.value - 1], &cardDimension);
    } else {
        SDL_SetRenderDrawColor(gRenderer, 0x0c, 0x04, 0x74, 0xFF);
        SDL_RenderFillRect(gRenderer, &cardDimension);
        SDL_SetRenderDrawColor(gRenderer, 0x60, 0xEE, 0xF8, 0xFF);
        SDL_RenderDrawRect(gRenderer, &cardDimension);
    }
}

#endif //YUKON_CARDVIEW_H
