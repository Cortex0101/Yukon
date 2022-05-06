//
// Created by ldeir on 28-04-2022.
//

#ifndef YUKON_COLUMN_H
#define YUKON_COLUMN_H

#include <stdbool.h>

#include "Card.h"
#include "CardLinkedList.h"
#include "Deck.h"

struct Node* column1Head = NULL;
struct Node* column2Head = NULL;
struct Node* column3Head = NULL;
struct Node* column4Head = NULL;
struct Node* column5Head = NULL;
struct Node* column6Head = NULL;
struct Node* column7Head = NULL;

struct Node* columns[7];

void initializeColumnLists() {
    addHead(column1Head, 1);
    addHead(column2Head, 2);
    addHead(column3Head, 3);
    addHead(column4Head, 4);
    addHead(column5Head, 5);
    addHead(column6Head, 6);
    addHead(column7Head, 7);
    columns[0] = column1Head;
    columns[1] = column2Head;
    columns[2] = column3Head;
    columns[3] = column4Head;
    columns[4] = column5Head;
    columns[5] = column6Head;
    columns[6] = column7Head;

    setActiveList(1);
    insertAtTail(removeTopCardOfDeck()->data);

    setActiveList(2);
    for (int i = 0; i < 6; ++i) {
        Card card = removeTopCardOfDeck()->data;
        insertAtTail(card);
    }

    setActiveList(3);
    for (int i = 0; i < 7; ++i) {
        Card card = removeTopCardOfDeck()->data;
        insertAtTail(card);
    }

    setActiveList(4);
    for (int i = 0; i < 8; ++i) {
        insertAtTail(removeTopCardOfDeck()->data);
    }

    setActiveList(5);
    for (int i = 0; i < 9; ++i) {
        insertAtTail(removeTopCardOfDeck()->data);
    }

    setActiveList(6);
    for (int i = 0; i < 10; ++i) {
        insertAtTail(removeTopCardOfDeck()->data);
    }

    setActiveList(7);
    for (int i = 0; i < 11; ++i) {
        insertAtTail(removeTopCardOfDeck()->data);
    }
}

// Check if 'card' is placeable in the column with the head 'columnHead'
bool isPlaceable(const Card* card, int column) {
    setActiveList(column);
    struct Node* columnTail = getTail();
    if (columnTail == NULL) {
        return true; // can place if there is no cards in column
    }
    if (isOneGreater(card, &columnTail->data) && !cardsSameSuit(card, &columnTail->data)) {
        return true;
    }
    return false;
}

bool insertCard(const Card* card, int column) {
    setActiveList(column);
    if (isPlaceable(card, column)) {
        insertAtTail(*card);
        return true;
    }
    return false;
}

// moving without rules - primarly for debugging.
bool moveCardsWithoutRules(int fromColumn, int toColumn, int amount) {
    setActiveList(fromColumn);
    struct Node* fromCard = getElementFromTail(amount - 1);
    getElementFromTail(amount)->next = NULL;
    setActiveList(toColumn);
    struct Node* tail = getTail();
    tail->next = fromCard;
    fromCard->prev = tail;
}

Card* getTopCard(int column) {
    setActiveList(column);
    return &getTail()->data;
}

int getColumnSize(int column) {
    int prevActive = activeHead;
    setActiveList(column);
    int size = getSize();
    setActiveList(prevActive);
    return size;
}


#endif //YUKON_COLUMN_H
