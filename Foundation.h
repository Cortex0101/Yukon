#include "Card.h"
#include "CardLinkedList.h"

#ifndef YUKON_FOUNDATION_H
#define YUKON_FOUNDATION_H

int getSuit(int foundationNo) {
    return foundationNo - 8;
}

Card getTopCardOfFoundation(int foundationNo) {
    int prevActive = activeHead;
    setActiveList(foundationNo);
    if (getHead() != NULL) {
        Card card = getHead()->data;
        setActiveList(prevActive);
        return card;
    }
    return getCard(2, Spades).card; // TODO: Return an invalid card...
}

bool stackIsEmpty(int foundationNo) {
    int prevActive = activeHead;
    setActiveList(foundationNo);
    if (getHead() == NULL) {
        setActiveList(prevActive);
        return true;
    }
    setActiveList(prevActive);
    return false;
}

bool stackIsFull(int foundationNo) {
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
        int prevActive = activeHead;
        setActiveList(foundationNo);
        insertAtTail(card);
        setActiveList(prevActive);
    }
}

#endif