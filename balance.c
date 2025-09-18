#include <stdio.h>
#include <string.h>

#define MAX 1000

char* isBalanced(char* s) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) {
                return "NO";
            }
            char popped = stack[top--];
            if ((c == ')' && popped != '(') ||
                (c == '}' && popped != '{') ||
                (c == ']' && popped != '[')) {
                return "NO";
            }
        }
    }

    if (top == -1) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[MAX];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    return 0;
}