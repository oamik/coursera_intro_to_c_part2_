#include <stdlib.h>

unsigned power( unsigned x, unsigned y );

int main(){

  if(power(0, 0) != 1)
    exit(EXIT_FAILURE);
  if(power(3, 1) != 3)
    exit(EXIT_FAILURE);
  if(power(2, 5) != 32)
    exit(EXIT_FAILURE);
  if(power(0, 8) != 0)
    exit(EXIT_FAILURE);
  if(power(10, 9) != 1000000000)
    exit(EXIT_FAILURE);

  return EXIT_SUCCESS;
}
