#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char stringLine[6969];
int isStop = 0;
int trigonometricMode = 0;

#include "sources/stringConverter.h"
#include "sources/syntaxChecker.h"
#include "sources/equationCalculator.h"
#include "sources/baseConverter.h"
#include "sources/views.h"
#include "sources/expressionCalculator.h"
#include "sources/fileControl.h"

int readLineMagic();
void playMagic();
void stopMagic();
void changeMode();

int main(void) {
  printHeader();
  do {
    loadValue();
    if (trigonometricMode == 0)
      printf("Current Mode: Deg. Type -m to switch.\n");
    else
      printf("Current Mode: Rad. Type -m to switch.\n");
    playMagic();
    if (isStop)
      sayGoodbye();
  } while (isStop == 0);

  return 0;
}

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
    if (stringLine[i] == 't' && stringLine[i+1] == 'o')
      return checkConverterSyntax(stringLine);
    if (stringLine[i] == 'x')
      return checkEquationSyntax(stringLine);
  };
  return checkExpressionSyntax(stringLine);
}

void playMagic() {
  int typeLine = readLineMagic();
  switch(typeLine) {
    case -19: printError(typeLine);
            break;
    case -18: printError(typeLine);
            break;
    case -16: printError(typeLine);
            break;
    case -15: printError(typeLine);
            break;
    case -14: printError(typeLine);
            break;
    case -13: printError(typeLine);
            break;
    case -12: printError(typeLine);
            break;
    case -11: printError(typeLine);
            break;
    case -5: printError(typeLine);
            break;
    case -4: printError(typeLine);
            break;
    case -3: printError(typeLine);
            break;
    case -2: printError(typeLine);
            break;
    case -1: printError(typeLine);
            break;
    case 1: if (trigonometricMode == 0)
              solveExpressionDeg(stringLine);
            else
              solveExpressionRad(stringLine);
            break;
    case 2: solveEquation(stringLine);
            break;
    case 3: convertingBase(stringLine);
            break;
    case 4: showHelp();
            break;
    case 5: playCredit();
            break;
    case 6: stopMagic();
            break;
    case 7: changeMode();
            break;
  }
}

void stopMagic() {
  isStop = 1;
}

void changeMode() {
  if (trigonometricMode == 0)
    saveValue(1);
  else
    saveValue(0);
}
