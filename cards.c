#include "cards.h"

/* This is basically a singleton container
 * of all of the possible cards. Things like "hands"
 * can simply be an array of 5 ints which point to the
 * index in this array for that card, so we don't have
 * to malloc new Card structs every time. Also makes
 * comparing cards easier.
 */
struct Card cards[] = {
    {false, 0, 0},

    {true, 1, 1}, // 1
    {true, 1, 2}, // 2
    {true, 1, 3}, // 3
    {true, 1, 4}, // 4
    {true, 1, 5}, // 5
    {true, 1, 7}, // 6
    {true, 1, 8}, // 7

    {true, 2, 3}, // 8
    {true, 2, 4}, // 9
    {true, 2, 5}, // 10
    {true, 2, 7}, // 11
    {true, 2, 8}, // 12

    {true, 3, 3}, // 13
    {true, 3, 4}, // 14
    {true, 3, 5}, // 15
    {true, 3, 6}, // 16
    {true, 3, 7}, // 17
    {true, 3, 8}, // 18

    {true, 4, 3}, // 19
    {true, 4, 4}, // 20
    {true, 4, 5}, // 21
    {true, 4, 6}, // 22
    {true, 4, 7}, // 23
    {true, 4, 8}, // 24
};
