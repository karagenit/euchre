#include "cards.h"

/* This is basically a singleton container
 * of all of the possible cards. Things like "hands"
 * can simply be an array of 5 ints which point to the
 * index in this array for that card, so we don't have
 * to malloc new Card structs every time. Also makes
 * comparing cards easier.
 */
Card cards[CARDS] = {
    {1, 1}, // 0
    {1, 2}, // 1
    {1, 3}, // 2
    {1, 4}, // 3
    {1, 5}, // 4
    {1, 7}, // 5
    {1, 8}, // 6

    {2, 3}, // 7
    {2, 4}, // 8
    {2, 5}, // 9
    {2, 7}, // 10
    {2, 8}, // 11

    {3, 3}, // 12
    {3, 4}, // 13
    {3, 5}, // 14
    {3, 6}, // 15
    {3, 7}, // 16
    {3, 8}, // 17

    {4, 3}, // 18
    {4, 4}, // 19
    {4, 5}, // 20
    {4, 6}, // 21
    {4, 7}, // 22
    {4, 8}, // 23
};
