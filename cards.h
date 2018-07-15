#ifndef _CARDS_H_
#define _CARDS_H_

#include <stdint.h>

#define CARDS 24

typedef struct Card {
    /*
     * 1: trump
     * 2: same color as trump
     * 3: off suit
     * 4: off suit
     */
    int8_t suit;
    /*
     * Right, Left, Ace, King, Queen, Jack (?), 10, 9
     * 1 - 8
     */
    int8_t rank;
} Card;

// TODO: instead of these numbers, use #define KING 4

extern Card cards[];

#endif
