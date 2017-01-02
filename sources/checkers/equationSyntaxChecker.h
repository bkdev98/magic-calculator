int typeEquation(char s[]) {
  // return:
  // 0: unknown;
  // 1: basicEquation;
  // 2: quadraticEquation;
  // 3: cubicEquation;
  // 4: twoHiddensEquation;
  // 5: threeHiddensEquation;

  for (int i = 0; i <= strlen(s) - 1; i++)
    if (s[i] == 'x') {
      if (s[i + 1] == '^') {
        if (s[i + 2] == '2') {
          return 2;
        } else if (s[i + 2] == '3') {
          return 3;
        }
      } else {
        for (int j = i + 1; j <= strlen(s) - 1; j++)
          if (s[j] == '&') {
            for (int k = j + 1; k <= strlen(s) - 1; k++)
              if (s[k] == '&')
                return 5;
            return 4;
          }
        return 1;
      }
    }
  return 0;
};

int checkBasicEquationSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // 2x-4=0
  int i = 0;
  if (s[i] != '+' && s[i] != '-' && (s[i] > '9' || s[i] < '1'))
    return -2;
  i++;
  while (s[i] != 'x' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
        return -2;
    i++;
  }
  if (i >= strlen(s) - 1)
    return -2;
  ++i;
  if (s[i] != '+' && s[i] != '-')
    return -2;
  ++i;
  while (s[i] != '=' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
      return -2;
    i++;
  }
  if (i >= strlen(s) - 1)
    return -2;
  ++i;
  if (s[i] != '0' || i != strlen(s) - 1)
    return -2;
  return 2;
}

int checkQuadraticEquationSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // -5x^2+10x-20=0
  int i = 0;
  if (s[i] != '+' && s[i] != '-' && (s[i] > '9' || s[i] < '1'))
    return -2;
  i++;
  while (s[i] != 'x' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
        return -2;
    i++;
  }
  if (i >= strlen(s) - 1 || s[i + 1] != '^' || s[i + 2] != '2')
    return -2;
  i += 3;
  if (s[i] != '+' && s[i] != '-')
    return -2;
  ++i;
  while (s[i] != 'x' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
      return -2;
    i++;
  }
  if (i >= strlen(s) - 1)
    return -2;
  ++i;
  if (s[i] != '+' && s[i] != '-')
    return -2;
  ++i;
  while (s[i] != '=' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
      return -2;
    i++;
  }
  if (i >= strlen(s) - 1)
    return -2;
  ++i;
  if (s[i] != '0' || i != strlen(s) - 1)
    return -2;
  return 2;
}

int checkCubicEquationSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // -9x^3+3x^2-2x+9=0
  int i = 0;
  if (s[i] != '+' && s[i] != '-' && (s[i] > '9' || s[i] < '1'))
    return -2;
  i++;
  while (s[i] != 'x' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
        return -2;
    i++;
  }
  if (i >= strlen(s) - 1 || s[i + 1] != '^' || s[i + 2] != '3')
    return -2;
  i += 3;
  if (s[i] != '+' && s[i] != '-')
    return -2;
  i++;
  while (s[i] != 'x' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
        return -2;
    i++;
  }
  if (i >= strlen(s) - 1 || s[i + 1] != '^' || s[i + 2] != '2')
    return -2;
  i += 3;
  if (s[i] != '+' && s[i] != '-')
    return -2;
  ++i;
  while (s[i] != 'x' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
      return -2;
    i++;
  }
  if (i >= strlen(s) - 1)
    return -2;
  ++i;
  if (s[i] != '+' && s[i] != '-')
    return -2;
  ++i;
  while (s[i] != '=' && i <= strlen(s) - 1) {
    if (s[i] > '9' || s[i] < '0')
      return -2;
    i++;
  }
  if (i >= strlen(s) - 1)
    return -2;
  ++i;
  if (s[i] != '0' || i != strlen(s) - 1)
    return -2;
  return 2;
}

int checkTwoHiddensEquationSyntax(char str[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  return 2;
}

int checkThreeHiddensEquationsSyntax(char str[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  return 2;
}

int checkEquationSyntax(char s[]) {
  // return:
  // -2: syntax error
  // 2: equation

  switch (typeEquation(s)) {
    case 0: return -2;
    case 1: return checkBasicEquationSyntax(s);
    case 2: return checkQuadraticEquationSyntax(s);
    case 3: return checkCubicEquationSyntax(s);
    case 4: return checkTwoHiddensEquationSyntax(s);
    case 5: return checkThreeHiddensEquationsSyntax(s);
  }
  return -2;
};
