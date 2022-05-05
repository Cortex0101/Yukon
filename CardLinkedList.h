//
// Created by ldeir on 30-04-2022.
//

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

struct Node* heads[20];

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

struct Node* getElementFromHead(int j) {
    struct Node* temp = getHead();
    for (int i = 0; i < j; ++i) {
        if (temp != NULL) {
            temp = temp->next;
        } else {
            printf("No more cards to iterate over!");
            return temp;
        }
    }
    return temp;
}

struct Node* getElementFromTail(int j) {
    struct Node* temp = getTail();
    for (int i = 0; i < j; ++i) {
        if (temp != NULL) {
            temp = temp->prev;
        } else {
            printf("No more cards to iterate over!");
            return temp;
        }
    }
    return temp;
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

#endif //YUKON_CARDLINKEDLIST_H
