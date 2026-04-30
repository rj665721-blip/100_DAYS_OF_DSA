// Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <ctype.h>
int calculate(char *s) {
    int result = 0;
    int last = 0;
    int num = 0;
    char sign = '+';
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if ((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0') {
            if (sign == '+') {
                result += last;
                last = num;
            }
            else if (sign == '-') {
                result += last;
                last = -num;
            }
            else if (sign == '*') {
                last = last * num;
            }
            else if (sign == '/') {
                last = last / num;
            }
            sign = s[i];
            num = 0;
        }
    }
    return result + last;
}