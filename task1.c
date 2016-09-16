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
  char str2[] = "AAA";
  char str3[] = "A1B2";
  char str4[] = "AABC";
  char str5[] = "TO-DO";
  char str6[] = "PROGRAM";
  char str7[] = "OPERATING SYSTEMS";

  // print permutations for str1
  printf("*** Printing permutations for: %s ***\n", str1);
  sleep(1);
  permute(str1, 0, strlen(str1));
  for (int i = 5; i > 0 ; i--) {
    printf("*** Clearing in %d seconds! ***\n", i);
    sleep(1);
  }
  system("clear");

  // print permutations for str2
  printf("*** Printing permutations for: %s ***\n", str2);
  sleep(2);
  permute(str2, 0, strlen(str2));
  for (int i = 5; i > 0 ; i--) {
    printf("*** Clearing in %d seconds! ***\n", i);
    sleep(1);
  }
  system("clear");

  // print permutations for str3
  printf("*** Printing permutations for: %s ***\n", str3);
  sleep(2);
  permute(str3, 0, strlen(str3));
  for (int i = 5; i > 0 ; i--) {
    printf("*** Clearing in %d seconds! ***\n", i);
    sleep(1);
  }
  system("clear");

  // print permutations for str4
  printf("*** Printing permutations for: %s ***\n", str4);
  sleep(2);
  permute(str4, 0, strlen(str4));
  for (int i = 5; i > 0 ; i--) {
    printf("*** Clearing in %d seconds! ***\n", i);
    sleep(1);
  }
  system("clear");

  // print permutations for str5
  printf("*** Printing permutations for: %s ***\n", str5);
  sleep(2);
  permute(str5, 0, strlen(str5));
  for (int i = 5; i > 0 ; i--) {
    printf("*** Clearing in %d seconds! ***\n", i);
    sleep(1);
  }
  system("clear");

  // print permutations for str5
  printf("*** Printing permutations for: %s ***\n", str6);
  sleep(2);
  permute(str6, 0, strlen(str6));
  for (int i = 5; i > 0 ; i--) {
    printf("*** Clearing in %d seconds! ***\n", i);
    sleep(1);
  }
  system("clear");

  // -- Too time consuming --
  // print permutations for str5
  // printf("*** Printing permutations for: %s ***\n", str7);
  // sleep(2);
  // permute(str7, 0, strlen(str7));
  // for (int i = 5; i > 0 ; i--) {
  //   printf("*** Clearing in %d seconds! ***\n", i);
  //   sleep(1);
  // }
  // system("clear");

  printf("------- Good Bye ------\n");
  return 0;
}
