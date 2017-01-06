int readLineMagic() {
  printf("$ ~ ");
  scanf("%s", stringLine);
  if (strlen(stringLine) == 2) {
    if (stringLine[0] == '-' && stringLine[1] == 'h')
      return 4;
    if (stringLine[0] == '-' && stringLine[1] == 'c')
      return 5;
    if (stringLine[0] == '-' && stringLine[1] == 'e')
      return 6;
    if (stringLine[0] == '-' && stringLine[1] == 'm')
      return 7;
  }
  for (int i = 0; i <= strlen(stringLine) - 1; i++) {
    //  Base Converter
    if (stringLine[i] == 't' && stringLine[i+1] == 'o')
      return checkConverterSyntax(stringLine);
    //  Equation Calculator
    if (stringLine[i] == 'x') {
      int isHidden = 0, isThreeHiddens = 0, isEnough = 0;
      for (int j = 1; j <= strlen(stringLine) - 1; j++) {
        if (stringLine[j] == 'y')
          isHidden = 1;
        if (stringLine[j] == 'z' && isHidden == 1)
          isThreeHiddens = 1;
        if (stringLine[j] == '&' && isHidden == 1 && isThreeHiddens == 1) {
          isEnough = 1;
          break;
        }
      }

      if (isHidden == 0) {  // Normal Equation
        return checkEquationSyntax(stringLine);
      }
      else // Hiddens Equation
      {
        //  Two Hiddens Equation
        if (isThreeHiddens == 0) {
          printf("2 %d %s\n", isEnough, stringLine);
          //  User Input Is Enough
          if (isEnough == 1) {
            return checkEquationSyntax(stringLine);
          } else {  //  Not Enough
            readTwoHiddensLine();
          }
        }
        else // Three Hiddens Equation
        {
          printf("3 %d %s\n", isEnough, stringLine);
          //  User Input Is Enough
          if (isEnough == 1) {
            return checkEquationSyntax(stringLine);
          } else {  //  Not Enough
            readThreeHiddensLine();
          }
        }
        //
        return checkEquationSyntax(stringLine);
      }
    }
  }
  return checkExpressionSyntax(stringLine);
}

void readTwoHiddensLine() {
  char s[100];
  printf("Second Equation: \n$ ~ ");
  scanf("%s", s);
  strcat(stringLine, "&");
  strcat(stringLine, s);
}

void readThreeHiddensLine() {
  char s1[100], s2[100];
  printf("Second Equation: \n$ ~ ");
  scanf("%s", s1);
  strcat(stringLine, "&");
  strcat(stringLine, s1);
  printf("Third equation: \n$ ~ ");
  scanf("%s", s2);
  strcat(stringLine, "&");
  strcat(stringLine, s2);
}
