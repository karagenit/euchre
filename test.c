#include "test.h"

void test_getWinningCardIndex() {
    CardIndex cardsA[HAND_CNT] = { 7, 8, 9, 10 };
    assert(getWinningCardIndex(cardsA) == 0);

    CardIndex cardsB[HAND_CNT] = { 7, 12, 18, 19 };
    assert(getWinningCardIndex(cardsB) == 0);

    CardIndex cardsC[HAND_CNT] = { 11, 10, 9, 8 };
    assert(getWinningCardIndex(cardsC) == 3);

    CardIndex cardsD[HAND_CNT] = { 7, 8, 1, 10 };
    assert(getWinningCardIndex(cardsD) == 2);
}

void test_simulatePlay() {
    Hand hand = {1, 1, 1, 2, 2};
    Decisions decisions;
    initDecisions(decisions);

    simulatePlay(hand, &(decisions[0]));

    int emptyCounts = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (hand[i] == -1) {
            emptyCounts++;
        }
    }
    assert(emptyCounts == 1);
    assert(decisions[0].cardIndices[0] == 1 || decisions[0].cardIndices[0] == 2);
}

void test_getChoices() {
    Choices choices;
    getChoices(choices); // TODO: rename init

    assert(choices[0].scores[0] == BASE_VALUE);
    assert(choices[0].cardOneIndex == -1);
}

void test_initHands() {
    Hands hands;
    initHands(hands);
//  for (int c = 0; c < HAND_CNT; c++) {
//      printf("Hand: ");
//      for (int r = 0; r < HAND_SIZE; r++) {
//          printf("%d ", hands[c][r]);
//      }
//      printf("\n");
//  }
    assert(hands[0][0] != -1);
}

void test_initDecisions() {
    Decisions decisions;
    initDecisions(decisions);
    assert(decisions[0].cardIndices[0] == -1);
}

void test_getValidPlays() {
    Hand hand = { 1, 1, 1, 1, 1 };
    assert(hand[0] == 1);
    getValidPlays(hand, -1);
    assert(hand[0] == 1);
    getValidPlays(hand, 1);
    assert(hand[0] == 1);
    getValidPlays(hand, 2);
    assert(hand[0] == -1);
}

int main() {
    srand(time(NULL));

    test_getChoices();
    test_initHands();
    test_initDecisions();
    test_getValidPlays();
    test_simulatePlay();
    test_getWinningCardIndex();

    printf("Tests passed.\n");
    return 0;
}
