#include "choices.h"

void initChoices(Choices choices) {
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
}

void setChoiceIndices(Choice *choice, CardIndex one, CardIndex two, CardIndex three) {
    choice->playedCards[0] = one;
    choice->playedCards[1] = two;
    choice->playedCards[2] = three;
}

Choice* findChoice(Choices choices, CardIndex one, CardIndex two, CardIndex three) {
    for (int i = 0; i < CHOICES; i++) {
        if (choices[i].playedCards[0] == one &&
            choices[i].playedCards[1] == two &&
            choices[i].playedCards[2] == three) {
                return &(choices[i]);
        }
    }
    return NULL;
}

// TODO: write to stderr, return -1 on failure
void toFile(Choices choices, char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error writing file.\n");
        return;
    }

    for (int i = 0; i < CHOICES; i++) {
        for (int j = 0; j < CARDS; j++) {
            putw(choices[i].scores[j], file);
        }
    }

    fclose(file);
}

void fromFile(Choices choices, char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error reading file.\n");
        return;
    }

    for (int i = 0; i < CHOICES; i++) {
        for (int j = 0; j < CARDS; j++) {
            choices[i].scores[j] = getw(file);
        }
    }

    fclose(file);
}
