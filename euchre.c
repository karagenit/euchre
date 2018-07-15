#include "euchre.h"

void main() {
    srand(time(NULL));

    Choices choices;
    getChoices(choices);

    for (int i = 0; i < 100000; i++) {
        simulate(choices);
    }
}
