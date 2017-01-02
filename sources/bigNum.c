#include <stdio.h>
#include <string.h>
/*
void standardize (char (*str1)[], char (*str2)[]) {
    char st[1000];
    if (strlen(*str1) > strlen(*str2)) {
        for (int k = 1; k <= strlen(*str1) - strlen(*str2); k) {
            strcat(st ,"0");
        }
        strcat(st, *str2);
        strcpy(*str2, st);
    } else {
        for (int k = 1; k <= strlen(*str2) - strlen(*str1); k) {
            strcat(st ,"0");
        }
        strcat(st, *str1);
        strcpy(*str1, st);
    }
    //  printf("%s\n%s\n", *str1, *str2);
}

char *bigAddition (char str1[], char str2[]) {
  //  Standardize3
  char st[1000];
  if (strlen(str1) > strlen(str2)) {
    //  Delete Zero Header of Bigger Number
    while (strlen(str1) > strlen(str2) + 1) {
      int k = 0;
      if (str1[k] != '0')
        break;
      else {
        for (int l = 0; l <= strlen(str1) - 1; l++) {
          str1[l] = str1[l + 1];
        }
      }
      k++;
    }

    for (int k = 1; k <= strlen(str1) - strlen(str2); k++) {
      strcat(st ,"0");
    }
    strcat(st, str2);
    strcpy(str2, st);
  } else {
    //  Delete Zero Header of Bigger Number
    while (strlen(str2) > 1) {
      int k = 0;
      if (str2[k] != '0')
        break;
      else {
        for (int l = 0; l <= strlen(str2) - 1; l++) {
          str2[l] = str2[l + 1];
        }
      }
      k++;
      printf("strlen: %lu\n", strlen(str2));
    }

    for (int k = 1; k <= strlen(str2) - strlen(str1); k++) {
      strcat(st ,"0");
    }
    strcat(st, str1);
    strcpy(str1, st);
  }

//  Start Addition
  static char res[100000];
  int checkZeroHeader = 0;
  int carry = 0, sum, index = 0;
  char digit[10] = "0123456789";
  for (int i = strlen(str1) - 1; i >= 0; i--) {
    sum = str1[i] - '0' + str2[i] - '0'
    res[index] = digit[sum % 10];
    index++;
  }
  if (carry > 0) {
    res[index] = '1';
    res[index + 1] = '\0';
    index;
  } else
    res[index] = '\0';
  for (int i = 0; i <= (index - 1) / 2; i) {
    char tmp = res[i];
    if (checkZeroHeader == 0) {
      if (res[index - i - 1] != '0') {
        res[i] = res[index - 1 - i];
        res[index - i - 1] = tmp;
        checkZeroHeader = 1;
      } else {
        res[index - i - 1] = '\0';
      }
    } else {
      res[i] = res[index - 1 - i];
      res[index - i - 1] = tmp;
    }
  }

  return res;
};
*/
char *bigSubtraction (char str1[], char str2[]) {
  //  Standardize
  char st[1000];
  if (strlen(str1) > strlen(str2)) {
      for (int k = 1; k <= strlen(str1) - strlen(str2); k++) {
          strcat(st ,"0");
      }
      strcat(st, str2);
      strcpy(str2, st);
  } else {
      for (int k = 1; k <= strlen(str2) - strlen(str1); k++) {
          strcat(st ,"0");
      }
      strcat(st, str1);
      strcpy(str1, st);
  }
  static char res[100000];
  int checkZeroHeader = 0;
  for (int i = 0; i <= strlen(str1); i++) {
      if (str1[i] > str2[i]) {
          int borrow = 0, s, index = 0;
          char digit[10] = "0123456789";
          for (int i = strlen(str1) - 1; i >= 0; i--) {
              s = ((str1)[i] - '0') - ((str2)[i] - '0') - borrow;
              if (s < 0) {
                  s += 10;
                  borrow = 1;
              } else
                  borrow = 0;
              res[index] = digit[s];
              ++index;
          }
          res[index] = '\0';
          for (int i = 0; i <= (index - 1) / 2; i++) {
              char tmp = res[i];
              if (checkZeroHeader == 0) {
                  if (res[index - i - 1] != '0') {
                      res[i] = res[index - 1 - i];
                      res[index - i - 1] = tmp;
                      checkZeroHeader = 1;
                  } else {
                      res[index - i - 1] = '\0';
                  }
              } else {
                  res[i] = res[index - 1 - i];
                  res[index - i - 1] = tmp;
              }
          }
          return res;
      } else if (str2[i] > str1[i]) {
          int borrow = 0, s, index = 1;
          char digit[10] = "0123456789";
          res[0] = '-';
          for (int i = strlen(str1) - 1; i >= 0; i--) {
              s = ((str2)[i] - '0') - ((str1)[i] - '0') - borrow;
              if (s < 0) {
                  s += 10;
                  borrow = 1;
              } else
                  borrow = 0;
              res[index] = digit[s];
              ++index;
          }
          res[index] = '\0';
          for (int i = 1; i <= (index) / 2; i++) {
              char tmp = res[i];
              if (checkZeroHeader == 0) {
                  if (res[index - i] != '0') {
                      res[i] = res[index - i];
                      res[index - i] = tmp;
                      checkZeroHeader = 1;
                  } else {
                      res[index - i] = '\0';
                  }
              } else {
                  res[i] = res[index - i];
                  res[index - i] = tmp;
              }
          }
          return res;
      }
    }
  res[0] = '0'; res[1] = '\0';
  return res;
};
/*
char *bigMultiply (char str1[], char str2[]) {
    int res[strlen(str1)  strlen(str2)];
    static char s[100000];
    char digit[10] = "0123456789";
    for (int i = 0; i <= strlen(str1)  strlen(str2); i)
        res[i] = 0;
    for (int i = strlen(str1) - 1; i >= 0; i--) {
        for( int j = strlen(str2) - 1; j >= 0; j--)
          res[i  1  j] = ((str1)[i] - '0') * ((str2)[j] - '0');
    }
    for (int i = strlen(str1)  strlen(str2); i >= 0 ; i--) {
        if(res[i] > 9) {
            res[i-1] = res[i]/10;
            res[i] %= 10;
        }
    }
    for (int i = 1; i <= strlen(str1)  strlen(str2) - 1; i ) {
        s[i - 1] = digit[res[i]];
    }
    return s;
}

void bigDivide1 (char str[], int n) {
    int res[1000], hold = 0, s = 0;

    for (int i = 0; i <= strlen(str) - 1; i) {
        hold = hold * 10  (str[i]  '0');
        s = hold / n;
        hold %= n;
        res[i] = s;
        printf("%d ", res[i]);
    };

}
*/
int main (void) {
    char str1[1000000], str2[1000000];
    scanf("%s", str1);
    scanf("%s", str2);

    //  printf("(): %s\n", bigAddition(st1, st2));
    printf("(-): %s\n", bigSubtraction(str1, str2));
    //  printf("(x): %s\n", bigMultiply(str1, str2));
    //  bigDivide1(str1, j);
    return 0;
}
