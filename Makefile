
all: output

output: main.c lista_concatenata.c
	gcc -O2 -std=c99 --pedantic -Wall *.c -o iap