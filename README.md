# euchre
Machine Learning to Play Euchre

## Design

Cards:

We are suit agnostic, so instead we use A (trump), B (same color as trump), C, and D. 

A: Right Left Ace King Queen 10 9
B: Ace King Queen 10 9
C: Ace King Queen Jack 10 9
D: Ace King Queen Jack 10 9

Simulations are done a la Monte Carlo, with hands randomly being dealt and playing essentially four instances of the ML against itself. Choices are recorded, and success/failure determines whether to weight that choice as +1 or -1.

The "learning" is essentially a choice database, as such:

|1st Card|2nd Card|3rd Card|RA Score|LA Score|...|
|---|---|---|---|---|---|
|AceB|X|X|1000|900|...|

Essentially, the list of cards is what has already been played up until your turn, and the scores represent the viability of each card you could play. (In practice, the bot picks from its hand and what is legally allowed e.g. following suit).

There are (24) + (24 * 23) + (24 * 23 * 22) = 12720 play combinations here, and with ~21 options to play from at any point, ~300,000 simulations necessary to hit every option.

## Later Things

- Farmers hand
- Going alone
- Calling/passing
