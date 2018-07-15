#include "euchre.h"

void main() {
    srand(time(NULL));

    Choices choices;
    initChoices(choices);

    for (int i = 0; i < 100000; i++) {
        simulate(choices);
    }
}
