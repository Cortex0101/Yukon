#include "Card.h"
#include "CardLinkedList.h"

#ifndef YUKON_FOUNDATION_H
#define YUKON_FOUNDATION_H

//uses the foundation number to give each foundation a unique suit
int getSuit(int foundationNo) {
    return foundationNo - 8;
}

Card getTopCardOfFoundation(int foundationNo) {
    int prevActive = activeHead;
    setActiveList(foundationNo);
    if (getTail() != NULL) {
        Card card = getTail()->data;
        setActiveList(prevActive);
        return card;
    }
    setActiveList(prevActive);
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
    if (card.suit == getSuit(foundationNo) && !stackIsFull(foundationNo)) {
        if (stackIsEmpty(foundationNo)) {
            if (card.value == 1) {
                return true;
            }
        } else {
            if (card.value == getTopCardOfFoundation(foundationNo).value + 1) {
                return true;
            }
        }
    }
    return false;
}

void placeCard(Card* card, int foundationNo) {
    struct Node* theCardNode = getElementFromTail(0);
    if(isPlaceableInFoundation(*card, foundationNo)) {
        if (getElementFromTail(1) != NULL) {
            getElementFromTail(1)->next = NULL;
        } else {
            addHead(NULL, activeHead);
        }
        int prevActive = activeHead;
        setActiveList(foundationNo);
        struct Node* tail = getTail();
        if (tail != NULL) {
            tail->next = theCardNode;
            theCardNode->prev = tail;
        } else {
            addHead(theCardNode, foundationNo);
        }
        setActiveList(prevActive);
    }
}

#endif