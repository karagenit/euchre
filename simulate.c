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

void initHands(Hands hands) {}

void initDecisions(Decisions decisions) {}

void simulateHands(Hands hands, Decisions decisions) {}

void simulateHand(Hands hands, Trick *trick) {}

void simulatePlay(Hand hand, Trick *trick) {}

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
