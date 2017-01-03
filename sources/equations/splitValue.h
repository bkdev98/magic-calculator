char a0[100], b0[100], c0[100], d0[100],
     a1[100], b1[100], c1[100], d1[100],
     a2[100], b2[100], c2[100], d2[100];

void splitValueBasicEquation(char str[]) {
   // -2x+3=0
   int i = 0, j = 0;
   while (str[i] != 'x') {
     a0[j] = str[i];
     i++;
     j++;
   }
   if (j == 0) {
     a0[0] = '1';
     j = 1;
   }
   if (j == 1 && a0[0] == '-') {
     a0[0] = '-';
     a0[1] = '1';
     j = 2;
   }
   if (j == 1 && a0[0] == '+') {
     a0[0] = '+';
     a0[1] = '1';
     j = 2;
   }
   a0[j] = '\0';
   ++i;
   j = 0;
   if (str[i] == '=') {
     ++i;
     if (str[i] == '-') {
       b0[j] = '+';
       j++;
       i++;
       while (str[i] != '\0') {
         b0[j] = str[i];
         i++;
         j++;
       }
       b0[j] = '\0';
     } else if (str[i] =='+') {
       b0[j] = '-';
       j++;
       i++;
       while (str[i] != '\0') {
         b0[j] = str[i];
         i++;
         j++;
       }
       b0[j] = '\0';
     } else {
       b0[j] = '-';
       j++;
       while (str[i] != '\0') {
         b0[j] = str[i];
         i++;
         j++;
       }
       b0[j] = '\0';
     }
   } else while (str[i] != '=') {
     b0[j] = str[i];
     i++;
     j++;
   }
   if (j == 0) {
     b0[0] = '0';
     ++j;
   }
   b0[j] = '\0';
}

void splitValueQuadraticEquation(char str[]) {
  // -2x^2+3x-9=0
  int i = 0, j = 0;
  while (str[i] != 'x') {
    a0[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    a0[0] = '1';
    j = 1;
  }
  if (j == 1 && a0[0] == '-') {
    a0[0] = '-';
    a0[1] = '1';
    j = 2;
  }
  if (j == 1 && a0[0] == '+') {
    a0[0] = '+';
    a0[1] = '1';
    j = 2;
  }
  a0[j] = '\0';
  i += 3;
  j = 0;

  while (str[i] != 'x') {
    b0[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    b0[0] = '0';
    j = 1;
  }
  if (j == 1 && b0[0] == '-') {
    b0[0] = '-';
    b0[1] = '1';
    j = 2;
  }
  if (j == 1 && b0[0] == '+') {
    b0[0] = '+';
    b0[1] = '1';
    j = 2;
  }
  b0[j] = '\0';
  ++i;
  j = 0;
  if (str[i] == '=') {
    ++i;
    if (str[i] == '-') {
      c0[j] = '+';
      j++;
      i++;
      while (str[i] != '\0') {
        c0[j] = str[i];
        i++;
        j++;
      }
      c0[j] = '\0';
    } else if (str[i] =='+') {
      c0[j] = '-';
      j++;
      i++;
      while (str[i] != '\0') {
        c0[j] = str[i];
        i++;
        j++;
      }
      c0[j] = '\0';
    } else {
      c0[j] = '-';
      j++;
      while (str[i] != '\0') {
        c0[j] = str[i];
        i++;
        j++;
      }
      c0[j] = '\0';
    }
  } else while (str[i] != '=') {
    c0[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    c0[0] = '0';
    ++j;
  }
  c0[j] = '\0';
}

void splitValueCubicEquation(char str[]) {
  // -2x^2+3x-9=0
  int i = 0, j = 0;

  while (str[i] != 'x') {
    a0[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    a0[0] = '1';
    j = 1;
  }
  if (j == 1 && a0[0] == '-') {
    a0[0] = '-';
    a0[1] = '1';
    j = 2;
  }
  if (j == 1 && a0[0] == '+') {
    a0[0] = '+';
    a0[1] = '1';
    j = 2;
  }
  a0[j] = '\0';
  i += 3;
  j = 0;

  while (str[i] != 'x') {
    b0[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    b0[0] = '1';
    j = 1;
  }
  if (j == 1 && b0[0] == '-') {
    b0[0] = '-';
    b0[1] = '1';
    j = 2;
  }
  if (j == 1 && b0[0] == '+') {
    b0[0] = '+';
    b0[1] = '1';
    j = 2;
  }
  b0[j] = '\0';
  i += 3;
  j = 0;

  while (str[i] != 'x') {
    c0[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    c0[0] = '0';
    j = 1;
  }
  if (j == 1 && c0[0] == '-') {
    c0[0] = '-';
    c0[1] = '1';
    j = 2;
  }
  if (j == 1 && c0[0] == '+') {
    c0[0] = '+';
    c0[1] = '1';
    j = 2;
  }
  c0[j] = '\0';
  ++i;
  j = 0;
  if (str[i] == '=') {
    ++i;
    if (str[i] == '-') {
      d0[j] = '+';
      j++;
      i++;
      while (str[i] != '\0') {
        d0[j] = str[i];
        i++;
        j++;
      }
      d0[j] = '\0';
    } else if (str[i] =='+') {
      d0[j] = '-';
      j++;
      i++;
      while (str[i] != '\0') {
        d0[j] = str[i];
        i++;
        j++;
      }
      d0[j] = '\0';
    } else {
      d0[j] = '-';
      j++;
      while (str[i] != '\0') {
        d0[j] = str[i];
        i++;
        j++;
      }
      d0[j] = '\0';
    }
  } else while (str[i] != '=') {
    d0[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    d0[0] = '0';
    ++j;
  }
  d0[j] = '\0';
}

void splitValueTwoHiddensEquation(char s[])
{
    char s1[100], s2[100];

    fflush(stdin);
    {
        int i = 0, j = 0;
        for (i = 0; s[i] != '&'; i++)
            s1[i] = s[i];
        s1[i] = '\0';
        i++;
        for (j = 0 ; i < strlen(s); i++, j++)
            s2[j] = s[i];
        s2[j] = '\0';

    }


    char tmp1[100], tmp2[100], tmp3[100], tmp4[100];

    {
        fflush(stdin);
        int i = 0, j = 0;
        for (i = 0; s1[i] != '='; i++)
            tmp1[i] = s1[i];
        tmp1[i] = '\0';

        for (j = 0 ; i < strlen(s1); i++, j++)
            tmp2[j] = s1[i];
        tmp2[j] = '\0';

    }

    {
        fflush(stdin);
        int i = 0, j = 0;
        for (i = 0; s2[i] != '='; i++)
            tmp3[i] = s2[i];
        tmp3[i] = '\0';

        for (j = 0 ; i < strlen(s2); i++, j++)
            tmp4[j] = s2[i];
        tmp4[j] = '\0';

    }


    int check = 0;
    {
        fflush(stdin);
        char tmpA[100], tmpB[100], tmpC[100];
        int i = 0, j = 0;
        while (tmp1[i] != 'x' && tmp1[i] != 'y' && i < strlen(tmp1)) {
            tmpA[j] = tmp1[i];
            i++;
            j++;
        }
        tmpA[j] = '\0';
        if ( j == 0 && tmp1[i] == 'x')
            strcpy(a0, "1");
        else if ( j == 1 && tmp1[i] == 'x'&& tmpA[0] == '-'){

                strcpy(a0, "-1");

        }
        else if ( j == 1 && tmp1[i] == 'x'&& tmpA[0] == '+')
            strcpy(a0, "1");
        else if ( tmp1[i] == 'x' ){
            strcpy(a0, tmpA);
        }
        else if ( j == 0 && tmp1[i] == 'y'){
            strcpy(b0, "1");
        }
        else if (  j == 1 && tmp1[i] == 'y'&& tmpA[0] == '-'){

                strcpy(b0, "-1");

        }
        else if ( j == 1 && tmp1[i] == 'y'&& tmpA[0] == '+')
            strcpy(b0, "1");
        else if ( tmp1[i] == 'y' ){
            strcpy(b0, tmpA);
        }

        fflush(stdin);
        i++;
        j = 0;
        while (tmp1[i] != 'x' && tmp1[i] != 'y' && i < strlen(tmp1)) {
            tmpB[j] = tmp1[i];
            i++;
            j++;
        }
        tmpB[j] = '\0';
        if ( j == 1 && tmp1[i] == 'x'){
            strcpy(a0, tmpB);
            a0[1] = '1';
        }
        else if ( tmp1[i] == 'x' ){
            strcpy(a0, tmpB);
        }
        else if ( j == 1 && tmp1[i] == 'y'){
            strcpy(b0, tmpB);
            b0[1] = '1';
        }
        else if ( tmp1[i] == 'y' ){
            strcpy(b0, tmpB);
        }

        fflush(stdin);
        if ( (i + 1) < strlen(tmp1)){
            i++;
            j = 0;
            while (i < strlen(tmp1)){
                tmpC[j] = tmp1[i];
                i++;
                j++;
            }
            tmpC[j] = '\0';
            strcpy(c0, tmpC);
            check = 1;

        }
    }

//==============================================================================

    {
        fflush(stdin);
        char tmpD[100];
        if (check == 0){

            char tmpD[100];

            {
                int i;
                for(i = 0; i < (strlen(tmp2) - 1); i++)
                    tmpD[i] = tmp2[i + 1];
                tmpD[i] = '\0';
            }
            if ( tmpD[0] == '-')
                for (int t = 1; t < strlen (tmp2); t++)
                    c0[t - 1] = tmpD[t];
            else if (tmpD[0] == '+'){
                c0[0] = '-';
                for (int t = 1; t < strlen (tmp2); t++)
                        c0[t] = tmpD[t];
            }
            else{
                c0[0] = '-';
                for (int t = 0; t < strlen (tmp2); t++)
                    c0[t + 1] = tmpD[t];
            }
        }
    }


//==============================================================================

{
    fflush(stdin);
    check = 0;
    char tmpE[100], tmpF[100], tmpG[100];
    int i = 0, j = 0;

    while (tmp3[i] != 'x' && tmp3[i] != 'y' && i < strlen(tmp3)) {
        tmpE[j] = tmp3[i];
        i++;
        j++;
    }
    tmpE[j] = '\0';

    if ( j == 0 && tmp3[i] == 'x')
        strcpy(a1, "1");
    else if ( j == 1 && tmp3[i] == 'x' && tmpE[0] == '-'){
            strcpy(a1, "-1");
    }
    else if ( j == 1 && tmp3[i] == 'x' && tmpE[0] == '+')
        strcpy(a1, "1");
    else if ( tmp3[i] == 'x' ){
        strcpy(a1, tmpE);
    }
    else if ( j == 0 && tmp3[i] == 'y'){
        strcpy(b1, "1");
    }
    else if (  j == 1 && tmp3[i] == 'y' && tmpE[0] == '-'){

            strcpy(b1, "-1");

    }
    else if (  j == 1 && tmp3[i] == 'y' && tmpE[0] == '+')
        strcpy(a1, "1");
    else if ( tmp3[i] == 'y' ){
        strcpy(b1, tmpE);
    }
    fflush(stdin);
    i++;
    j = 0;
    while (tmp3[i] != 'x' && tmp3[i] != 'y' && i < strlen(tmp3)) {
        tmpF[j] = tmp3[i];
        i++;
        j++;
    }
    tmpF[j] = '\0';
    if ( j == 1 && tmp3[i] == 'x'){
        strcpy(a1, tmpF);
        a1[1] = '1';
    }
    else if ( tmp3[i] == 'x' ){
        strcpy(a1, tmpF);
    }
    else if ( j == 1 && tmp3[i] == 'y'){
        strcpy(b1, tmpF);
        b1[1] = '1';
    }
    else if ( tmp3[i] == 'y' ){
        strcpy(b1, tmpF);
    }
    fflush(stdin);
    if ( (i+1) < strlen(tmp3)){
        i++;
        j = 0;
        while (i < strlen(tmp3)){
            tmpG[j] = tmp3[i];
            i++;
            j++;
        }
        tmpG[j] = '\0';
        strcpy(c1, tmpG);
        check = 1;

    }
}

//==============================================================================

    {
        fflush(stdin);
        char tmpH[100];

        if (check == 0){
            char tmpH[100];

            fflush(stdin);
            {
                int i;
                for(i = 0; i < (strlen(tmp4) - 1); i++)
                    tmpH[i] = tmp4[i + 1];
                tmpH[i] = '\0';
            }

            fflush(stdin);
            if ( tmpH[0] == '-')
                for (int t = 1; t < strlen (tmp4); t++)
                    c1[t - 1] = tmpH[t];
            else if (tmpH[0] == '+'){
                c1[0] = '-';
                for (int t = 1; t < strlen (tmp4); t++)
                    c1[t] = tmpH[t];
            }
            else{
                c1[0] = '-';
                for (int t = 0; t < strlen (tmp4); t++)
                    c1[t + 1] = tmpH[t];
            }
        }
    }
}
