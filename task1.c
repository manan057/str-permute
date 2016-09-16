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

int main() {
  char str1[] = "ABC";
  permute(str1, 0, strlen(str1));
  return 0;
}
