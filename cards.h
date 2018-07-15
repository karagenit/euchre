#ifndef _CARDS_H_
#define _CARDS_H_

#include <stdint.h>

#define CARDS 24

typedef int8_t CardIndex;
typedef int8_t Suit;
typedef int8_t Rank;

typedef struct Card {
    /*
     * 1: trump
     * 2: same color as trump
     * 3: off suit
     * 4: off suit
     */
    Suit suit;
    /*
     * Right, Left, Ace, King, Queen, Jack (?), 10, 9
     * 1 - 8
     */
    Rank rank;
} Card;

// TODO: instead of these numbers, use #define KING 4

extern Card cards[];

#endif
