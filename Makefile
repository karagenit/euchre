FILES = cards.c choices.c
TESTFILES = test.c $(FILES)
SIMFILES = euchre.c $(FILES)

build: $(SIMFILES)
	gcc -o euchre $(SIMFILES)

test: $(TESTFILES)
	gcc -o test $(TESTFILES)
	./test

clean:
	rm test euchre
