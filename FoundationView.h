//
// Created by ldeir on 29-04-2022.
//

#ifndef YUKON_FOUNDATIONVIEW_H
#define YUKON_FOUNDATIONVIEW_H

#include "CardView.h"
#include "Foundation.h"

const int FOUNDATION_X = 10;
const int FOUNDATION_Y = 10;
const int FOUNDATION_VERTICAL_SPACING = 120 / 5;
const int FOUNDATION_HORIZONTAL_SPACING = (88 / 4) + 88;

const int FOUNDATION_OUTLINE = 3;

void drawFoundation(int foundation) {
    setActiveList(foundation);
    foundation -= 8; // simple hack..
    struct Node* temp = heads[activeHead];

    SDL_Rect foundationRect = {((FOUNDATION_HORIZONTAL_SPACING * 8) + FOUNDATION_X) - FOUNDATION_OUTLINE, (FOUNDATION_Y * (15 * foundation) + COLUMN_Y) - FOUNDATION_OUTLINE, CARDVIEW_WIDTH + FOUNDATION_OUTLINE * 2, CARDVIEW_HEIGHT + FOUNDATION_OUTLINE * 2};
    SDL_SetRenderDrawColor( gRenderer, 220, 220, 220, 0xFF );
    SDL_RenderFillRect(gRenderer, &foundationRect);
    if (temp == NULL)
        return;

    CardView view = getCard(getTail()->data.value, getTail()->data.suit);
    view.xPos = (FOUNDATION_HORIZONTAL_SPACING * 8) + FOUNDATION_X;
    view.yPos = FOUNDATION_Y * (15 * foundation) + COLUMN_Y;
    drawCard(&view);

    /*

    CardView cardView = getCard(temp->data.value, temp->data.suit);
    cardView.xPos = (FOUNDATION_HORIZONTAL_SPACING * 8) + FOUNDATION_X;
    cardView.yPos = FOUNDATION_Y * (15 * foundation) + COLUMN_Y;
    drawCard(&cardView);

    int i = 1;
    while (true) {
        if (temp->next != NULL) {
            temp = temp->next;
            cardView = getCard(temp->data.value, temp->data.suit);
            cardView.xPos = (FOUNDATION_HORIZONTAL_SPACING * foundation) + FOUNDATION_X;
            cardView.yPos = FOUNDATION_Y;
            drawCard(&cardView);
            ++i;
        } else {
            return;
        }
    }
     */
}
#endif //YUKON_COLUMNVIEW_H