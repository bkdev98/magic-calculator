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

void printError(int n) {
  switch (n) {
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
  }
}

void printHeader() {
  printf("MAGIC CALCULATOR\n");
  printf("Put things you want to solve, or -h for help, -e to exit.\n");
}

void sayGoodbye() {
  printf("Bye bye!\n");
}
