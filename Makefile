
all: output

output:
	gcc -O2 -std=c99 --pedantic -Wall sorgenti/*.c -o iap