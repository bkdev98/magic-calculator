#define PI 3.141592654
#define E 2.718281828

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
    strcpy(str, numberToString(sin(i * (PI / 180)) ));
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
    strcpy(str, numberToString(cos(i * (PI / 180)) ));
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
        strcpy(str, "No Solution!");
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
        strcpy(str, "No Solution!");
        return str;
    }
    strcpy(str, numberToString(sin(i * (PI / 180)) ));
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
    tmp = log(i) / log(E);
    strcpy(str, numberToString(tmp));
    return str;
}

char * sqRt(char s[])
{
    static char str[100];
    long double i = stringToNumber(s);
    if (i < 0)
    {
        strcpy(str, "No Solution!");
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

char * Exp(char str1[], char str2[])
{
    static char str[100];

    long double i = stringToNumber(str1),
                i1 = stringToNumber(str2),
                tmp;

    /* bat dau tinh */
    if (i == 0 && i1 < 0)
    {
        strcpy(str, "No Solution!");
        return str;
    }
    else
    {
        if (i >= 0)
        {
            tmp = pow( i, i1 );
        }
        else
        {
            long double test_i1 = i1;

            i *= (-1);
            while (abs(test_i1) < 2) test_i1 *= 10;

            if ( strstr(str2, ".") == NULL )
            {
                if ( str2[strlen(str2) - 1] % 2 == 0)
                    tmp = pow( i, i1 );
                else
                    tmp = pow( i, i1 ) * (-1);
            }
            else if ( fmod( test_i1, 2 ) != 0 ) // so le
            {
                strcpy(str, "No Solution!");
                return str;
            }
            else if ( fmod( test_i1, 4 ) != 0) // so le bac 2
                tmp = pow( i, i1 ) * (-1);
            else
            {
                tmp = pow( i, i1 ); // so chan
            }
        }
    }
    strcpy(str, numberToString(tmp));
    return str;
}
//==============================================================================
char * nthRoot ( char str1[], char str2[])
{
    static char str[100];
    long double i = stringToNumber(str1),
                i1 = stringToNumber(str2),
                tmp;
    /* bat dau tinh */
    if (i1 == 0 || (i == 0 && i1 < 0))
    {
        strcpy(str, "No Solution!");
        return str;
    }
    else if ( i1 > 0)
    {
        if (i >= 0)
        {
            tmp = pow( i, (1 / i1) );
        }
        else
        {
            long double test_i1 = i1;

            i *= (-1);
            while (abs(test_i1) < 2) test_i1 *= 10;

            if ( strstr(str2, ".") == NULL )
            {
                if ( str2[strlen(str2) - 1] % 2 == 0)
                {
                    strcpy(str, "No Solution!");
                    return str;
                }
                else tmp = pow( i, (1 / i1) ) * (-1);
            }
            else if ( fmod( test_i1, 2 ) != 0 ) // truong hop so le b1 can ra > 0.
                tmp = pow( i, (1 / i1) );
            else if ( fmod( test_i1, 4 ) != 0) // truong hop so le b2 can ra < 0.
                tmp = pow( i, (1 / i1) ) * (-1);
            else                                // truong hop so chan
            {
                strcpy(str, "No Solution!");
                return str;
            }
        }
    }
    else
    {
        i1 *= (-1);
        if (i >= 0)
        {
            tmp = 1 / pow( i, (1 / i1) );
        }
        else
        {
            long double test_i1 = i1;

            i *= (-1);
            while (abs(test_i1) < 2) test_i1 *= 10;

            if ( strstr(str2, ".") == NULL )
            {
                if ( str2[strlen(str2) - 1] % 2 == 0)
                {
                    strcpy(str, "No Solution!");
                    return str;
                }
                else tmp = 1 / (pow( i, (1 / i1) ) * (-1));
            }
            else if ( fmod( test_i1, 2 ) != 0 ) // truong hop so le b1 can ra > 0.
                tmp = 1 / pow( i, (1 / i1) );
            else if ( fmod( test_i1, 4 ) != 0) // truong hop so le b2 can ra < 0.
                tmp = 1 / (pow( i, (1 / i1) ) * (-1));
            else                               // truong hop so chan
            {
                strcpy(str, "No Solution!");
                return str;
            }
        }
    }
    strcpy(str, numberToString(tmp));
    return str;
}
