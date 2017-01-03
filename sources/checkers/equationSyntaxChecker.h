#include "splitValue.h"

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

int rightNumber(char s[]){
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

int checkBasicEquationSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // 2x-4=0
  char acceptedSymbol[100] = "0123456789+-=x";
  int checkX = 0, checkEqual = 0;
  for (int i = 0; i <= strlen(s) - 1; i++) {
    if (strchr(acceptedSymbol, s[i]) == NULL)
      return -2;
    if (s[i] == 'x') {
      if (checkX == 0)
        checkX = 1;
       else
        return -2;
    }
    if (s[i] == '=') {
      if (checkX == 0)
        return -2;
      else if (checkEqual == 0)
        checkEqual = 1;
      else
        return -2;
    }
  }
  if (checkX == 0 || checkEqual == 0)
    return -2;
  splitValueBasicEquation(stringLine);
  if (rightNumber(a0) == 0 || rightNumber(b0) == 0)
    return -2;
  return 2;
}


int checkQuadraticEquationSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // 2x^2-4x+2=0
  char acceptedSymbol[100] = "0123456789+-=x^";
  int checkX2 = 0, checkX = 0, checkEqual = 0;
  for (int i = 0; i <= strlen(s) - 1; i++) {
    if (strchr(acceptedSymbol, s[i]) == NULL)
      return -2;
    if (s[i] == 'x' && s[i + 1] == '^' && s[i + 2] == '2') {
      if (checkX2 == 0 && checkX == 0 && checkEqual == 0)
        checkX2 = 1;
      else
        return -2;
    } else if (s[i] == 'x' && s[i + 1] != '^') {
      if (checkX2 == 1 && checkX == 0 && checkEqual == 0)
        checkX = 1;
      else
        return -2;
    } else if (s[i] == '=') {
      if (checkEqual == 0 && checkX == 1 && checkX2 == 1)
        checkEqual = 1;
      else
        return -2;
    }
  }
  if (checkEqual == 0)
    return -2;
  splitValueQuadraticEquation(stringLine);
  if (rightNumber(a0) == 0 || rightNumber(b0) == 0 || rightNumber(c0) == 0)
    return -2;
  return 2;
}

int checkCubicEquationSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // -x^3+2x^2-4x+2=0
  char acceptedSymbol[100] = "0123456789+-=x^";
  int checkX3 = 0, checkX2 = 0, checkX = 0, checkEqual = 0;
  for (int i = 0; i <= strlen(s) - 1; i++) {
    if (strchr(acceptedSymbol, s[i]) == NULL)
      return -2;
    if (s[i] == 'x' && s[i + 1] == '^' && s[i + 2] == '3') {
      if (checkX3 == 0 && checkX2 == 0 && checkX == 0)
        checkX3 = 1;
      else
        return -2;
    } else if (s[i] == 'x' && s[i + 1] == '^' && s[i + 2] == '2') {
      if (checkX3 == 1 && checkX2 == 0 && checkX == 0 && checkEqual == 0)
        checkX2 = 1;
      else
        return -2;
    } else if (s[i] == 'x' && s[i + 1] != '^') {
      if (checkX3 == 1 && checkX2 == 1 && checkX == 0 && checkEqual == 0)
        checkX = 1;
      else
        return -2;
    } else if (s[i] == '=') {
      if (checkX3 == 1 && checkEqual == 0 && checkX == 1 && checkX2 == 1)
        checkEqual = 1;
      else
        return -2;
    }
  }
  if (checkEqual == 0)
    return -2;
  splitValueCubicEquation(stringLine);
  if (rightNumber(a0) == 0 || rightNumber(b0) == 0 || rightNumber(c0) == 0 || rightNumber(d0) == 0)
    return -2;
  return 2;
}

int checkTwoHiddensEquationSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // 2x-3y=3&-x+y-6=0
  char acceptedSymbol[100] = "0123456789+-=xy&";
  int checkX = 0, checkY = 0, checkAnd = 0, checkEqual = 0;
  for (int i = 0; i <= strlen(s) - 1; i++) {
    if (strchr(acceptedSymbol, s[i]) == NULL)
      return -2;
    if (s[i] == 'x') {
      if (checkX == 0) {
        if (checkX == 0 && checkY == 0 && checkEqual == 0 && checkAnd == 0)
          checkX = 1;
        else
          return -2;
      } else if (checkX == 1) {
        if (checkY == 1 && checkEqual == 1 && checkAnd == 1)
          checkX = 2;
        else
          return -2;
      }
    } else if (s[i] == 'y') {
      if (checkY == 0) {
        if (checkX == 1 && checkY == 0 && checkAnd == 0 && checkEqual == 0)
          checkY = 1;
        else
          return -2;
      } else if (checkY == 1) {
        if (checkX == 2 && checkAnd == 1 && checkEqual == 1)
          checkY = 2;
        else
          return -2;
      }
    } else if (s[i] == '=') {
      if (checkEqual == 0) {
        if (checkX == 1 && checkY == 1 && checkAnd == 0 && checkEqual == 0)
          checkEqual = 1;
        else
          return -2;
      } else if (checkEqual == 1) {
        if (checkX == 2 && checkY == 2 && checkAnd == 1 && checkEqual == 1)
          checkEqual = 2;
        else
          return -2;
      }
    } else if (s[i] == '&') {
      if (checkX == 1 && checkEqual == 1 && checkY == 1 && checkAnd == 0)
        checkAnd = 1;
      else
        return -2;
    }
  }

  if (checkEqual != 2)
    return -2;

  splitValueTwoHiddensEquation(stringLine);
  if (rightNumber(a0) == 0 || rightNumber(b0) == 0 || rightNumber(c0) == 0 || rightNumber(a1) == 0 || rightNumber(b1) == 0 || rightNumber(c1) == 0)
    return -2;
  return 2;
}

int checkThreeHiddensEquationsSyntax(char s[]) {
  // return:
  // -2: syntaxError
  // 2: ok
  // 2x-3y-z=3&-x+y+2z-6=0&x-y+z=2
  char acceptedSymbol[100] = "0123456789+-=xyz&";
  int checkX = 0, checkY = 0, checkZ = 0, checkAnd = 0, checkEqual = 0;
  for (int i = 0; i <= strlen(s) - 1; i++) {
    if (strchr(acceptedSymbol, s[i]) == NULL)
      return -2;
    if (s[i] == 'x') {
      if (checkX == 0) {
        if (checkY == 0 && checkEqual == 0 && checkAnd == 0 && checkZ == 0)
          checkX = 1;
        else
          return -2;
      } else if (checkX == 1) {
        if (checkY == 1 && checkEqual == 1 && checkAnd == 1 && checkZ == 1)
          checkX = 2;
        else
          return -2;
      } else if (checkX == 2) {
        if (checkY == 2 && checkEqual == 2 && checkAnd == 2 && checkZ == 2)
          checkX = 3;
        else
          return -2;
      }
    } else if (s[i] == 'y') {
      if (checkY == 0) {
        if (checkX == 1  && checkAnd == 0 && checkEqual == 0 && checkZ == 0)
          checkY = 1;
        else
          return -2;
      } else if (checkY == 1) {
        if (checkX == 2 && checkAnd == 1 && checkEqual == 1 && checkZ == 1)
          checkY = 2;
        else
          return -2;
      } else if (checkY == 2) {
        if (checkX == 3 && checkAnd == 2 && checkEqual == 2 && checkZ == 2)
          checkY = 3;
        else
          return -2;
      }
    } else if (s[i] == 'z') {
      if (checkZ == 0) {
        if (checkX == 1 && checkY == 1 && checkAnd == 0 && checkEqual == 0)
          checkZ = 1;
        else
          return -2;
      } else if (checkZ == 1) {
        if (checkX == 2 && checkY == 2 && checkAnd == 1 && checkEqual == 1)
          checkZ = 2;
        else
          return -2;
      } else if (checkZ == 2) {
        if (checkX == 3 && checkY == 3 && checkAnd == 2 && checkEqual == 2)
          checkZ = 3;
        else
          return -2;
      }
    } else if (s[i] == '=') {
      if (checkEqual == 0) {
        if (checkX == 1 && checkY == 1 && checkZ == 1 && checkAnd == 0)
          checkEqual = 1;
        else
          return -2;
      } else if (checkEqual == 1) {
        if (checkX == 2 && checkY == 2 && checkZ == 2 && checkAnd == 1)
          checkEqual = 2;
        else
          return -2;
      } else if (checkEqual == 2) {
        if (checkX == 3 && checkY == 3 && checkZ == 3 && checkAnd == 2)
          checkEqual = 3;
        else
          return -2;
      }
    } else if (s[i] == '&') {
      if (checkAnd == 0) {
        if (checkX == 1 && checkEqual == 1 && checkZ == 1 && checkY == 1)
          checkAnd = 1;
        else
          return -2;
      } else if (checkAnd == 1) {
        if (checkX == 2 && checkEqual == 2 && checkZ == 2 && checkY == 2)
          checkAnd = 2;
        else
          return -2;
      }
    }
  }
  if (checkEqual != 3)
    return -2;

  splitValueThreeHiddensEquation(stringLine);
  if (rightNumber(a0) == 0 || rightNumber(b0) == 0 || rightNumber(c0) == 0 || rightNumber(a1) == 0 || rightNumber(b1) == 0 || rightNumber(c1) == 0 || rightNumber(a2) == 0 || rightNumber(b2) == 0 || rightNumber(c2) == 0)
    return -2;
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
