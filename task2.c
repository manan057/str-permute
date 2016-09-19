/*
  Name: Manan Rana
  StudentID: 26030888
  Start Date: 5/9/16
  Last Modified: 16/9/16
  Progam Description: this program takes in a sequence of command-line arguments
                      with the first argument denoting the number of child processes
                      to be created (n), and followed by the list of strings as
                      the arguments for the permutation function invoked by each
                      of the child processes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

/* function that swaps the values of two pointers */
void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

/* function which prints all the permutations of a string using backtrack */
void permute(char *str, int start_index, int end_index) {
  if (start_index == end_index) {
    printf("%s\n", str);
  } else {
    for (int i = start_index; i < end_index; i++) {
      swap((str + start_index), (str + i));
      permute(str, start_index + 1, end_index);
      swap((str + start_index), (str + i));       //backtrack
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {                       // check to see if 3 arguments are provided
    printf("Please provide the following command line arguments: ./program N[processes] S1[string] S2 .. SN\n");
    printf("eg: ./program 2 abc patato\n");
  } else {
    if (isdigit(atoi(argv[1])) != 0) {  // check if N is a number
      printf("The second command argument is NOT a number!\n");
    } else {
      int n = atoi(argv[1]);
      // printf("%d\n", n);
      int n_args = argc;
      // printf("%d\n", n_args);
      if (n != (n_args-2)) {           // check to see if N matches with the number of strings provided
         printf("Insufficient number of string arguments supplied\n");
      } else {
        // Running the time tests
        // FILE *fp;
        // fp = fopen("/time-stats.txt", "w+");
        // for (int t = 0; t < 5; t++) {

          int pid;
          for (int i = 0; i < n; i++) {
            pid=fork();             /* fork a child process */
            if (pid > 0) {          /* parent continues here */
              // system("ps -el");
              printf("\n");
              // wait(NULL);           /* to get all printing done before shell prompt shows*/
            } else if (pid == 0) {  /* child got here! */
              clock_t begin = clock();
              permute(argv[2+i], 0, strlen(argv[2+i]));
              clock_t end = clock();
              double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
              printf("--- This process took: %fs ---\n", time_spent);

              // char str[] = "-- Test: ";
              // strcat(str, itoa(t));
              // strcat(str, "; String: ");
              // strcat(str, argv[2+i]);
              // strcat(str, "; Time: ");
              // strcat(str, itoa(time_spent));
              // strcat(str, " --\n");
              // fputs(str, fp);

              exit(0);
            } else {                /* only if there was a problem with fork */
              printf("Failed to fork a process!\n");
              exit(-1);
            }
          }

        // }
        // fclose(fp);

      }
    }
  }
  return 0;
}
