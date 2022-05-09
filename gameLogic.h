#include "Foundation.h"

bool checkIfAllFoundationsAreFull() {
    if (stackIsFull(8) && stackIsFull(9) && stackIsFull(10) && stackIsFull(11)) {
        return true;
    }
    return false;
}

void quitGame() {
    printf("You win!!!");
    exit(0);
}

//Prints all the elements in linked list in forward traversal order
void print(int activeList) {
    setActiveList(activeList);
    struct Node* temp = heads[activeHead];
    int i = 0;
    printf("Double Linked List Consists of: \n");
    while(temp != NULL) {
        i++;
        printf("%d of %s \n", temp->data.value, CARD_SUITS_STRING[temp->data.suit]);
        temp = temp->next;
    }
    printf("%d cards total", i);
    printf("\n");
}

//Prints all elements in linked list in reverse traversal order.
void reversePrint() {
    struct Node* temp = heads[activeHead];
    if(temp == NULL) return; // empty list, exit
    // Going to last Node
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d%d ", temp->data.suit, temp->data.value);
        temp = temp->prev;
    }
    printf("\n");
}