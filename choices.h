#ifndef _CHOICES_H_
#define _CHOICES_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "cards.h"

#define BASE_VALUE 0
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
typedef struct Choice {
    /* Indexes of each card in the global cards[] array, with -1
     * meaning no card.
     */
    CardIndex playedCards[3];
    /* Score/weight for playing each of the 24 possible cards.
     * Default value is BASE_VALUE for each.
     *
     * Be careful of integer overflows!
     */
    int16_t scores[CARDS];
} Choice;

/* Note: allocating this will take approx 650 KiB of memory,
 * so you *can* put it on the stack, but...
 *
 * Also note: this is an array, and thus a pointer. Treat it as such.
 */
typedef Choice Choices[CHOICES];

void initChoices(Choices choices);
void setChoiceIndices(Choice *choice, CardIndex one, CardIndex two, CardIndex three);
// TODO: easier to return Choice* ?
Choice* findChoice(Choices choices, CardIndex one, CardIndex two, CardIndex three);
void toFile(Choices choices, char *filename);
void fromFile(Choices choices, char *filename);

#endif
