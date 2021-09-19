 all:
	g++ -g -Wall -Werror -Wextra -Wpedantic -Wno-error=unused-function main.cpp ./SortingAlg/sort.c ./StrFuncs/strlibMy.c -o onegin.out
	
