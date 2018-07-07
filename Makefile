FILES = euchre.c cards.c choices.c

main: $(FILES)
	gcc -o euchre $(FILES)
