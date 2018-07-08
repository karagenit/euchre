#include "test.h"

int main() {
    struct Choice *choices = getChoices();

    assert(choices[0].scores[0] == BASE_VALUE);
    assert(choices[0].cardOneIndex == -1);
    
    free(choices);

    printf("Tests passed.\n");
    return 0;
}
