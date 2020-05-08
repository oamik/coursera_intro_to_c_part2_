#include <stdio.h>
#include <stdlib.h>


void rotate(int matrix[10][10]){
	char temp[10][10];
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
		  	temp[j][9-i] = matrix[i][j];
		}
	}
	for(int i = 0; i < 10; ++i)
	{
	  	for(int j = 0; j < 10; ++j)
		{
		  matrix[i][j] = temp[i][j];
		}
	}
}


int main(int argc, char const *argv[])
{
	if (argc != 2) {    
	    fprintf(stderr,"Usage: rotate inputFileName\n");    
	    return EXIT_FAILURE;  
	  }  
	FILE * f = fopen(argv[1], "r");
	int a[10][10];
	
	if (f == NULL) {
    	perror("Could not open file");    
		exit(EXIT_FAILURE);
	}

	int c;
	while ( (c=fgetc(f)) != EOF ) {
	  for (int i = 0; i < 10; ++i)
	  {
	  	for (int j = 0; i < 10; ++j)
	  	{
	  		a[i][j] = c;
	  	}
	  }
	}

	if (fclose(f) != 0) {    
    	perror("Failed to close the input file!");    
	    return EXIT_FAILURE;  
	}  

	rotate(a);

	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			printf("%c", a[i][j]);
		}
	}



  	return EXIT_SUCCESS;
}
