#include "equations/splitValue.h"
#include "equations/calcEquation.h"
//  #include "equations/unknownEquation.h"

void solveEquation(char str[]) {
  int type = typeEquation(str);
  switch (type) {
    case 1: splitValueBasicEquation(str);
            printf("Solving Equation %sx%s=0: \n", a0, b0);
            printf("%s\n", basicEquation(a0, b0));
            break;
    case 2: splitValueQuadraticEquation(str);
            printf("Solving Equation %sx^2%sx%s=0: \n", a0, b0, c0);
            printf("%s\n", quadraticEquation(a0, b0, c0));
            break;
    case 3: splitValueCubicEquation(str);
            printf("Solving Equation %sx^3%sx^2%sx%s=0: \n", a0, b0, c0, d0);
            printf("%s\n", cubicEquation(a0, b0, c0, d0));
            break;
    case 4: //  printf("%s\n", twoHiddensEquation(str));
            break;
    case 5: //  printf("%s\n", threeHiddensEquation(str));
            break;
  }
}
