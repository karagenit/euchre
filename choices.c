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
            setChoiceIndices(&(choices[choiceIndex]), -1, -1, -1);
            choiceIndex++;
            continue;
        }
        for (int j = -1; j < CARDS; j++) {
            if (j == -1) {
                setChoiceIndices(&(choices[choiceIndex]), i, -1, -1);
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
                setChoiceIndices(&(choices[choiceIndex]), i, j, k);
                choiceIndex++;
            }
        }
    }

    return choices;
}

void setChoiceIndices(Choice *choice, int one, int two, int three) {
    choice->playedCards[0] = one;
    choice->playedCards[1] = two;
    choice->playedCards[2] = three;
}

int findChoiceIndex(Choices choices, CardIndex one, CardIndex two, CardIndex three) {
    for (int i = 0; i < CHOICES; i++) {
        if (choices[i].playedCards[0] == one &&
            choices[i].playedCards[1] == two &&
            choices[i].playedCards[2] == three) {
                return i;
        }
    }
    return -1;
}

void toFile(Choices choices, char *filename) {
    // TODO: simply write values for "scores", as the rest (the indexes) are always the same.
}

Choice* fromFile(char *filename) {
    // TODO
}
