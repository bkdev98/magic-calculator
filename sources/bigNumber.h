#include <stdio.h>
#include <string.h>

int isBigger(char st1[], char st2[]) {
  if (strlen(st1) > strlen(st2))
    return 1;
  else if (strlen(st1) < strlen(st2))
    return -1;
  else for (int i = 0; i <= strlen(st1) - 1; i++)
    if (st1[i] > st2[i])
      return 1;
    else if (st1[i] < st2[i])
      return -1;
  return 0;
}

char *bigAdd (char st1[], char st2[]) {
  char static stRes[1000];
  stRes[0] = '1';
  stRes[1] = '\0';
  return stRes;
}
char *bigSub (char st1[], char st2[]) {
  char static stRes[1000];
  stRes[0] = '1';
  stRes[1] = '\0';
  return stRes;
}
char *bigMul (char st1[], char st2[]) {
  char static stRes[1000];
  stRes[0] = '1';
  stRes[1] = '\0';
  return stRes;
}
char *bigDiv (char st1[], char st2[]) {
  char static stRes[1000];
  stRes[0] = '1';
  stRes[1] = '\0';
  return stRes;
}
char *bigMod (char st1[], char st2[]) {
  char static stRes[1000];
  stRes[0] = '1';
  stRes[1] = '\0';
  return stRes;
}
/*
int main(void) {
  char st1[1000], st2[1000];
  scanf("%s", st1);
  scanf("%s", st2);
  printf("(+) = %s\n", bigAdd(st1, st2));
  printf("(-) = %s\n", bigSub(st1, st2));
  printf("(*) = %s\n", bigMul(st1, st2));
  printf("(/) = %s\n", bigDiv(st1, st2));
  printf("(M) = %s\n", bigMod(st1, st2));
  return 0;
}
*/
