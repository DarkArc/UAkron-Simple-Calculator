unsigned long strlen(const char* str) {
  unsigned long i;
  for (i = 0; 1; ++i) {
    if (str[i] == '\0') {
      break;
    }
  }
  return i;
}

int strcmp(const char* str1, const char* str2) {
  unsigned long i = 0;
  int returnVal;

  loop:
    returnVal = str1[i] - str2[i];

    if (returnVal || !str1[i] || !str2[i]) {
      goto end;
    }

    ++i;

    goto loop;

  end:
    return returnVal;
}


char* strcpy(char* dest, const char* src) {
  unsigned long i;
  for (i = 0; src[i] != '\0'; ++i) {
    dest[i] = src[i];
  }
  return dest;
}

#include <stdio.h>

int main() {
  char aStr[10] = "Bob\0";
  char bStr[10] = "Bob v\0";

  int len = (int) (strlen(aStr));
  printf("%d\n", len);

  int cmp = strcmp(aStr, bStr);
  printf("%d\n", cmp);

  strcpy(aStr, bStr);
  printf("%s\n", bStr);
}
