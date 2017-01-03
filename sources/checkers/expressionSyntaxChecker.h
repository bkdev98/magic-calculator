int checkExpressionSyntax(char s[]) {
  char digits[10] = "0123456789";
	char symbol[24] = "0123456789+-*/^vsctlL().";
	char operand[6] = "+-*/^v";
	char func[5] = "sctlL";
	int bracket = 0;
	//-1  thieu ngoac
	//-2  thieuToanTu // (5*6)(5-6)
	//-3  thuaToanTu // 5**6
	//-4  divZero // 5/0
	//-5  _v4 6v_
	//-6  ngoacRong // (5*8)*()/(5+4)
	//-8  soThucSai // 5.*6.1
	//-9  kyTuLa // 56a*8
	int i, leng;
	leng = strlen(s);
	for (i = 0; i < leng; i++){
		if (strchr(symbol, s[i]) == NULL){
			return -9;
		}
		if (s[i] == '(' || s[i] == ')'){
			bracket++;
		}
		if (s[i] == '(' && s[i+1] == ')'){
			return -6;
		}
		if (s[i] == '/' && s[i+1] == '0'){
			return -4;
		}
		if ((s[i] == '.') && (strchr(digits, s[i+1]) != NULL || strchr(digits, s[i-1]) != NULL)) {
			return -8;
		}
		if (s[i] == ')' && (s[i+1] == '(' || strchr(func, s[i+1]) != NULL) && (i < leng - 1)) {
			return -2;
		}
		if ((s[i]  == 'v') && (strchr(digits, s[i+1]) == NULL || strchr(digits, s[i-1])== NULL)) {
			return -5;
		}
		if ((strchr(operand, s[i])) != NULL && (strchr(operand, s[i+1])) != NULL){
			return - 3;
		}
	}
	if (bracket % 2 != 0){
		return -1;
	}
	return 1;
};
