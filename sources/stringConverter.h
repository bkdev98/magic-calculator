#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char * numberToString(long double num) {
    static char output[50];
    snprintf(output, 50, "%Lf", num);
    for(int i = strlen(output) - 1; i > -1; i--)
        if (output[i] == '0')
            output[i] = '\0';
        else {
            if (output[i] == '.')
                output[i] = '\0';
            break;
        }
    return output;
}

long double stringToNumber(char s[]) {
    int i = 0;
    long double number = 0, tmp;

    while (i < strlen(s)){
        if (s[i] == '.')
            break;
        i++;
    }
    if ((s[0] == '-' || s[0] == '+') && i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i - 1));
        for (int j = (strlen(s) - 1); j > 0; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(s[0] == '-') number *= -1;
    }

    else if ( i != strlen(s)){
        tmp = 1 / pow(10, (strlen(s) - i) - 1);
        for (int j = (strlen(s) - 1); j > -1; j--)
            if (s[j] != '.'){
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    else if ((s[0] == '-' || s[0] == '+') && i == strlen(s)){
        tmp = 1;
        for (int j = (strlen(s) - 1); j > 0; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
        if(s[0] == '-') number *= -1;
    }

    else if ( i == strlen(s)){
        tmp = 1;
        for (int j = (strlen(s) - 1); j > -1; j--)
            {
                number += (s[j] - 48) * tmp;
                tmp *= 10;
            }
    }

    return number;
}
