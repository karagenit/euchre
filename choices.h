#ifndef _CHOICES_H_
#define _CHOICES_H_

#include <stdint.h>

#define BASE_VALUE 10000

/* This struct represents a possible "table state" i.e. what 
 * has already been played, and has values stored for each
 * possible play after that (and technically values that'll never
 * happen, because there aren't duplicate cards).
 *
 * Technically, instead of storing cardIndexes (for cards[index]) we
 * could store pointers to that card, but it's easier using the indexes
 * for e.g. cross referencing Choice.values[index]. 
 */
struct Choice {
    /* Indexes of each card in the global cards[] array, with -1
     * meaning no card.
     */
    uint8_t cardOneIndex;
    uint8_t cardTwoIndex;
    uint8_t cardThreeIndex;
    /* Score/weight for playing each of the 24 possible cards.
     * Default value is BASE_VALUE for each.
     */
    int scores[24];
};

#endif
