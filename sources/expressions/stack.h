typedef struct node Node;
struct node{
	char *data;
	Node *next;
};

Node* creatNode (char str[]); // tao mot node moi
void push (char str[], Node** pHead); // day mot node vao stack
char* pop (Node** pHead); // lay node tren cung cua stack
int isEmpty (Node** pHead); // kiem tra stack co rong hay khong
char get (Node** pOperator); // doc gia tri node tren cung cua stack Operator

char* caculateInfixDeg (char infix[]); // tinh bieu thuc trung to
char* caculateInfixRad (char infix[]); // tinh bieu thuc trung to
int priority (char c); // xac dinh muc do uu tien cua toan tu
int isOperator (char c); // kiem tra xem co phai la toan tu hay khong
char* getNumber (int* begin, char str[]); // tach so ra tu xau
char* getNegativeNumber (int* begin, char str[]); // lay so am
char* solveTwoOperand (char opearator, char operandA[], char operandB[], int *OK);
int isFuction (char c);
char* solveFuncDeg (char function[], char operand[]);
char* solveFuncRad (char function[], char operand[]);
int isExistFunc (char str[]); //kiem tra co ton tai mot ham toan hoc nao khong
char* getFuncName (int *begin, char str[]);

#include "operand.h"
/*
int main (int argc, char const *argv[]){
	char inFix[1000]; //bieu thuc trung to
	scanf("%s", inFix);
	printf("%s\n", caculate_infix(inFix));
	return 0;
}
*/
char* caculateInfixDeg (char infix[]){

	Node *Operands = creatNode(" "); //stack chua toan hang
	Node *Operators = creatNode(" "); //stack chua toan tu
	int leng = strlen(infix);
	int i, begin = 0, j;
	int OK = 1;
	int opearatorPriority; // muc do uu tien cua toan tu moi doc vao
	int headOpearatorPriority; // muc do uu tien cua toan tu tren dinh stack
	char *str, headOperator, CharToString[1];
	char *popOperandA, *popOperandB, *popOperator;
	char function, *funcName; //sin cos tan ...
	char *result; // result of solveTwoOperand

	for (i = 0; i < leng; i++){
		if (!isOperator(infix[i]) && !isFuction(infix[i])){
			str = getNumber (&i, infix);
			push (str, &Operands);
		}
		else {
			if (infix[i] == '('){
				if (infix[i+1] == '-'){
					str = getNegativeNumber (&i, infix);
					push (str, &Operands);
				}
				else{
					push ("(", &Operators);
				}
			}
			else if (infix[i] == ')') {
				popOperator = pop(&Operators);
				while (*popOperator != '('){
				 	popOperandA = pop(&Operands);
				 	popOperandB = pop(&Operands);
				 	result = solveTwoOperand(popOperator[0], popOperandB, popOperandA, &OK);
				 	if (!OK){
						return result;
					}
					else{
						push(result, &Operands);
					}
				 	popOperator = pop(&Operators);
				 }
			}
			else if (isFuction(infix[i])) { // sin cos tan log ln sqrt sqr
				funcName = getFuncName(&i, infix); // lay ten ham
				//tach phan bieu thuc ben trong ham toan hoc
				j = i + 2;
				str = malloc(sizeof(char)*100);
				if (infix[j] == '-'){
					str[j - (i + 2)] = infix[j];
					j++;
				}
				while (!isOperator(infix[j])){
					str[j - (i + 2)] = infix[j];
					j++;
				}
				str[j - (i + 2)] = '\0';
				//	printf("%s\n", str);

					result = solveFuncDeg(funcName, str);
					push (result, &Operands);

				i = j;
				continue;

			}
			else if (isEmpty(&Operators)){
				CharToString[0] = infix[i];
				push (CharToString, &Operators);
			}
			else {
				opearatorPriority = priority(infix[i]);

				headOperator = get (&Operators);
				headOpearatorPriority = priority(headOperator);

				if (opearatorPriority > headOpearatorPriority){
					CharToString[0] = infix[i]; // chuyen ky tu char sang string
					push (CharToString, &Operators);
				}
				else {
					// thuc hien tinh toan voi toan tu tren dinh stack
					popOperator = pop(&Operators);
				 	popOperandA = pop(&Operands);
				 	popOperandB = pop(&Operands);
				 	result = solveTwoOperand(popOperator[0], popOperandB, popOperandA, &OK);
				 	if (!OK){
						return result;
					}
					else{
						push(result, &Operands);
					}

				 	CharToString[0] = infix[i]; // chuyen ky tu char sang string
					push (CharToString, &Operators); // day toan tu moi doc vao stack
				}

			}
		}
	}
	//tinh tiep neu ngan xep chua rong
	while (!isEmpty(&Operators)){
		popOperator = pop(&Operators);
		popOperandA = pop(&Operands);
		popOperandB = pop(&Operands);
		result = solveTwoOperand(popOperator[0], popOperandB, popOperandA, &OK);
		if (!OK){
			return result;
		}
		else{
			push(result, &Operands);
		}
	}
	//tra ve ket qua
	return Operands->data;
}

char* caculateInfixRad (char infix[]){

	Node *Operands = creatNode(" "); //stack chua toan hang
	Node *Operators = creatNode(" "); //stack chua toan tu
	int leng = strlen(infix);
	int i, begin = 0, j;
	int opearatorPriority; // muc do uu tien cua toan tu moi doc vao
	int headOpearatorPriority; // muc do uu tien cua toan tu tren dinh stack
	int OK;
	char *str, headOperator, CharToString[1];
	char *popOperandA, *popOperandB, *popOperator;
	char function, *funcName; //sin cos tan ...
	char *result; // result of solveTwoOperand

	for (i = 0; i < leng; i++){
		if (!isOperator(infix[i]) && !isFuction(infix[i])){
			str = getNumber (&i, infix);
			push (str, &Operands);
		}
		else {
			if (infix[i] == '('){
				if (infix[i+1] == '-'){
					str = getNegativeNumber (&i, infix);
					push (str, &Operands);
					continue;
				}
				else{
					push ("(", &Operators);
				}
			}
			else if (infix[i] == ')') {
				popOperator = pop(&Operators);
				while (*popOperator != '('){
				 	popOperandA = pop(&Operands);
				 	popOperandB = pop(&Operands);
				 	result = solveTwoOperand(popOperator[0], popOperandB, popOperandA, &OK);
				 	if (!OK){
						return result;
					}
					else{
						push(result, &Operands);
					}
				 	popOperator = pop(&Operators);
				 }
			}
			else if (isFuction(infix[i])) { // sin cos tan log ln sqrt sqr
				funcName = getFuncName(&i, infix); // lay ten ham
				//tach phan bieu thuc ben trong ham toan hoc
				j = i + 2;
				str = malloc(sizeof(char)*100);
				if (infix[j] == '-'){
					str[j - (i + 2)] = infix[j];
					j++;
				}
				while (!isOperator(infix[j])){
					str[j - (i + 2)] = infix[j];
					j++;
				}
				str[j - (i + 2)] = '\0';
				//	printf("%s\n", str);

					result = solveFuncRad(funcName, str);
					push (result, &Operands);

				i = j;
				continue;

			}
			else if (isEmpty(&Operators)){
				CharToString[0] = infix[i];
				push (CharToString, &Operators);
			}
			else {
				opearatorPriority = priority(infix[i]);

				headOperator = get (&Operators);
				headOpearatorPriority = priority(headOperator);

				if (opearatorPriority >= headOpearatorPriority){
					CharToString[0] = infix[i]; // chuyen ky tu char sang string
					push (CharToString, &Operators);
				}
				else {
					// thuc hien tinh toan voi toan tu tren dinh stack
					popOperator = pop(&Operators);
				 	popOperandA = pop(&Operands);
				 	popOperandB = pop(&Operands);
				 	result = solveTwoOperand(popOperator[0], popOperandB, popOperandA, &OK);
				 	if (!OK){
						return result;
					}
					else{
						push(result, &Operands);
					}

				 	CharToString[0] = infix[i]; // chuyen ky tu char sang string
					push (CharToString, &Operators); // day toan tu moi doc vao stack
				}

			}
		}
	}
	//tinh tiep neu ngan xep chua rong
	while (!isEmpty(&Operators)){
		popOperator = pop(&Operators);
		popOperandA = pop(&Operands);
		popOperandB = pop(&Operands);
		result = solveTwoOperand(popOperator[0], popOperandB, popOperandA, &OK);
		if (!OK){
			return result;
		}
		else{
			push(result, &Operands);
		}
		
	}
	//tra ve ket qua
	return Operands->data;
}

char* solveFuncDeg (char function[], char operand[]){
	char *result;
		// printf("%s\n", function);
		// printf("%s\n", operand);
		if (strcmp("sin", function) == 0){
			result = dSin(operand);
		}
		else if (strcmp("cos", function) == 0){
			result = dCoSin(operand);
		}
		else if (strcmp("tan", function) == 0){
			result = dTan(operand);
		}
		else if (strcmp("log", function) == 0){
			result = logarit(operand);
		}
		else if (strcmp("ln", function) == 0){
			result = logn(operand);
		}
		else if (strcmp("sqrt", function) == 0){
			result = sqRt(operand);
		}
		else if (strcmp("cbrt", function) == 0){
			result = cbRt(operand);
		}
	return result;
}

char* solveFuncRad (char function[], char operand[]){
	char *result;
		// printf("%s\n", function);
		// printf("%s\n", operand);
		if (strcmp("sin", function) == 0){
			result = rSin(operand);
		}
		else if (strcmp("cos", function) == 0){
			result = rCoSin(operand);
		}
		else if (strcmp("tan", function) == 0){
			result = rTan(operand);
		}
		else if (strcmp("log", function) == 0){
			result = logarit(operand);
		}
		else if (strcmp("ln", function) == 0){
			result = logn(operand);
		}
		else if (strcmp("sqrt", function) == 0){
			result = sqRt(operand);
		}
		else if (strcmp("cbrt", function) == 0){
			result = cbRt(operand);
		}
	return result;
}

int isExistFunc (char str[]){
	int leng = strlen(str);
	int i;
	for (i = 0; i < leng; i++){
		if (isFuction(str[i]) || isOperator(str[i])){
			return 1;
		}
	}
	return 0;
}

char* solveTwoOperand (char operator, char operandA[], char operandB[], int *OK){
	char *result;
	static char error[14] = "Can't div Zero";
	switch (operator){
		case '+' :
			result = bigAdd(operandA, operandB);
			break;
		case '-' :
			result = bigSub(operandA, operandB);
			break;
		case '*' :
			result = bigMul(operandA, operandB);
			break;
		case '/' :
			if (strcmp("0", operandB) == 0){
				*OK = 0;
				return error;
			}
			else {
				result = bigDiv(operandA, operandB);
			}
			break;
		case '%' :
			result = bigMod(operandA, operandB);
			break;
		case '^' :
			result = Exp(operandA, operandB);
			break;
		case 'r' :
			result = nthRoot(operandA, operandB);
			break;
	};
	return result;
}

char* getNumber (int* begin, char str[]){
	int i = *begin, count = 0, leng = strlen(str);
	char *strnum = malloc(sizeof(char)*100);
	while (!isOperator(str[i]) && (i < leng)){
		strnum[count] = str[i];
		count++;
		i++;
	}
	strnum[count] = '\0';
	*begin = *begin + count - 1;
	return strnum;
}

char* getNegativeNumber (int* begin, char str[]){
	int i = *begin + 1, count = 0, leng = strlen(str);
	char *strnum = malloc(sizeof(char)*100);
	strnum[0] = str[i]; //lay dau am
	count++;
	i++;
	while (!isOperator(str[i]) && (i < leng)){
		strnum[count] = str[i];
		count++;
		i++;
	}
	strnum[count] = '\0';
	*begin = *begin + count + 1;
	return strnum;
}

char* getFuncName (int *begin, char str[]){
	int i = *begin, count = 0, leng = strlen(str);
	char *strname = malloc(sizeof(char)*5);
	while (str[i] != '(' && (i < leng)){
		strname[count] = str[i];
		count++;
		i++;
	}
	strname[count] = '\0';
	*begin = *begin + count - 1;
	return strname;
}

int priority (char c){
	if (c =='^' || c == 'r'){
		return 3;
	}
	else if (c == '*' || c == '/' || c == '%'){
		return 2;
	}
	else if (c == '+' || c == '-'){
		return 1;
	}
	else if (c == '('){
		return 0;
	}
}

int isOperator (char c){
	if (c == '%' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c =='^' || c == 'r'){
		return 1;
	}
	else if (c == 's' || c == 'c' || c == 't' || c == 'l'){
		return 1;
	}
	else {
		return 0;
	}
}

int isFuction(char c){
	char funcList[4] = "sctl";
	if (strchr(funcList, c) != NULL){
		return 1;
	}
	return 0;
}

char* pop (Node** pHead){
	char *str;
	Node* pNew = (*pHead);
	*pHead = (*pHead)->next;
	str = (*pNew).data;
	free(pNew);
	return str;
}

void push (char str[], Node** pHead){
	//tao them mot node chua ky tu c
	Node* p = creatNode(str);
	//day node vao stack
	p->next = *pHead; //tro p vao head (*pHead == head)
	*pHead = p; //gan p cho pHead
}

Node* creatNode(char str[]){
	int leng = strlen(str);
	Node *p = NULL;
	p = malloc(sizeof(Node));
	if (p == NULL){
		exit(0);
	}
	else {
		p->next = NULL;
		p->data = malloc(sizeof(char)*leng);
		strcpy((*p).data, str);
	}
	return p;
}

char get (Node** pOperator){
	Node *pNew = *pOperator;
	return *((*pNew).data);
}

int isEmpty (Node** pHead){
	Node *pNew = *pHead;
	if (pNew->next == NULL){
		return 1;
	}
	return 0;
}
