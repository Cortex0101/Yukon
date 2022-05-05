#include "Card.h"
#include "CardLinkedList.h"

#ifndef YUKON_FOUNDATION_H
#define YUKON_FOUNDATION_H

int getSuit(int foundationNo) {
    activeHead = foundationNo;
    return getTail()->data.suit;
}

Card getTopCard(int foundationNo) {
    activeHead = foundationNo;
    return getHead()->data;
}

bool stackIsEmpty(int foundationNo) {
    activeHead = foundationNo;
    if (getHead() == NULL) {
        return true;
    }
    return false;
}

bool stackIsFull(int foundationNo) {
    activeHead = foundationNo;
    if (getTopCard(foundationNo).value == 13) {
        return true;
    }
    return false;
}

bool isPlaceable(Card card, int foundationNo) {
    if ((card.suit == getSuit(foundationNo) && !stackIsFull(foundationNo)) || stackIsEmpty(foundationNo)) {
        return true;
    }
    return false;
}

void placeCard(Card card, int foundationNo) {
    if(isPlaceable(card, foundationNo)) {
        insertAtHead(card);
    }
}

#endif