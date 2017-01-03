#include "equations/splitValue.h"
#include "equations/calcEquation.h"
#include "equations/unknownEquation.h"

void solveEquation(char str[]) {
  int type = typeEquation(str);
  switch (type) {
    case 1: splitValueBasicEquation(str);
            printf("Solving Equation %sx%s=0: \n", a0, b0);
            printf("%s\n", basicEquation(a0, b0));
            break;
    case 2: splitValueQuadraticEquation(str);
            printf("Solving Equation %sx^2%sx%s=0: \n--------\n", a0, b0, c0);
            printf("%s\n", quadraticEquation(a0, b0, c0));
            break;
    case 3: splitValueCubicEquation(str);
            printf("Solving Equation %sx^3%sx^2%sx%s=0:\n--------\n", a0, b0, c0, d0);
            printf("%s\n", cubicEquation(a0, b0, c0, d0));
            break;
    case 4: splitValueTwoHiddensEquation(str);
            printf("Solving Two Hiddens Equation:\n(1) %sx%sy=%s\n&\n(2) %sx%sy=%s\n--------\n", a0, b0, c0, a1, b1, c1);
            printf("%s\n", twoHiddensEquation(a0, b0, c0, a1, b1, c1));
            break;
    case 5: //  splitValueThreeHiddensEquation(str);
            //  printf("Solving Three Hiddens Equation:\n(1) %sx%sy%sz=%s\n&\n(2) %sx%sy%sz=%s\n&\n(3) %sx%sy%sz=%s\n--------\n", a0, b0, c0, d0, a1, b1, c1, d1, a2, b2, c2, d2);
            //  printf("%s\n", threeHiddensEquation(a0, b0, c0, d0, a1, b1, c1, d1, a2, b2, c2, d2));
            break;
  }
}
