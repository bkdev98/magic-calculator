#include "equations/calcEquation.h"
#include "equations/unknownEquation.h"

void solveEquation(char str[]) {
  int type = typeEquation(str);
  switch (type) {
    case 1: printf("Solving Equation %sx%s=0\n", a0, b0);
            printf("%s\n", basicEquation(a0, b0));
            break;
    case 2: printf("Solving Equation %sx^2%sx%s=0\n", a0, b0, c0);
            printf("%s\n", quadraticEquation(a0, b0, c0));
            break;
    case 3: printf("Solving Equation %sx^3%sx^2%sx%s=0:\n", a0, b0, c0, d0);
            printf("%s\n", cubicEquation(a0, b0, c0, d0));
            break;
    case 4: printf("Solving Two Hiddens Equation:\n(1) %sx%sy=%s\n(2) %sx%sy=%s\n", a0, b0, c0, a1, b1, c1);
            printf("%s\n", twoHiddensEquation(a0, b0, c0, a1, b1, c1));
            break;
    case 5: printf("Solving Three Hiddens Equation:\n(1) %sx%sy%sz=%s\n(2) %sx%sy%sz=%s\n(3) %sx%sy%sz=%s\n", a0, b0, c0, d0, a1, b1, c1, d1, a2, b2, c2, d2);
            printf("%s\n", threeHiddensEquation(a0, b0, c0, d0, a1, b1, c1, d1, a2, b2, c2, d2));
            break;
  }
}
