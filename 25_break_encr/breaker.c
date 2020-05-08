#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 26


void breaker(FILE * f) {    
  int c;
  int abc[SIZE];

  for (int i = 0; i < SIZE; ++i)
  {
    abc[i] = 0;
  }

  while ((c = fgetc(f)) != EOF) {        
    if (isalpha(c)) {          
      c = tolower(c);            
      c -= 'a';      
      abc[c]++;      
    }        
  }
  // find most_freq char ('e)
  int e = 0;
  for (int i = 0; i < SIZE; ++i)
  {
    if (abc[i] > abc[e])
    {
      e = i;
    }
  }

  // decrypt
  e += 'a';
  e -= 'e';
  if (e < 0)
  {
    e += 26;
  }
  printf("%d\n", e);
}

int main(int argc, char ** argv) {  
  if (argc != 2) {    
    fprintf(stderr,"Usage: breaker inputFileName\n");    
    return EXIT_FAILURE;  
  }  
  // int key = atoi(argv[1]);  
  // if (key == 0) {    
  //   fprintf(stderr,"Invalid key (%s): must be a non-zero integer\n", argv[1]);    
  //   return EXIT_FAILURE;  
  // }  
  FILE * f = fopen(argv[1], "r");  
  if (f == NULL) {    
    perror("Could not open file");    
    return EXIT_FAILURE;  
  } 

  breaker(f);  
  
  if (fclose(f) != 0) {    
    perror("Failed to close the input file!");    
    return EXIT_FAILURE;  
  }  
  return EXIT_SUCCESS;
}