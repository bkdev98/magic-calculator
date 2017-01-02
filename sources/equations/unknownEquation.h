char * twoHiddensEquation(char stA0[], char stB0[], char stC0[],
            char stA1[], char stB1[], char stC1[])
{
    long double a0, b0, c0, a1, b1, c1;

    a0 = stringToNumber(stA0);
    b0 = stringToNumber(stB0);
    c0 = stringToNumber(stC0);
    a1 = stringToNumber(stA1);
    b1 = stringToNumber(stB1);
    c1 = stringToNumber(stC1);
    static char s[100];
    if ((a0 == 0 && b0 == 0)||(a1 == 0 && b1 == 0))
    {
        strcpy(s, "MATH ERROR");
        return s;
    }
    long double det, x, y;

    det = (a0 * b1 - a1 * b0);

    a0 /= det;
    b0 /= (det * (-1));

    a1 /= (det * (-1));
    b1 /= det;

    swap(&a0, &b1);

    x = (a0 * c0) + (b0 * c1);
    strcpy(s, numberToString(x));
    y = (a1 * c0) + (b1 * c1);
    strcat(s, "______");
    strcat(s, numberToString(y));

    return s;
}

char * threeHiddensEquation(char sta0[], char stb0[], char stc0[], char std0[],
            char sta1[], char stb1[], char stc1[], char std1[],
            char sta2[], char stb2[], char stc2[], char std2[])
{
    long double a0, b0, c0, d0, a1, b1, c1, d1, a2, b2, c2, d2;

    a0 = stringToNumber(sta0);
    b0 = stringToNumber(stb0);
    c0 = stringToNumber(stc0);
    d0 = stringToNumber(std0);
    a1 = stringToNumber(sta1);
    b1 = stringToNumber(stb1);
    c1 = stringToNumber(stc1);
    d1 = stringToNumber(std1);
    a2 = stringToNumber(sta2);
    b2 = stringToNumber(stb2);
    c2 = stringToNumber(stc2);
    d2 = stringToNumber(std2);

    static char s[100];
    if ((a0 == 0 && b0 == 0 && c0 == 0) ||
        (a1 == 0 && b1 == 0 && c1 == 0)||
        (a2 == 0 && b2 == 0 && c2 == 0))
    {
        strcpy(s, "MATH ERROR");
        return s;
    }
    long double det,
                x1, x2, x3, x4, x5, x6, x7, x8, x9,
                x, y, z;

    det = a0*(b1*c2 - b2*c1) - b0*(a1*c2 - a2*c1) + c0*(a1*b2 - a2*b1);

    x1 = (b1*c2 - b2*c1) / det;
    x2 = ((-1)*(a1*c2 - a2*c1)) / det;
    x3 = (a1*b2 - a2*b1) / det;

    x4 = ((-1)*(b0*c2 - b2*c0)) / det;
    x5 = (a0*c2 - a2*c0) / det;
    x6 = ((-1)*(a0*b2 - a2*b0)) / det;

    x7 = (b0*c1 - b1*c0) / det;
    x8 = ((-1)*(a0*c1 - a1*c0)) / det;
    x9 = (a0*b1 - a1*b0) / det;

    swap(&x2, &x4);
    swap(&x3, &x7);
    swap(&x6, &x8);

    x = (x1 * d0) + (x2 * d1) + (x3 * d2);
    strcpy(s, numberToString(x));
    y = (x4 * d0) + (x5 * d1) + (x6 * d2);
    strcat(s, "______");
    strcat(s, numberToString(y));
    z = (x7 * d0) + (x8 * d1) + (x9 * d2);
    strcat(s, "______");
    strcat(s, numberToString(z));

    return s;
}
