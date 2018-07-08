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

typedef struct Play {
    /* Card #s of the previous 0-3 cards
     * that were played in this trick.
     */
    int8_t previousCardIndices[3];
    /* Card # of the card that was played here.
     */
    int8_t cardIndex;
    /* Whether this play was for team A (as opposed
     * to team B).
     */
    bool teamA; // just do cards[4], teamALead bool
} Play;

typedef struct Trick {
    Play plays[HAND_CNT]; // winner is highest trump then highest of lead suit
    bool teamAWon;
} Trick;

typedef Trick Decisions[5];

void simulate(Choices choices);
void initHands(Hands hands);
void initDecisions(Decisions decisions);
void simulateHands(Hands hands, Decisions decisions);
void simulateHand(Hands hands, Trick *trick);
void simulatePlay(Hand hand, Play *play);
int getTeamAPoints(Decisions decisions);

#endif
