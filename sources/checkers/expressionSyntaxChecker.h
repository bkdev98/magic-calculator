int checkExpressionSyntax(char s[]) {
  char digits[10] = "0123456789";
	char symbol[24] = "0123456789+-*/^vsctlL().";
	char operand[6] = "+-*/^v";
	char func[5] = "sctlL";
	int bracket = 0;
	//-11  thieu ngoac
	//-12  thieuToanTu // (5*6)(5-6)
	//-13  thuaToanTu // 5**6
	//-14  divZero // 5/0
	//-15  _v4 6v_
	//-16  ngoacRong // (5*8)*()/(5+4)
	//-18  soThucSai // 5.*6.1
	//-19  kyTuLa // 56a*8

	int i, leng;
	leng = strlen(s);
	for (i = 0; i < leng; i++){
		if (strchr(symbol, s[i]) == NULL){
			return -19;
		}
		if (s[i] == '(' || s[i] == ')'){
			bracket++;
		}
		if (s[i] == '(' && s[i+1] == ')'){
			return -16;
		}
		if (s[i] == '/' && s[i+1] == '0'){
			return -14;
		}
		if ((s[i] == '.') && (strchr(digits, s[i+1]) != NULL || strchr(digits, s[i-1]) != NULL)) {
			return -18;
		}
		if (s[i] == ')' && (s[i+1] == '(' || strchr(func, s[i+1]) != NULL) && (i < leng - 1)) {
			return -12;
		}
		if ((s[i]  == 'r') && (strchr(digits, s[i+1]) == NULL || strchr(digits, s[i-1])== NULL)) {
			return -15;
		}
		if ((strchr(operand, s[i])) != NULL && (strchr(operand, s[i+1])) != NULL){
			return - 13;
		}
	}
	if (bracket % 2 != 0){
		return -11;
	}
	return 1;
};
