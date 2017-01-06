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
  printf(">   Calculate the Value of Expression.\n");
  printf("        Example 1: 2.1+6.9\n");
  printf("        Example 2: (21+69)*2\n");
  printf("        Example 3: sqrt(16)+2^3\n");
  printf("    Supported Operators: \n");
  printf("        +, -, *, /, ^, r, sin, cos, tan, log, ln, sqrt, cbrt.\n");
  printf(">   Solve Basic/Quadratic/Cubic Equation.\n");
  printf("        Example 1: 6x-9=0\n");
  printf("        Example 2: -x^2+2x^2=4\n");
  printf("        Example 3: x^3-3x^2+6x-9=0\n");
  printf(">   Solve Two/Three hiddens Equation.\n");
  printf("        Example 1: 2x-y=6&x+y=4\n");
  printf("        Example 2: -x-y+2z=6&x+9y-z=2&-x-y+z=1\n");
  printf(">   Converting Any Bases to Others\n");
  printf("        Example 1: (10)69to(2)\n");
  printf("        Example 2: (2)100011010to(16)\n");
  printf("        Example 3: (8)1637to(4)\n");
  printf("Switch between Rad and Deg mode: type -m\n");
  printf("View Credit: type -c\n");
  printf("Exit Program: type -e\n");
  printf("************************************\n");
}

void printError(int n) {
  switch (n) {
    case -20: printf("Expression Calculator: Math error: Can't not compute Tan\n");
            break;
    case -19: printf("Expression Calculator: Syntax error: Unaccepted symbol!\n");
            break;
    case -18: printf("Expression Calculator: Wrong number syntax!\n");
            break;
    case -16: printf("Expression Calculator: Syntax error: Empty Bracklet!\n");
            break;
    case -15: printf("Expression Calculator: Syntax error!\n");
            break;
    case -14: printf("Expression Calculator: Math error: Can't not div Zero!\n");
            break;
    case -13: printf("Expression Calculator: Syntax error: Operand error!\n");
            break;
    case -12: printf("Expression Calculator: Syntax error: Operand missing!\n");
            break;
    case -11: printf("Expression Calculator: Syntax error: Bracklet missing!\n");
            break;

    case -5: printf("Base Converter: Input & output base must be in [2; 16]. Please try again!\n");
            break;
    case -4: printf("Base Converter: Your input number is not in this input base. Please try again!\n");
            break;
    case -3: printf("Base Converter: Syntax must be (baseA)numberInBaseAto(baseB). Please try again!\n");
            break;
    case -2: printf("Equation Calculator: Syntax error. Please try again, for more infos, type -h!\n");
            break;
  }
}

void printHeader() {
  printf("MAGIC CALCULATOR\n");
  printf("Put things you want to solve, or -h for help, -e to exit.\n");
}

void sayGoodbye() {
  printf("Bye bye!\n");
}
