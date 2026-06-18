#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

static bool tokenIsNumber(const char *token) {
	if (isdigit((unsigned char)token[0]))
		return true;
	if (token[0] == '-' && isdigit((unsigned char)token[1]))
		return true;
	return false;
}

int evalRPN(char **tokens, int tokensSize) {
	int values[tokensSize];
	int topValue = -1;

	for (int tokenIndex = 0; tokenIndex < tokensSize; tokenIndex++) {
		char *currentToken = tokens[tokenIndex];
		if (tokenIsNumber(currentToken)) {
			int number = atoi(currentToken);
			values[++topValue] = number;
		} else {
			char operator = currentToken[0];
			int rightValue = values[topValue--];
			int leftValue = values[topValue--];
			int result = 0;
			switch (operator) {
			case '+':
				result = leftValue + rightValue;
				break;
			case '-':
				result = leftValue - rightValue;
				break;
			case '*':
				result = leftValue * rightValue;
				break;
			case '/':
				result = leftValue / rightValue;
				break;
			}
			values[++topValue] = result;
		}
	}

	return values[0];
}
