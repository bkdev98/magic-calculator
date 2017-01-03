char * basicEquation(char strA[], char strB[]){
    long double a, b, x ;
    static char s[100];

    a = stringToNumber(strA);
    b = stringToNumber(strB);

    if (a == 0 && b != 0)
        strcpy(s, "No Solution!");
    else if (a == 0 && b == 0)
        strcpy(s, "Infinitely Many Solutions!");
    else {
        x = (b * (-1))/a;
        strcpy(s, "x = ");
        strcat(s, numberToString(x));
    }
    return s;
}

char * quadraticEquation(char strA[], char strB[], char strC[])
{
    long double a, b, c, delta, x1, x2;
    static char s[100];

    a = stringToNumber(strA);
    b = stringToNumber(strB);
    c = stringToNumber(strC);

    if (a == 0){
        strcpy(s, basicEquation(strB, strC));
        return s;
    }
    delta = b*b - 4*a*c;
    if (delta < 0)
        strcpy(s, "No Solution!");
    else if (delta == 0){
        x1 = (-b + sqrt(delta)) / (2 * a);
        strcpy(s, "x = ");
        strcat(s, numberToString(x1));
    }
    else{
        x1 = (-b + sqrt(delta)) / (2 * a);
        strcpy(s, "x(1) = ");
        strcat(s, numberToString(x1));
        x2 = (-b - sqrt(delta)) / (2 * a);
        strcat(s, "\nx(2) = ");
        strcat(s, numberToString(x2));
    }
    return s;
}

char * cubicEquation(char strA[], char strB[], char strC[], char strD[])
{
    long double a, b, c, d, x1, x2, x3, delta, k;
    static char s[100];

    a = stringToNumber(strA);
    b = stringToNumber(strB);
    c = stringToNumber(strC);
    d = stringToNumber(strD);

    if (a == 0){
        strcpy(s, quadraticEquation(strB, strC, strD));
        return s;
    }
    delta = (b*b - 3*a*c);
    k = (9*a*b*c - 2*b*b*b - 27*a*a*d) / (2 * sqrt(fabsl(delta*delta*delta)));
    if (delta > 0 ){
        if (fabsl(k) <= 1) {
            x1 = (2 * sqrt(delta) * cos(acos(k)/3) - b) / (3*a);
            strcpy(s, "x(1) = ");
            strcat(s, numberToString(x1));
            x2 = (2 * sqrt(delta) * cos(acos(k)/3 - (2*acos(-1)/3)) - b) / (3*a);
            strcat(s, "\nx(2) = ");
            strcat(s, numberToString(x2));
            x3 = (2 * sqrt(delta) * cos(acos(k)/3 + (2*acos(-1)/3)) - b) / (3*a);
            strcat(s, "\nx(3) = ");
            strcat(s, numberToString(x3));

        }
        else {
            x1 = (sqrt(delta)*fabsl(k) / (3*a*k))*(cbrt(fabsl(k) + sqrt(k*k-1)) + cbrt(fabsl(k) - sqrt(k*k-1))) - (b/(3*a));
            strcpy(s, "x = ");
            strcat(s, numberToString(x1));

        }
    }
    else if (delta == 0) {
        x1 = ((b * -1) + cbrt(b*b*b - 27*a*a*d)) / (3*a);
        strcpy(s, "x = ");
        strcat(s, numberToString(x1));
    }
    else {
        x1 = (sqrt(fabsl(delta)) / (3*a))*(cbrt(k + sqrt(k*k+1)) + cbrt(k - sqrt(k*k+1))) - (b/(3*a));
        strcpy(s, "x = ");
        strcat(s, numberToString(x1));
    }
    return s;
}
