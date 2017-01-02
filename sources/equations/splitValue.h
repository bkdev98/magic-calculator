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
  a0[j] = '\0';
  ++i;
  j = 0;
  while (str[i] != '=') {
    b0[j] = str[i];
    i++;
    j++;
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
  a0[j] = '\0';
  i += 3;
  j = 0;
  while (str[i] != 'x') {
    b0[j] = str[i];
    i++;
    j++;
  }
  b0[j] = '\0';
  ++i;
  j = 0;
  while (str[i] != '=') {
    c0[j] = str[i];
    i++;
    j++;
  }
  c0[j] = '\0';
}

void splitValueCubicEquation(char str[]) {
  //  4x^3-3x^2+6x-9=0
  int i = 0, j = 0;
  while (str[i] != 'x') {
    a0[j] = str[i];
    i++;
    j++;
  }
  a0[j] = '\0';
  i += 3;
  while (str[i] != 'x') {
    b0[j] = str[i];
    i++;
    j++;
  }
  b0[j] = '\0';
  i += 3;
  j = 0;
  while (str[i] != 'x') {
    c0[j] = str[i];
    i++;
    j++;
  }
  c0[j] = '\0';
  ++i;
  j = 0;
  while (str[i] != '=') {
    d0[j] = str[i];
    i++;
    j++;
  }
  d0[j] = '\0';
}
