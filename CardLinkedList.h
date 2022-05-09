#ifndef YUKON_CARDLINKEDLIST_H
#define YUKON_CARDLINKEDLIST_H

#include<stdio.h>
#include<stdlib.h>

#include "Card.h"

struct Node  {
    Card data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

/*
 * index 0 is head of deck
 * index 1-7 is head of columns
 * index 8-11 is head of foundations
 */
struct Node* heads[12];
int activeHead;

void addHead(struct Node* newHead, int i) {
    heads[i] = newHead;
}

void setActiveList(int i) {
    activeHead = i;
    head = heads[i];
}

//Creates a new Node and returns pointer to it.
struct Node* getNewNode(Card card) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = card;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//Inserts a Node at head of doubly linked list
void insertAtHead(Card card) {
    struct Node* newNode = getNewNode(card);
    if(head == NULL) {
        head = newNode;
        return;
    }

    heads[activeHead]->prev = newNode;
    newNode->next = heads[activeHead];
    heads[activeHead] = newNode;

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

//Inserts a Node at tail of Doubly linked list
void insertAtTail(Card card) {
    struct Node* temp = heads[activeHead];
    struct Node* newNode = getNewNode(card);
    if(heads[activeHead] == NULL) {
        heads[activeHead] = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; // Go To last Node
    temp->next = newNode;
    newNode->prev = temp;
}
//returns the head of the linked list
struct Node* getHead() {
    struct Node* temp = heads[activeHead];
    if (temp == NULL) {
        return heads[activeHead];
    }
    while(true) {
        if (temp->prev != NULL) {
            temp = temp->prev;
        } else {
            return temp;
        }
    }
}

//returns the tail of the linked list
struct Node* getTail() {
    struct Node* temp = heads[activeHead];
    if (temp == NULL) {
        return heads[activeHead];
    }
    while(true) {
        if (temp->next != NULL) {
            temp = temp->next;
        } else {
            return temp;
        }
    }
}

// returns the node that is the n'th in the list, starting from the head
struct Node* getElementFromHead(int offsetFromHead) {
    struct Node* temp = getHead();
    for (int i = 0; i < offsetFromHead; ++i) {
        if (temp != NULL) {
            temp = temp->next;
        } else {
            printf("No more cards to iterate over!");
            return temp;
        }
    }
    return temp;
}

// returns the node that is the n'th in the list, starting from the tail
struct Node* getElementFromTail(int offsetFromTail) {
    struct Node* temp = getTail();
    for (int i = 0; i < offsetFromTail; ++i) {
        if (temp != NULL) {
            temp = temp->prev;
        } else {
            printf("No more cards to iterate over!");
            return temp;
        }
    }
    return temp;
}

int getSize() {
    struct Node* temp = heads[activeHead];
    int i = 0;
    while(temp != NULL) {
        ++i;
        temp = temp->next;
    }
    return i;
}

#endif //YUKON_CARDLINKEDLIST_H
