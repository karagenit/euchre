FILES = cards.c choices.c
TESTFILES = test.c $(FILES)
SIMFILES = euchre.c $(FILES)

main: $(SIMFILES)
	gcc -o euchre $(SIMFILES)

test: $(TESTFILES)
	gcc -o test $(TESTFILES)
	./test
