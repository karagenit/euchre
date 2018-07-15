#include "simulate.h"

/* NOTE: edits Choices in place
 */
void simulate(Choices choices) {
    Hands hands;
    initHands(hands);

    Decisions decisions;
    initDecisions(decisions);

    // TODO: use previous success/failure of choices to determine decision
    simulateHands(hands, decisions);

    // teamBPoints = -teamAPoints;
    int teamAPoints = getTeamAPoints(decisions);

    // update choices scores
}

void initHands(Hands hands) {
    // set all hands to -1
    for (int i = 0; i < HAND_CNT * HAND_SIZE; i++) {
        int row = i / HAND_SIZE;
        int col = i % HAND_SIZE;
        hands[row][col] = -1;
    }
    // create array for shuffled cards
    int shuffled[CARDS];
    for (int i = 0; i < CARDS; i++) {
        shuffled[i] = -1;
    }
    // shuffle cards
    for (int card = 0; card < CARDS; card++) {
        int idx = rand() % CARDS; // 0 - 23
        while (shuffled[idx] != -1) {
            idx = (idx + 1) % CARDS;
        }
        shuffled[idx] = card;
    }
    // set hands to first 20 of shuffled
    for (int i = 0; i < HAND_CNT * HAND_SIZE; i++) {
        int row = i / HAND_SIZE;
        int col = i % HAND_SIZE;
        hands[row][col] = shuffled[i];
    }
}

void initDecisions(Decisions decisions) {
    for (int i = 0; i < HAND_SIZE; i++) {
        decisions[i].teamAWon = false;
        for (int j = 0; j < HAND_CNT; j++) {
            decisions[i].cardIndices[j] = -1;
        }
    }
}

void simulateHands(Hands hands, Decisions decisions) {}

void simulateHand(Hands hands, Trick *trick) {}

void simulatePlay(Hand hand, Trick *trick) {
    // get valid plays
    Hand plays;
    memcpy(plays, hand, HAND_SIZE);
    getValidPlays(plays, trick->cardIndices[0]);

    // randomly select one
    int idx = rand() % HAND_SIZE;
    while (plays[idx] == -1) {
        idx = (idx + 1) % HAND_SIZE;
    }

    // remove card from our hand, put into trick history
    for (int i = 0; i < HAND_CNT; i++) {
        if (trick->cardIndices[i] == -1) {
            trick->cardIndices[i] = plays[idx];
            break;
        }
    }
    hand[idx] = -1;
}

void getValidPlays(Hand hand, Suit leadSuit) {
    if (leadSuit == -1) {
        return;
    }
    for (int i = 0; i < HAND_SIZE; i++) {
        if (cards[hand[i]].suit != leadSuit) {
            hand[i] = -1;
        }
    }
}

int getTeamAPoints(Decisions decisions) {
    int teamAScore = 0;

    // TODO: build this into the Decisions struct + simulateHand function?
    for (int i = 0; i < 5; i++) {
        if (decisions[i].teamAWon) {
            teamAScore++;
        }
    }

    switch(teamAScore) {
        case 5:
            return 2;
        case 4:
        case 3:
            return 1;
        case 2:
        case 1:
            return -1;
        case 0:
            return -2;
        default:
            // uh oh...
            return 0;
    }
}
