//
// Created by ldeir on 29-04-2022.
//

#ifndef YUKON_COLUMNVIEW_H
#define YUKON_COLUMNVIEW_H

#include "CardView.h"

const int COLUMN_X = 10;
const int COLUMN_Y = 10;

void drawColumn(CardView cards[], int numCards, int column) {
    if (numCards < 1)
        return;

    // Feel free to expirement with below parameters
    const int COLUMN_VERTICAL_SPACING = cards[0].height / 5;
    const int COLUMN_HORIZONTAL_SPACING = (cards[0].width / 4) + cards[0].width;

    for (int i = 0; i < numCards; ++i) {
        cards[i].xPos = (COLUMN_HORIZONTAL_SPACING * column) + COLUMN_X;
        cards[i].yPos = (COLUMN_VERTICAL_SPACING * i) + COLUMN_Y;
        drawCard(&cards[i]);
    }
}

#endif //YUKON_COLUMNVIEW_H
