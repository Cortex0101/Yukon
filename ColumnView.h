//
// Created by ldeir on 29-04-2022.
//

#ifndef YUKON_COLUMNVIEW_H
#define YUKON_COLUMNVIEW_H

#include "CardView.h"
#include "Column.h"

const int COLUMN_X = 10;
const int COLUMN_Y = 10;

void drawColumn(int column) {
    // Feel free to expirement with below parameters
    const int COLUMN_VERTICAL_SPACING = 120 / 5;
    const int COLUMN_HORIZONTAL_SPACING = (88 / 4) + 88;

    setActiveList(column);
    column -= 1; // simple hack..
    struct Node* temp = heads[activeHead];

    if (temp == NULL)
        return;

    CardView cardView = getCard(temp->data.value, temp->data.suit);
    cardView.xPos = (COLUMN_HORIZONTAL_SPACING * column) + COLUMN_X;
    cardView.yPos = (COLUMN_VERTICAL_SPACING * 0) + COLUMN_Y;
    drawCard(&cardView);

    int i = 1;
    while (true) {
        if (temp->next != NULL) {
            temp = temp->next;
            cardView = getCard(temp->data.value, temp->data.suit);
            cardView.xPos = (COLUMN_HORIZONTAL_SPACING * column) + COLUMN_X;
            cardView.yPos = (COLUMN_VERTICAL_SPACING * i) + COLUMN_Y;
            drawCard(&cardView);
            ++i;
        } else {
            return;
        }
    }
}

#endif //YUKON_COLUMNVIEW_H
