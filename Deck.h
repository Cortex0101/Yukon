#include "Card.h"

void createDeck() {
    for (int i = 1; i < 14; ++i) {
        for (int j = 1; j < 5; ++j) {
            Card *card = (Card *) malloc(sizeof(Card));
            card->value = i;
            card->suit = j;
            insertAtTail(*card);
        }
    }
}
//Not sure if this needs to return the card or the node
Card* removeTopCardOfDeck() {
    activeHead = 0;
    struct Node* temp = getTail();
    temp->prev->next = NULL;
}