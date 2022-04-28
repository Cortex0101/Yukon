//
// Created by ldeir on 28-04-2022.
//

#ifndef YUKON_CARDVIEW_H
#define YUKON_CARDVIEW_H

#include <SDL.h>

#include "Card.h"
#include "Ressources.h"

SDL_Rect (*gCardViewRects)[13] = NULL;

typedef struct {
    int width;
    int height;

    int xPos;
    int yPos;

    Card card;
} CardView;

void setupCardView() {
    loadCardDeckImage(); // must be called first
    gCardViewRects = getTextureRectsForDeck();
}

CardView getCard() {
    CardView cardView;
    cardView.width = 55;
    cardView.height = 75;
    cardView.xPos = 0;
    cardView.yPos = 0;

    Card card;
    card.suit = Spades;
    card.value = 3;
    card.visible = true;
    cardView.card = card;

    return cardView;
}

void drawCard(const CardView* cardView) {
    SDL_Rect cardDimension;
    cardDimension.w = cardView->width;
    cardDimension.h = cardView->height;
    cardDimension.x = cardView->xPos;
    cardDimension.y = cardView->yPos;

    SDL_RenderCopy(gRenderer, gCardDeck, &gCardViewRects[cardView->card.suit][cardView->card.value - 1], &cardDimension);
}

#endif //YUKON_CARDVIEW_H
