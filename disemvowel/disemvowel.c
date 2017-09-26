#include <stdlib.h>
#include <stdio.h>
#include "disemvowel.h"
#include <string.h>
 
int isVowel(char character);

char* disemvowel(char* str) {
  int m = 0;
  int len;
  len = strlen(str);  
  char* noVowels;
  noVowels = (char*)calloc(len + 1,sizeof(char)); 

  for(int i = 0;str[i] != '\0'; i++){
   if(!(isVowel(str[i]))){
     noVowels[m] = str[i];
     m++;
     }
  }
  noVowels[m] = '\0';
  return noVowels;
}

int isVowel(char character){
	switch(character){
	    case 'a':
            case 'e':
            case 'u':
            case 'i':
            case 'o':
            case 'A':
	    case 'E':
            case 'U':
            case 'I':
	    case 'O':
            return 1;
	    default:
	    return 0;
	}         
}
