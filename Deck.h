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
struct Node* removeTopCardOfDeck() {
    activeHead = 0;
    struct Node* temp1 = getTail()->prev;
    struct Node* temp2 = getTail();
    temp1->next = NULL;
    return temp2;
}