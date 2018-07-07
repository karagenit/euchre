#include "cards.h"

/* This is basically a singleton container
 * of all of the possible cards. Things like "hands"
 * can simply be an array of 5 ints which point to the
 * index in this array for that card, so we don't have
 * to malloc new Card structs every time. Also makes
 * comparing cards easier.
 */
struct Card cards[] = {
    {1, 1}, // 1
    {1, 2}, // 2
    {1, 3}, // 3
    {1, 4}, // 4
    {1, 5}, // 5
    {1, 7}, // 6
    {1, 8}, // 7

    {2, 3}, // 8
    {2, 4}, // 9
    {2, 5}, // 10
    {2, 7}, // 11
    {2, 8}, // 12

    {3, 3}, // 13
    {3, 4}, // 14
    {3, 5}, // 15
    {3, 6}, // 16
    {3, 7}, // 17
    {3, 8}, // 18

    {4, 3}, // 19
    {4, 4}, // 20
    {4, 5}, // 21
    {4, 6}, // 22
    {4, 7}, // 23
    {4, 8}, // 24
};
