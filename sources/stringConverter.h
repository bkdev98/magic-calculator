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

int check(char s[]){
    int check = 0, checkB = 0;
    if (s[0] != '+' && s[0] != '-' && (s[0] < 48 || s[0] > 57))
        return 0;
    else if (s[1] == '.' && (s[0] == '-' || s[0] == '+' || s[0] < 48 || s[0] > 57))
        return 0;
    else {
        if (s[0] == '+' || s[0] == '-')
            for (int i = 1; i < strlen (s); i++){
                if ( s[i] == '.')
                    check += 1;
                if ( (s[i] < 48 || s[i] > 57) && s[i] != '.')
                    checkB += 1;
            }
        else
            for (int i = 0; i < strlen (s); i++){
                if ( s[i] == '.')
                    check += 1;
                if ( (s[i] < 48 || s[i] > 57) && s[i] != '.')
                    checkB += 1;
            }
    }
    if (check > 1 || checkB > 0)
        return 0;
    else
        return 1;

}
long double stringToNumber(char s[],  int *result) {
    *result = check(s);
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

