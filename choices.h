#ifndef _CHOICES_H_
#define _CHOICES_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "cards.h"

#define BASE_VALUE 10000
#define CHOICES 12721 // (1) + (24) + (24 * 23) + (24 * 23 * 22)

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
    int8_t cardOneIndex;
    int8_t cardTwoIndex;
    int8_t cardThreeIndex;
    /* Score/weight for playing each of the 24 possible cards.
     * Default value is BASE_VALUE for each.
     */
    int scores[CARDS];
};

struct Choice* getChoices();
void setChoiceIndices(struct Choice *choices, int index, int one, int two, int three);
void toFile(struct Choice *choices, char *filename);
struct Choice* fromFile(char *filename);

#endif
