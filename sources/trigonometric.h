char * rSin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(sin(i)));
    return str;
}

char * dSin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(sin(i * (M_PI / 180)) ));
    return str;
}

char * rCoSin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(cos(i)));
    return str;
}

char * dCoSin(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(cos(i * (M_PI / 180)) ));
    return str;
}

char * rTan(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    // co the sai so can test lai.
    if ( (i > 1.57078 && i < 1.5708) || (i < -1.57078 && i > -1.5708) ||
        (i > 4.71237 && i < 4.7124) || (i < -4.71237 && i > -4.7124))
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    strcpy(str, numberToString(tan(i)));
    return str;
}

char * dTan(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    if ( i == 90 || i == -90 || i == 270 || i == -270)
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    strcpy(str, numberToString(sin(i * (M_PI / 180)) ));
    return str;
}

char * logarit(char s[])
{
    static char str[100];
    if(strstr(s, ",") == NULL)
    {
        long double i = stringToNumber(s);
        strcpy(str, numberToString(log10(i)));
    }
    else
    {
        char str1[100], str2[100];
        int j, tmp;
        for(j = 0; s[j] != ','; j++)
            str1[j] = s[j];
        tmp = ++j;
        for(int i = 0; i <= (strlen(s) - tmp); i++, j++)
        {
            if(s[j] == ' ')
            {
                i--;
                continue;
            }
            str2[i] = s[j];
        }
        long double i = stringToNumber(str1),
                    i1 = stringToNumber(str2);
        tmp = log(i1) / log(i);
        strcpy(str, numberToString(tmp));
    }
    return str;
}

char * logn(char s[])
{
    static char str[100];
    long double i = stringToNumber(s), tmp;
    tmp = log(i) / log(M_E);
    strcpy(str, numberToString(tmp));
    return str;
}

char * sqRt(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    if (i < 0)
    {
        strcpy(str, "MATH ERROR");
        return str;
    }
    strcpy(str, numberToString(sqrt(i)));

    return str;
}

char * cbRt(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    strcpy(str, numberToString(cbrt(i)));

    return str;
}
