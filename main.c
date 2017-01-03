#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "sources/stringConverter.h"
#include "sources/syntaxChecker.h"
#include "sources/baseConverter.h"
#include "sources/equationCalculator.h"

char stringLine[6969];
//  int ioMode = 0;
//  char trigonometricMode[10];

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

void playCredit() {
  waitFor(1);
  printf("              MAGIC CALCULATOR\n");
  waitFor(1);
  printf("       Made With All Love In The World\n");
  waitFor(1);
  printf("                 *** By ***\n");
  waitFor(1);
  printf("             Team Leader: BKDEV\n");
  waitFor(1);
  printf("           Stack Professor: KHANH98\n");
  waitFor(1);
  printf("             Mr. Calculator: NQK\n");
  waitFor(1);
  printf("For more infomation: https://github.com/bkdev98/magic-calculator\n");
  waitFor(1);
}

void showHelp() {
  printf("************************************\n");
  printf("With MAGIC CALCULATOR, you can: \n");
  printf("> Calculate the Value of Expression.\n");
  printf("    Example: 9/(1+2)*sqrt(16)-sin(90)\n");
  printf("> Solve Quadratic/Cubic Equation.\n");
  printf("    Example: x^3-3x^2+6x-9=0\n");
  printf("> Solve Two/Three hiddens Equation.\n");
  printf("    Example: 2x-y=6&x+y=4\n");
  printf("> Converting Any Bases to Others\n");
  printf("    Example: (10)69to(2)\n");
  printf("View Credit: type -c\n");
  printf("Exit Program: type -e\n");
  printf("************************************\n");
}

void playMagicMode() {
  printf("MAGIC CALCULATOR\n");
  //  printf("Current Mode: Deg | Magic\n");
  printf("Put things you want to solve, or -h for help, -e to exit.\n");
}

/*
void playNormalMode() {
  printf("MAGIC CALCULATOR\n");
  printf("Current Mode: Deg | Normal\n");
  printf("Menu: \n");
  printf("1. Calculate the value of expression.\n");
  printf("2. Solve quadratic equation.\n");
  printf("3. Solve cubic equation.\n");
  printf("4. Solve two hiddens equation.\n");
  printf("5. Solve three hiddens equation.\n");
  printf("6. Converting bases.\n");
  printf("Or type magic to change to Magic Mode.\n");
}
*/

int readLine() {
  // return:
  // -5: base not valid
  // -4: input is not number in base.
  // -3: wrong converting base spell.
  // -2: wrong equation spell.
  // -1: wrong expression spell.
  // 1: experssion.
  // 2: equation.
  // 3: converting base.
  // 4: show help
  // 5: play credit
  // 6: exit
  printf("$ ~ ");
  scanf("%s", stringLine);
  if (strlen(stringLine) == 2) {
    if (stringLine[0] == '-' && stringLine[1] == 'h')
      return 4;
    if (stringLine[0] == '-' && stringLine[1] == 'c')
      return 5;
    if (stringLine[0] == '-' && stringLine[1] == 'e')
      return 6;
  }
  for (int i = 0; i <= strlen(stringLine) - 1; i++) {
    if (stringLine[i] == 't' && stringLine[i+1] == 'o')
      return checkConverterSyntax(stringLine);
    if (stringLine[i] == 'x')
      return checkEquationSyntax(stringLine);
  };
  return checkExpressionSyntax(stringLine);
}

int isContinue() {
  char s[100];
  printf("$ ~ ");
  scanf("%s", s);
  if (strlen(s) != 1)
    return -1;
  else if (s[0] == 'N' || s[0] == 'n')
    return 0;
  else if (s[0] == 'Y' || s[0] == 'y')
    return 1;
  return -1;
}

int main(void) {
  int typeLine, isStop = 0, check;
  do {
    //  loadValue();
    playMagicMode();
    typeLine = readLine();
    switch(typeLine) {
      case -5: printf("Base Converter: Input & output base must be in [2; 16]. Please try again!\n");
              break;
      case -4: printf("Base Converter: Your input number is not in this input base. Please try again!\n");
              break;
      case -3: printf("Base Converter: Syntax error. Please try again!\n");
              break;
      case -2: printf("Equation Calculator: Syntax error. Please try again!\n");
              break;
      case -1: printf("Expression Calculator: Syntax error. Please try again!\n");
              break;
      case 1: printf("calculateExpression\n");
              //  calculateExpression(stringLine);
              break;
      case 2: solveEquation(stringLine);
              break;
      case 3: convertingBase(stringLine);
              break;
      case 4: showHelp();
              break;
      case 5: playCredit();
              break;
      case 6: isStop = 1;
              break;
    };
    /*
    printf("Do you want to continue (Y/N)?\n");
    do {
      check = isContinue();
      if (check == -1)
        printf("Your input is not valid, please input 'Y' or 'N'.\n");
      else if (check == 0)
        isStop = 1;
    } while (check == -1);
    */
    if (isStop)
      printf("Bye bye!\n");
  } while (isStop == 0);

  return 0;
}
