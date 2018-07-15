FILES = cards.c choices.c simulate.c
TESTFILES = test.c $(FILES)
SIMFILES = euchre.c $(FILES)
PLAYFILES = play.c $(FILES)

build: $(SIMFILES)
	gcc -o euchre $(SIMFILES)
	gcc -o play $(PLAYFILES)

test: $(TESTFILES)
	gcc -g -o test $(TESTFILES)

clean:
	rm test euchre test_choices.db
