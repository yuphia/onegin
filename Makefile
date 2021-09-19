all:
	g++ -g -Wall -Werror -Wextra -Wpedantic -Wno-unused-parameter -Wno-error=unused-function main.cpp sort.c strlibMy.c -o onegin.out
