
bool isValid(char *s) {
    char stack[10000];
    int top = -1;
int i=0;
    while(s[i] != '\0') {
        char c = s[i];

        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } 
        else {
            if (top == -1) return false; // nothing to match
            char last = stack[top--];
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                return false;
            }
        }
        i++;
    }
    return top == -1;
}
