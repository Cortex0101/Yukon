#include "Card.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    if (getTail()->prev != NULL) {
        struct Node *temp1 = getTail()->prev;
        struct Node *temp2 = getTail();
        if (temp1->next != NULL) {
            temp1->next = NULL;
            return temp2;
        }
    }
    return getTail();


}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void randomize(int arr[], int n) {
    srand(time(NULL));
    int i;
    for(i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

void shuffleDeckRandom(){
    int pointerValueArray[52];
    struct Node cardArray[52];
    for (int i = 0; i < 52; ++i) {
        cardArray[i] = *removeTopCardOfDeck();
        pointerValueArray[i] = i;
    }
    randomize (pointerValueArray, 52);
    addHead(&cardArray[pointerValueArray[0]],0);
    for (int i = 1; i < 52; ++i) {
        insertAtTail(cardArray[pointerValueArray[i]].data);
    }
}

//not sure what interleaved shuffling is so
void shuffleDeckInterleaved(){

}