first: first.c
	gcc -Wall -Werror -o first first.c -lm
clean:
	rm first
