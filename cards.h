#ifndef _CARDS_H_
#define _CARDS_H_

#include <stdint.h>
#include <stdbool.h>

struct Card {
    bool valid;
    /*
     * 1: trump
     * 2: same color as trump
     * 3: off suit
     * 4: off suit
     */
    uint8_t suit;
    /*
     * Right, Left, Ace, King, Queen, Jack (?), 10, 9
     * 1 - 8
     */
    uint8_t rank;
};

// TODO: instead of these numbers, use #define KING 4

extern struct Card cards[];

#endif
