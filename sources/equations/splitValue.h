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

void splitValueTwoHiddensEquation(char str[]) {
  // -2x+3y-6=0&x-y=9
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
  while (str[i] != 'y') {
    b0[j] = str[i];
    i++;
    j++;
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
  if (str[i] != '=') {
    if (str[i] == '-') {
      c0[j] = '+';
      j++;
      i++;
      while (str[i] != '=') {
        c0[j] = str[i];
        i++;
        j++;
      }
      c0[j] = '\0';
    } else if (str[i] =='+') {
      c0[j] = '-';
      j++;
      i++;
      while (str[i] != '=') {
        c0[j] = str[i];
        i++;
        j++;
      }
      c0[j] = '\0';
    }
    i += 2;
  } else {
    i++;
    while (str[i] != '&') {
      c0[j] = str[i];
      i++;
      j++;
    }
    c0[j] = '\0';
  }

  ++i;
  j = 0;
  while (str[i] != 'x') {
    a1[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    a1[0] = '1';
    j = 1;
  }
  if (j == 1 && a1[0] == '-') {
    a1[0] = '-';
    a1[1] = '1';
    j = 2;
  }
  if (j == 1 && a1[0] == '+') {
    a1[0] = '+';
    a1[1] = '1';
    j = 2;
  }
  a1[j] = '\0';
  ++i;
  j = 0;
  while (str[i] != 'y') {
    b1[j] = str[i];
    i++;
    j++;
  }
  if (j == 1 && b1[0] == '-') {
    b1[0] = '-';
    b1[1] = '1';
    j = 2;
  }
  if (j == 1 && b1[0] == '+') {
    b1[0] = '+';
    b1[1] = '1';
    j = 2;
  }
  b1[j] = '\0';
  ++i;
  j = 0;
  if (str[i] != '=') {
    if (str[i] == '-') {
      c1[j] = '+';
      j++;
      i++;
      while (str[i] != '=') {
        c1[j] = str[i];
        i++;
        j++;
      }
      c1[j] = '\0';
    } else if (str[i] =='+') {
      c1[j] = '-';
      j++;
      i++;
      while (str[i] != '=') {
        c1[j] = str[i];
        i++;
        j++;
      }
      c1[j] = '\0';
    }
  } else {
    i++;
    while (str[i] != '\0') {
      c1[j] = str[i];
      i++;
      j++;
    }
  }

  c1[j] = '\0';
}


void splitValueThreeHiddensEquation(char str[]) {
  // -2x+3y-6=0&x-y=9
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
  while (str[i] != 'y') {
    b0[j] = str[i];
    i++;
    j++;
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
  if (str[i] != '=') {
    if (str[i] == '-') {
      c0[j] = '+';
      j++;
      i++;
      while (str[i] != '=') {
        c0[j] = str[i];
        i++;
        j++;
      }
      c0[j] = '\0';
    } else if (str[i] =='+') {
      c0[j] = '-';
      j++;
      i++;
      while (str[i] != '=') {
        c0[j] = str[i];
        i++;
        j++;
      }
      c0[j] = '\0';
    }
    i += 2;
  } else {
    i++;
    while (str[i] != '&') {
      c0[j] = str[i];
      i++;
      j++;
    }
    c0[j] = '\0';
  }

  ++i;
  j = 0;
  while (str[i] != 'x') {
    a1[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    a1[0] = '1';
    j = 1;
  }
  if (j == 1 && a1[0] == '-') {
    a1[0] = '-';
    a1[1] = '1';
    j = 2;
  }
  if (j == 1 && a1[0] == '+') {
    a1[0] = '+';
    a1[1] = '1';
    j = 2;
  }
  a1[j] = '\0';
  ++i;
  j = 0;
  while (str[i] != 'y') {
    b1[j] = str[i];
    i++;
    j++;
  }
  if (j == 1 && b1[0] == '-') {
    b1[0] = '-';
    b1[1] = '1';
    j = 2;
  }
  if (j == 1 && b1[0] == '+') {
    b1[0] = '+';
    b1[1] = '1';
    j = 2;
  }
  b1[j] = '\0';
  ++i;
  j = 0;
  if (str[i] != '=') {
    if (str[i] == '-') {
      c1[j] = '+';
      j++;
      i++;
      while (str[i] != '=') {
        c1[j] = str[i];
        i++;
        j++;
      }
      c1[j] = '\0';
    } else if (str[i] =='+') {
      c1[j] = '-';
      j++;
      i++;
      while (str[i] != '=') {
        c1[j] = str[i];
        i++;
        j++;
      }
      c1[j] = '\0';
    }
    i += 2;
  } else {
    i++;
    while (str[i] != '&') {
      c1[j] = str[i];
      i++;
      j++;
    }
    c1[j] = '\0';
  }

  ++i;
  j = 0;
  while (str[i] != 'x') {
    a2[j] = str[i];
    i++;
    j++;
  }
  if (j == 0) {
    a2[0] = '1';
    j = 1;
  }
  if (j == 1 && a2[0] == '-') {
    a2[0] = '-';
    a2[1] = '1';
    j = 2;
  }
  if (j == 1 && a2[0] == '+') {
    a2[0] = '+';
    a2[1] = '1';
    j = 2;
  }
  a2[j] = '\0';
  ++i;
  j = 0;
  while (str[i] != 'y') {
    b2[j] = str[i];
    i++;
    j++;
  }
  if (j == 1 && b2[0] == '-') {
    b2[0] = '-';
    b2[1] = '1';
    j = 2;
  }
  if (j == 1 && b2[0] == '+') {
    b2[0] = '+';
    b2[1] = '1';
    j = 2;
  }
  b2[j] = '\0';
  ++i;
  j = 0;
  if (str[i] != '=') {
    if (str[i] == '-') {
      c2[j] = '+';
      j++;
      i++;
      while (str[i] != '=') {
        c2[j] = str[i];
        i++;
        j++;
      }
      c2[j] = '\0';
    } else if (str[i] =='+') {
      c2[j] = '-';
      j++;
      i++;
      while (str[i] != '=') {
        c2[j] = str[i];
        i++;
        j++;
      }
      c2[j] = '\0';
    }
  } else {
    i++;
    while (str[i] != '\0') {
      c2[j] = str[i];
      i++;
      j++;
    }
  }
  c2[j] = '\0';
}
