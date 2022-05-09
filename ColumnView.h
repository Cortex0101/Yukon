//
// Created by ldeir on 29-04-2022.
//

#ifndef YUKON_COLUMNVIEW_H
#define YUKON_COLUMNVIEW_H

#include "CardView.h"
#include "Column.h"

const int COLUMN_X = 10;
const int COLUMN_Y = 10;
const int COLUMN_VERTICAL_SPACING = 120 / 5;
const int COLUMN_HORIZONTAL_SPACING = (88 / 4) + 88;

void drawColumn(int column) {
    setActiveList(column);
    column -= 1; // simple hack..
    struct Node* temp = heads[activeHead];

    if (temp == NULL)
        return;

    CardView cardView = getCardView(temp->data);
    cardView.xPos = (COLUMN_HORIZONTAL_SPACING * column) + COLUMN_X;
    cardView.yPos = (COLUMN_VERTICAL_SPACING * 0) + COLUMN_Y;
    drawCard(&cardView);

    int i = 1;
    while (true) {
        if (temp->next != NULL) {
            temp = temp->next;
            cardView = getCardView(temp->data);
            cardView.xPos = (COLUMN_HORIZONTAL_SPACING * column) + COLUMN_X;
            cardView.yPos = (COLUMN_VERTICAL_SPACING * i) + COLUMN_Y;
            drawCard(&cardView);
            ++i;
        } else {
            return;
        }
    }
}

void    drawColumnWithOffset(int column, int cardNo, int xOffset, int yOffset) {
    setActiveList(column);
    column -= 1; // simple hack..
    struct Node *temp = heads[activeHead];

    if (temp == NULL)
        return;

    int sub = 2;

    CardView cardView = getCardView(temp->data);
    if (cardNo == 1) {
        cardView.xPos = xOffset;
        cardView.yPos = (COLUMN_VERTICAL_SPACING * 0) + yOffset;
        drawCard(&cardView);
        sub -= 1;
    } else {
        cardView.xPos = (COLUMN_HORIZONTAL_SPACING * column) + COLUMN_X;
        cardView.yPos = (COLUMN_VERTICAL_SPACING * 0) + COLUMN_Y;
        drawCard(&cardView);
    }

    int i = 2;
    int j = 2;
    while (true) {
        if (temp->next != NULL) {
            temp = temp->next;
            cardView = getCardView(temp->data);
            if (i >= cardNo) {
                cardView.xPos = xOffset;
                cardView.yPos = (COLUMN_VERTICAL_SPACING * (j - sub)) + yOffset;
                ++j;
                ++i;
            } else {
                cardView.xPos = (COLUMN_HORIZONTAL_SPACING * column) + COLUMN_X;
                cardView.yPos = (COLUMN_VERTICAL_SPACING * (i - 1)) + COLUMN_Y;
                ++i;
            }
            drawCard(&cardView);
        } else {
            return;
        }
    }
}

#endif //YUKON_COLUMNVIEW_H
