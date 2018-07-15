#ifndef _SIMULATE_H_
#define _SIMULATE_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "choices.h"
#include "cards.h"

// number of cards per hand
#define HAND_SIZE 5
// number of hands i.e. number of players, number of plays per trick
#define HAND_CNT 4

typedef CardIndex Hand[HAND_SIZE];

typedef Hand Hands[HAND_CNT];

typedef struct Trick {
    CardIndex cardIndices[HAND_CNT];
    /*
     * Team A is Hand Indices 0 and 2 (the even indices)
     */
    bool teamAWon;
} Trick;

typedef Trick Decisions[HAND_SIZE];

void simulate(Choices choices);
void initHands(Hands hands);
void initDecisions(Decisions decisions);
void simulateHands(Hands hands, Decisions decisions);
void simulateHand(Hands hands, Trick *trick, int leadingHand);
int getWinningCardIndex(CardIndex playedCards[HAND_CNT]); // TODO: typedef CardIndex Table[CNT]?
void simulatePlay(Hand hand, Trick *trick);
/*
 * WARNING: modifies the Hand array (replaces invalid plays
 * with -1) so you likely want to clone your Hand and pass that.
 */
void getValidPlays(Hand hand, Suit leadSuit);
int getTeamAPoints(Decisions decisions);

#endif
