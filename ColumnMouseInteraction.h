//
// Created by ldeir on 06-05-2022.
//

#ifndef YUKON_COLUMNMOUSEINTERACTION_H
#define YUKON_COLUMNMOUSEINTERACTION_H

#include "ColumnView.h"

int getColumnBasedOnMouseXPos(int mouseXPos) {
    const int COLUMN1_XPOS1 = (COLUMN_HORIZONTAL_SPACING * 0) + COLUMN_X;
    const int COLUMN1_XPOS2 = COLUMN1_XPOS1 + CARDVIEW_WIDTH;

    const int COLUMN2_XPOS1 = (COLUMN_HORIZONTAL_SPACING * 1) + COLUMN_X;
    const int COLUMN2_XPOS2 = COLUMN2_XPOS1 + CARDVIEW_WIDTH;

    const int COLUMN3_XPOS1 = (COLUMN_HORIZONTAL_SPACING * 2) + COLUMN_X;
    const int COLUMN3_XPOS2 = COLUMN3_XPOS1 + CARDVIEW_WIDTH;

    const int COLUMN4_XPOS1 = (COLUMN_HORIZONTAL_SPACING * 3) + COLUMN_X;
    const int COLUMN4_XPOS2 = COLUMN4_XPOS1 + CARDVIEW_WIDTH;

    const int COLUMN5_XPOS1 = (COLUMN_HORIZONTAL_SPACING * 4) + COLUMN_X;
    const int COLUMN5_XPOS2 = COLUMN5_XPOS1 + CARDVIEW_WIDTH;

    const int COLUMN6_XPOS1 = (COLUMN_HORIZONTAL_SPACING * 5) + COLUMN_X;
    const int COLUMN6_XPOS2 = COLUMN6_XPOS1 + CARDVIEW_WIDTH;

    const int COLUMN7_XPOS1 = (COLUMN_HORIZONTAL_SPACING * 6) + COLUMN_X;
    const int COLUMN7_XPOS2 = COLUMN7_XPOS1 + CARDVIEW_WIDTH;

    if (mouseXPos >= COLUMN1_XPOS1 && mouseXPos <= COLUMN1_XPOS2) {
        return 1;
    } else if (mouseXPos >= COLUMN2_XPOS1 && mouseXPos <= COLUMN2_XPOS2) {
        return 2;
    } else if (mouseXPos >= COLUMN3_XPOS1 && mouseXPos <= COLUMN3_XPOS2) {
        return 3;
    } else if (mouseXPos >= COLUMN4_XPOS1 && mouseXPos <= COLUMN4_XPOS2) {
        return 4;
    } else if (mouseXPos >= COLUMN5_XPOS1 && mouseXPos <= COLUMN5_XPOS2) {
        return 5;
    } else if (mouseXPos >= COLUMN6_XPOS1 && mouseXPos <= COLUMN6_XPOS2) {
        return 6;
    } else if (mouseXPos >= COLUMN7_XPOS1 && mouseXPos <= COLUMN7_XPOS2) {
        return 7;
    } else {
        return 0;
    }
}

int getCardBasedOnXY(int mouseXPos, int mouseYPos) {
    int column = getColumnBasedOnMouseXPos(mouseXPos);
    int numCardsInColumn = getColumnSize(column);

    int cardNo = (mouseYPos + COLUMN_Y) / COLUMN_VERTICAL_SPACING;

    if (cardNo <= numCardsInColumn) {
        printf("column: %c, card: %c", column + '0', cardNo + '0');
        return cardNo;
    } else {
        printf("column: %c, card: %c", column + '0', 0 + '0');
        return 0;
    }
}

bool mouseButtonDown;
bool callOnce = false;
int priv_column;
int priv_card;

void columnHandleMouseEvent(SDL_Event* mouseEvent) {
    if (mouseEvent->type == SDL_MOUSEBUTTONDOWN) {
        mouseButtonDown = true;
    } else if (mouseEvent->type == SDL_MOUSEBUTTONUP) {
        mouseButtonDown = false;
        int mousePosX, mousePosY;
        SDL_GetMouseState(&mousePosX, &mousePosY);
        printf("%c%", priv_card + '0');
        //moveCardsWithoutRules(priv_column, getColumnBasedOnMouseXPos(mousePosX), getColumnSize(priv_column) - (priv_card - 1));
        moveCards(priv_column, getColumnBasedOnMouseXPos(mousePosX), getColumnSize(priv_column) - (priv_card - 1));
    }
}

void columnUpdateMouse() {
    int mousePosX, mousePosY;
    SDL_GetMouseState(&mousePosX, &mousePosY);
    if (mouseButtonDown) {
        if (!callOnce) {
            priv_column = getColumnBasedOnMouseXPos(mousePosX);
            priv_card = getCardBasedOnXY(mousePosX, mousePosY);
            callOnce = true;
        }
        drawColumnWithOffset(priv_column, priv_card, mousePosX, mousePosY);
    } else {
        callOnce = false;
    }
}

#endif //YUKON_COLUMNMOUSEINTERACTION_H
