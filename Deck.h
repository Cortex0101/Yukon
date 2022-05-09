#include "Card.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef YUKON_DECK_H
#define YUKON_DECK_H

void createDeck() {
    setActiveList(0);
    for (int i = 1; i < 14; ++i) {
        for (int j = 0; j < 4; ++j) {
            Card *card = (Card *) malloc(sizeof(Card));
            card->value = i;
            card->suit = j;
            insertAtTail(*card);
        }
    }
}
//draws the top card of the deck (which also removes it from the deck)
Card getTopCardOfDeck() {
    setActiveList(0);
    Card *card = (Card *) malloc(sizeof(Card));
    card->suit = getTail()->data.suit;
    card->value = getTail()->data.value;
    if (getTail()->prev != NULL) {
        getTail()->prev->next = NULL;
    }
    return *card;
}

int rand_comparison(const void *a, const void *b)
{
    (void)a; (void)b;
    return rand() % 2 ? +1 : -1;
}

void randomize(int arr[], int n, size_t size) {
    return qsort(arr, n, size, rand_comparison);
}

void shuffleDeckRandom(){
    int pointerValueArray[52];
    Card cardArray[52];
    for (int i = 0; i < 52; ++i) {
        cardArray[i] = getTopCardOfDeck();
        pointerValueArray[i] = i;
    }
    randomize (pointerValueArray, 52, sizeof(int));
    for (int i = 0; i < 52; ++i) {
        insertAtTail(cardArray[pointerValueArray[i]]);
    }
}

void shuffleDeckInterleaved(){
    Card stack1[26];
    Card stack2[26];
    for (int i = 0; i < 26; ++i) {
        stack1[i] = getTopCardOfDeck();
    }
    for (int i = 0; i < 26; ++i) {
        stack2[i] = getTopCardOfDeck();
    }
    struct Node* deckHead = NULL;
    addHead(deckHead,0);
    for (int i = 0; i < 26; ++i) {
        insertAtTail(stack1[i]);
        insertAtTail(stack2[i]);
    }
}
#endif