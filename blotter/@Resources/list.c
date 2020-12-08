
#include <stdio.h>
void pr(int x, int i){while(x>i){printf("%i ", ++i);}}
void main(int argc, char* argv[]){(!argv[1] || !(atoi(argv[1]))) ? printf("enter a  positive number when running the program\n") : pr(atoi(argv[1]), 0);}

