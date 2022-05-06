//
// Created by ldeir on 29-04-2022.
//

#ifndef YUKON_FOUNDATIONVIEW_H
#define YUKON_FOUNDATIONVIEW_H

#include "CardView.h"
#include "Foundation.h"

const int FOUNDATION_X = 10;
const int FOUNDATION_Y = 10;

void    drawFoundation(int foundation) {
    // Feel free to expirement with below parameters
    const int FOUNDATION_VERTICAL_SPACING = 120 / 5;
    const int FOUNDATION_HORIZONTAL_SPACING = (88 / 4) + 88;

    setActiveList(foundation);
    foundation -= 1; // simple hack..
    struct Node* temp = heads[activeHead];

    if (temp == NULL)
        return;

    CardView cardView = getCard(temp->data.value, temp->data.suit);
    cardView.xPos = (FOUNDATION_HORIZONTAL_SPACING * foundation) + FOUNDATION_X;
    cardView.yPos = FOUNDATION_Y;
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
}

#endif //YUKON_COLUMNVIEW_H