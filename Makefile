FILES = euchre.c cards.c

main: $(FILES)
	gcc -o euchre $(FILES)
