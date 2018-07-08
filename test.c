#include "test.h"

int main() {
    srand(time(NULL));

    Choices choices;
    getChoices(choices); // TODO: rename init

    assert(choices[0].scores[0] == BASE_VALUE);
    assert(choices[0].cardOneIndex == -1);

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

    printf("Tests passed.\n");
    return 0;
}
