#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 12	// 10 chars + \n + \0



void rotate(char matrix[10][10]){

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
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s FileName.\n", argv[0] );
		return EXIT_FAILURE;
	}

	FILE *f = fopen(argv[1], "r");

	if (f == NULL)
	{
		fprintf(stderr, "Could not open file %s.\n", argv[1]);
		return EXIT_FAILURE;
	}

	char line[LINE_SIZE];
	char m[10][10];
	int i;

	for(i = 0; fgets(line, LINE_SIZE, f) != NULL; i++)
	{
		// printf("line size: %ld\n", strlen(line) );
		if (strlen(line) < 11)
		{
			fprintf(stderr, "Line is too short!\n");
			return EXIT_FAILURE;
		}
		if (i > 9)
		{
			fprintf(stderr, "The are more than %d lines!\n", 10);
			return EXIT_FAILURE;
		}
		if (strchr(line, '\n') == NULL)
		{
			fprintf(stderr, "Line is too long!\n");
			return EXIT_FAILURE;
		}
		strncpy(m[i], line, 10);
	}
	if (i < 10)
	{
		fprintf(stderr, "The are less than %d lines!\n", 10);
		return EXIT_FAILURE;
	}

	rotate(m);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%c", m[i][j] );
		}
		printf("\n");
	}


	return EXIT_SUCCESS;
}

