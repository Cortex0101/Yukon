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

void insertCardsInColumn(int column) {
    for (int i = 0; i < column + 4; ++i) {
        Card card = getTopCardOfDeck();
        if (i + 1 < column) {
            card.visible = false;
        }
        setActiveList(column);
        insertAtTail(card);
    }
}

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

    Card card1 = getTopCardOfDeck();
    setActiveList(1);
    insertAtTail(card1);

    /*
    for (int i = 0; i < 6; ++i) {
        Card card = getTopCardOfDeck();
        if (i > 4) {
            card.visible = false;
        }
        setActiveList(2);
        insertAtTail(card);
    }


    for (int i = 0; i < 7; ++i) {
        Card card = getTopCardOfDeck();
        if (i > 5) {
            card.visible = false;
        }
        setActiveList(3);
        insertAtTail(card);
    }

    for (int i = 0; i < 8; ++i) {
        Card card = getTopCardOfDeck();
        if (i > 6) {
            card.visible = false;
        }
        setActiveList(4);
        insertAtTail(card);
    }

    for (int i = 0; i < 9; ++i) {
        Card card = getTopCardOfDeck();
        setActiveList(5);
        insertAtTail(card);
    }

    for (int i = 0; i < 10; ++i) {
        Card card = getTopCardOfDeck();
        setActiveList(6);
        insertAtTail(card);
    }

    setActiveList(7);
    for (int i = 0; i < 11; ++i) {
        Card card = getTopCardOfDeck();
        setActiveList(7);
        insertAtTail(card);
    }
    */

    insertCardsInColumn(2);
    insertCardsInColumn(3);
    insertCardsInColumn(4);
    insertCardsInColumn(5);
    insertCardsInColumn(6);
    insertCardsInColumn(7);
}

// Check if 'card' is placeable in the column with the head 'columnHead'
bool isPlaceable(const Card* card, int column) {
    int prevActive = activeHead;
    setActiveList(column);
    struct Node* columnTail = getTail();
    if (columnTail == NULL) {
        setActiveList(prevActive);
        return true; // can place if there is no cards in column
    }
    if (isOneGreater(&columnTail->data, card) && !cardsSameSuit(card, &columnTail->data)) {
        setActiveList(prevActive);
        return true;
    }
    setActiveList(prevActive);
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
void moveCardsWithoutRules(int fromColumn, int toColumn, int amount) {
    setActiveList(fromColumn);
    struct Node* fromCard = getElementFromTail(amount - 1);
    if (getElementFromTail(amount) != NULL) {
        getElementFromTail(amount)->next = NULL;
    } else {
        addHead(NULL, fromColumn);
    }
    setActiveList(toColumn);
    struct Node* tail = getTail();
    if (tail != NULL) {
        tail->next = fromCard;
        fromCard->prev = tail;
    } else {
        addHead(fromCard, toColumn);
    }
}
//checks if the card is moveable, then moves it to the new column
bool moveCards(int fromColumn, int toColumn, int amount) {
    setActiveList(fromColumn);
    struct Node* fromCard = getElementFromTail(amount - 1);
    if (isPlaceable(&fromCard->data, toColumn)) {
        if (getElementFromTail(amount) != NULL) {
            getElementFromTail(amount)->next = NULL;
        } else {
            addHead(NULL, fromColumn);
        }
        setActiveList(toColumn);
        struct Node* tail = getTail();
        if (tail != NULL) {
            tail->next = fromCard;
            fromCard->prev = tail;
        } else {
            addHead(fromCard, toColumn);
        }
        return true;
    }
    return false;
}

Card* getTopCard(int column) {
    int privActive = activeHead;
    setActiveList(column);
    Card* card = &getTail()->data;
    setActiveList(privActive);
    return card;
}

int getColumnSize(int column) {
    int prevActive = activeHead;
    setActiveList(column);
    int size = getSize();
    setActiveList(prevActive);
    return size;
}


#endif //YUKON_COLUMN_H
