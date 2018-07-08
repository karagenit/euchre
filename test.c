#include "test.h"

int main() {
    Choices choices;
    getChoices(choices); // TODO: rename init

    assert(choices[0].scores[0] == BASE_VALUE);
    assert(choices[0].cardOneIndex == -1);

    printf("Tests passed.\n");
    return 0;
}
