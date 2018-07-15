#include "euchre.h"

void main() {
    srand(time(NULL));

    Choices choices;
    initChoices(choices);

    for (int i = 0; i < 1000000; i++) {
        simulate(choices);
    }

    toFile(choices, "data.db");
}
