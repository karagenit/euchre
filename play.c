#include "play.h"

void main() {
    Choices choices;
    initChoices(choices);
    fromFile(choices, "data.db");

    Choice *choice = findChoice(choices, -1, -1, -1);

    printf("Play Strenghts of Leading Cards\n");
    printf("Right Trump: %d\n", choice->scores[0]);
    printf("Low Trump: %d\n", choice->scores[6]);
    printf("Off Ace: %d\n", choice->scores[7]);
    printf("Different Off Ace: %d\n", choice->scores[12]);
    printf("Throw off: %d\n", choice->scores[11]);
}
