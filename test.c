#include <stdio.h>
#include <string.h>
#include <math.h>

char * numberToString(long double num);
long double stringToNumber(char s[]);
char *bigMod (char st1[], char st2[]);
char *bigAdd (char st1[], char st2[]);
char *bigSub (char st1[], char st2[]);
char *bigMul (char st1[], char st2[]);
char *bigDiv (char st1[], char st2[]);


int main(int argc, char const *argv[]){
	char st1[100], st2[100];
	scanf("%s%s", st1, st2);
	printf("(+) = %s\n", bigAdd(st1, st2));
	printf("(-) = %s\n", bigSub(st1, st2));
	printf("(*) = %s\n", bigMul(st1, st2));
	printf("(/) = %s\n", bigDiv(st1, st2));
	printf("(M) = %s\n", bigMod(st1, st2));
	return 0;
}
char *bigAdd (char st1[], char st2[]) {
  char static stRes[1000];
  long double a, b;
  a = stringToNumber(st1);
  b = stringToNumber(st2);
  return numberToString(a+b);
}
char *bigSub (char st1[], char st2[]) {
  char static stRes[1000];
  long double a, b;
  a = stringToNumber(st1);
  b = stringToNumber(st2);
  return numberToString(a-b);
}
char *bigMul (char st1[], char st2[]) {
  char static stRes[1000];
  long double a, b;
  a = stringToNumber(st1);
  b = stringToNumber(st2);
  return numberToString(a*b);
}
char *bigDiv (char st1[], char st2[]) {
  char static stRes[1000];
  long double a, b;
  a = stringToNumber(st1);
  b = stringToNumber(st2);
  return numberToString(a/b);
}
char *bigMod (char st1[], char st2[]) {
  long double a, b;
  long long c;
  a = stringToNumber(st1);
  b = stringToNumber(st2);
  c = a / b;
  return numberToString(a-(c*b));
}
char * numberToString(long double num){
    static char output[50];

    snprintf(output, 50, "%Lf", num);

    return output;
}
//==============================================================================
long double stringToNumber(char s[]){
    int i = 0, j;
    long double number = 0, tmp;

    while (i < strlen(s)){
        if (s[i] == '.')
            break;
        i++;
    }
    if (s[0] == '-' && i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i - 1));
        for (j = (strlen(s) - 1); j > 0; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(number > 0) number *= -1;
    }

    else if ( i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i) - 1);
        for (j = (strlen(s) - 1); j > -1; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    else if (s[0] == '-' && i == strlen(s)){
        tmp = 1;
        for (j = (strlen(s) - 1); j > 0; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(number > 0) number *= -1;
    }

    else if ( i == strlen(s)){
        tmp = 1;
        for (j = (strlen(s) - 1); j > -1; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    return number;
}