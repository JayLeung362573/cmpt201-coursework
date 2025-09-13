#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
  char *buff = NULL;
  size_t size = 0;
  ssize_t num_char;

  fputs("Enter a line: ", stdout);
  num_char = getline(&buff, &size, stdin);

  if (num_char == -1) {
    perror("getline failed");
    free(buff);
    exit(EXIT_FAILURE);
  }

  printf("Your entered: \"%s\"\n", buff);

  const char *delim = " ";
  char *saveptr = NULL;
  char *ret = strtok_r(buff, delim, &saveptr);

  while (ret != NULL) {
    printf("token: \"%s\"\n", ret);
    ret = strtok_r(NULL, delim, &saveptr);
  }

  free(buff);
  return EXIT_SUCCESS;
}
