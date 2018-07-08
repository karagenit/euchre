#include "choices.h"

Choice* getChoices(Choices choices) {
    // set all base scores
    for (int i = 0; i < CHOICES; i++) {
        for (int j = 0; j < CARDS; j++) {
            choices[i].scores[j] = BASE_VALUE;
        }
    }

    int choiceIndex = 0;
    // TODO: set played cards
    for (int i = -1; i < CARDS; i++) {
        if (i == -1) {
            setChoiceIndices(choices, choiceIndex, -1, -1, -1);
            choiceIndex++;
            continue;
        }
        for (int j = -1; j < CARDS; j++) {
            if (j == -1) {
                setChoiceIndices(choices, choiceIndex, i, -1, -1);
                choiceIndex++;
                continue;
            }
            if (i == j) {
                continue;
            }
            for (int k = -1; k < CARDS; k++) {
                if (i == k || j == k) {
                    continue;
                }
                // don't need to check k == -1, cause there aren't any past that
                setChoiceIndices(choices, choiceIndex, i, j, k);
                choiceIndex++;
            }
        }
    }

    return choices;
}

void setChoiceIndices(Choices choices, int index, int one, int two, int three) {
    choices[index].cardOneIndex = one;
    choices[index].cardTwoIndex = two;
    choices[index].cardThreeIndex = three;
}

void toFile(Choices choices, char *filename) {
    // TODO: simply write values for "scores", as the rest (the indexes) are always the same.
}

Choice* fromFile(char *filename) {
    // TODO
}
