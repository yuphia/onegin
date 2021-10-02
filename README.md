## ONEGIN, a programm for sorting text files

#H1 Table of contents

1. Starting and downloading
2. Concepts used in the program
3. Compatibility



#H3 1. Starting and downloading

    First you have to download all the files in this repo except the build repository
    
    Than you should run the program from the command line:
    1) You have to change your current repository using "cd"
    2) You compile the program using the "make" command
    3) Run it using command ./build/onegin.out "input.txt" "output.txt"

#H3 2. Concepts used in the program

    The program opens your files and converts your text file into an array of special struct Line
    this struct consists of a pointer to a line and a lineSize variable
    
    While sorting this program ignores all empty lines and characters that are not letters
    
    The sorting function is qsort from standart library

#H3 3. Compatibility

    The program only works for english characters and .txt files
