all:
	g++ -g -Wall -Werror -Wextra -Wpedantic -Wno-error=unused-function main.cpp sort.c strlibMy.c -o onegin.out
