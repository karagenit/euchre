#include "euchre.h"

void main() {
    struct Choice *choices = getChoices();
    printf("%d\n", choices[0].scores[0]);
    free(choices);
}
