 all:
	g++ -g -Wall -Werror -Wextra -Wpedantic -Wno-error=unused-function main.cpp ./fileInput/fileInputTreatment.cpp ./SortingAlg/sort.cpp ./StrFuncs/strlibMy.cpp -o onegin.out
	
