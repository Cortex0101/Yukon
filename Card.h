//
// Created by ldeir on 27-04-2022.
//

#ifndef YUKON_CARD_H
#define YUKON_CARD_H

#include <stdbool.h>
#include <string.h>

typedef enum {
    Clubs,
    Hearts,
    Spades,
    Diamonds
} Suit;

static const char *CARD_SUITS_STRING[] = {
        "Clubs",
        "Hearts",
        "Spades",
        "Diamonds",
};

typedef struct {
    Suit suit;
    int value;
    bool visible;
} Card;

// Returns -1 if card1 < card2, 0  if card1 == card2, 1  if card1 >  card2
int cardCmp(const Card* card1, const Card* card2) {
    if (card1->value < card2->value) {
        return -1;
    } else if (card1->value == card2->value) {
        return 0;
    } else {
        return 1;
    }
}

// returns true if card1 is 1 greater than card2
bool isOneGreater(const Card* card1, const Card* card2) {
    return (card1->value - 1) == card2->value;
}

bool cardsSameSuit(const Card* card1, const Card* card2) {
    return card1->suit == card2->suit;
}

#endif //YUKON_CARD_H
