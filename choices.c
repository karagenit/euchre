#include "choices.h"

struct Choice* getChoices() {
    struct Choice *choices = malloc(sizeof(struct Choice) * CHOICES);

    // set all base scores
    for (int i = 0; i < CHOICES; i++) {
        for (int j = 0; j < CARDS; j++) {
            choices[i].scores[j] = BASE_VALUE;
        }
    }

    // TODO: set played cards

    return choices;
}
