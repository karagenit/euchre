#ifndef _SIMULATE_H_
#define _SIMULATE_H_

#include <stdint.h>
#include <stdbool.h>

#include "choices.h"
#include "cards.h"

// number of cards per hand
#define HAND_SIZE 5
// number of hands i.e. number of players, number of plays per trick
#define HAND_CNT 4

typedef int Hand[HAND_SIZE];

typedef Hand Hands[HAND_CNT];

typedef struct Trick {
    int8_t cardIndices[HAND_CNT];
    bool teamAWon;
} Trick;

typedef Trick Decisions[5];

void simulate(Choices choices);
void initHands(Hands hands);
void initDecisions(Decisions decisions);
void simulateHands(Hands hands, Decisions decisions);
void simulateHand(Hands hands, Trick *trick);
void simulatePlay(Hand hand, Trick *trick);
int getTeamAPoints(Decisions decisions);

#endif
