/*
  Name: Manan Rana
  StudentID: 26030888
  Start Date: 5/9/16
  Last Modified: 16/9/16
  Progam Description: for a given string of length n this program will print
                      n! permutations regardless of having duplicates



*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
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
  int pid;
  for (int i = 0; i < n; i++) {
    pid=fork();             /* fork a child process */
    if (pid > 0) {          /* parent continues here */
      // system("ps -el");
      // count(start, 'P');
      printf("\n");
      // wait(NULL);           /* to get all printing done before shell prompt shows*/
    } else if (pid == 0) {  /* child got here! */
      clock_t begin = clock();
      permute(argv[2+i], 0, strlen(argv[2+i]));
      clock_t end = clock();
      double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
      printf("%f\n", time_spent);
      exit(0);
    } else {                /* only if there was a problem with fork */
      printf("Failed to fork a process \n");
      exit(-1);
    }
  }
  return 0;
}
