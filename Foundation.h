#include "Card.h"
#include "CardLinkedList.h"

#ifndef YUKON_FOUNDATION_H
#define YUKON_FOUNDATION_H

int getSuit(int foundationNo) {
    return foundationNo - 7;
}

Card getTopCardOfFoundation(int foundationNo) {
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
    if (getTopCardOfFoundation(foundationNo).value == 13) {
        return true;
    }
    return false;
}

bool isPlaceableInFoundation(Card card, int foundationNo) {
    if (card.suit == getSuit(foundationNo) && !stackIsFull(foundationNo) && ((!stackIsEmpty(foundationNo) && card.value == getTopCardOfFoundation(foundationNo).value + 1) || (stackIsEmpty(foundationNo) && card.value == 1))) {
        return true;
    }
    return false;
}

void placeCard(Card card, int foundationNo) {
    if(isPlaceableInFoundation(card, foundationNo)) {
        insertAtTail(card);
    }
}

#endif