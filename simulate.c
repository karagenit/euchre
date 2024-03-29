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

    updateChoices(choices, decisions);
}

void updateChoices(Choices choices, Decisions decisions) {
    int teamAPoints = getTeamAPoints(decisions);

    // update choices scores
    for (int i = 0; i < HAND_SIZE; i++) {
        int leaderPoints;

        // if team A lead
        if (decisions[i].leadingHand % 2 == 0) {
            leaderPoints = teamAPoints;
        } else {
            leaderPoints = -teamAPoints;
        }

        // find choice index for each of the 4 combos
        CardIndex firstCard = decisions[i].cardIndices[0];
        CardIndex secondCard = decisions[i].cardIndices[1];
        CardIndex thirdCard = decisions[i].cardIndices[2];
        CardIndex fourthCard = decisions[i].cardIndices[3];

        // TODO: check for null?
        findChoice(choices, -1, -1, -1)->scores[firstCard] += leaderPoints;
        findChoice(choices, firstCard, -1, -1)->scores[secondCard] -= leaderPoints;
        findChoice(choices, firstCard, secondCard, -1)->scores[thirdCard] += leaderPoints;
        findChoice(choices, firstCard, secondCard, thirdCard)->scores[fourthCard] += leaderPoints;
    }
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
        decisions[i].winningHand = -1;
        decisions[i].leadingHand = -1;
        for (int j = 0; j < HAND_CNT; j++) {
            decisions[i].cardIndices[j] = -1;
        }
    }
    decisions[0].leadingHand = 0;
}

void simulateHands(Hands hands, Decisions decisions) {
    // leading hand starts at index 0, moves to whoever wins each hand
    for (int i = 0; i < HAND_SIZE; i++) {
        simulateHand(hands, &(decisions[i]));
        decisions[i].winningHand = getWinningCardIndex(decisions[i].cardIndices);
        if (i < HAND_SIZE - 1) {
            decisions[i+1].leadingHand = decisions[i].winningHand;
        }
    }
}

void simulateHand(Hands hands, Trick *trick) {
    for (int i = 0; i < HAND_CNT; i++) {
        int idx = (i + trick->leadingHand) % HAND_CNT;
        simulatePlay(hands[idx], trick);
    }
}

int getWinningCardIndex(CardIndex playedCards[HAND_CNT]) {
    // "highest" suit - starts as lead suit but may be overridden by trump suit
    Suit highestSuit = cards[playedCards[0]].suit;
    Rank highestRank = cards[playedCards[0]].rank;
    int index = 0;

    // we can skip the first card here
    for (int i = 1; i < HAND_CNT; i++) {
        if (cards[playedCards[i]].suit == 1) {
            highestSuit = 1;
        }
        if (cards[playedCards[i]].suit == highestSuit) {
            if (cards[playedCards[i]].rank < highestRank) {
                index = i;
                highestRank = cards[playedCards[i]].rank;
            }
        }
    }
    return index;
}

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
    // we lead, we can play any card
    if (leadSuit == -1) {
        return;
    }

    // if we don't have any of the lead suit, we can play any card
    bool noneOfSuit = true;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand[i] == -1) {
            continue;
        }
        if (cards[hand[i]].suit == leadSuit) {
            noneOfSuit = false;
            break;
        }
    }
    if (noneOfSuit) {
        return;
    }

    // remove non-valid cards
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand[i] == -1) {
            continue;
        }
        if (cards[hand[i]].suit != leadSuit) {
            hand[i] = -1;
        }
    }
}

int getTeamAPoints(Decisions decisions) {
    int teamAScore = 0;

    // TODO: build this into the Decisions struct + simulateHand function?
    for (int i = 0; i < 5; i++) {
        bool leaderWon = (decisions[i].winningHand % 2) == (decisions[i].leadingHand % 2);
        bool teamALead = (decisions[i].leadingHand % 2) == 0;
        // if either: (A lead and leader won) or (A didn't lead and leader lost)
        if (leaderWon == teamALead) {
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
