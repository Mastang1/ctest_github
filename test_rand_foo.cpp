/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main ()
{
  int iSecret, iGuess;
  int iGuessTime = 0;

  /* initialize random seed: */
  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  iSecret = rand() % 13 + 1;

  do {
    printf ("Guess the number (1 to 10): ");
    scanf ("%d",&iGuess);
    if (iSecret<iGuess) puts ("The secret number is lower");
    else if (iSecret>iGuess) puts ("The secret number is higher");

    if(iGuessTime < 2){
        iGuessTime++;
    }else{
        puts ("game over");
        return 0;
    }
  } while (iSecret!=iGuess);

  puts ("Congratulations!");
  return 0;
}