#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}

//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void printLines(char **arr, size_t size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%s", arr[i]);
	}
}

void freeLines(char **arr, size_t size)
{
	
	for (int i = 0; i < size; ++i)
	{
		free(arr[i]);
	}
}

size_t readLines(char **arr, FILE *inFile)
{
	char *line = NULL;
	size_t sz = 0;
	size_t cap = 10;
	size_t size = 0;

	for(int i = 0; getline(&line, &sz, inFile) >= 0; ++i)
	{
		size++;
		if (size == cap)
		{
			cap = 2 * size;
			arr = realloc(arr, cap * sizeof(* arr));
		}
		arr[i] = malloc((strlen(line)+1) * sizeof(**arr));
		strcpy(arr[i], line);
	}
	free(line);

	return size;
}

int main(int argc, char ** argv) {
	
  char **arr = NULL;// = malloc(10 * sizeof(* arr));
	
	if (argc == 1)
	{
	  arr = malloc(10 * sizeof(*arr));
		size_t size = readLines(arr, stdin);
		sortData(arr, size);
		printLines(arr, size);
		freeLines(arr, size);
		free(arr);
	}
	else
	{
		for (int i = 1; i < argc; ++i)
		{
	    
			FILE *f = fopen(argv[i], "r");
			if (f == NULL)
			{
				perror("Could not open the file!\n");
				//	free(arr);

				return EXIT_FAILURE;
			}
			arr = malloc(10 * sizeof(*arr));
			size_t size = readLines(arr, f);
			sortData(arr, size);
			printLines(arr, size);
			freeLines(arr, size);
			free(arr);
			fclose(f);
		}
	}


	return EXIT_SUCCESS;
}
