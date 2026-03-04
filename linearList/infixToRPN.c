#include <stdio.h>
#include <stdlib.h>
// We assume that s[] is an legal expression and operands are letters like 'a' 'b' etc.
// 若为'('入栈
// 若为')'把所有'('之前出栈且删除'('
// 若为运算符：
//'*' 或 '/'
// 栈顶一直弹出直到遇到 '+' 或 '-' 或 '(' 或空栈然后入栈
//'+' 或 '-'
// 栈顶一直弹出直到遇到 '(' 或空栈
void infixToRPN(char *s)
{
    int slen = 0;
    while (s[slen] != '\0')
        ++slen;

    int RPNlen = 0;
    char *stack = (char *)malloc(sizeof(char) * slen);
    int top = -1;
    for (int i = 0; i < slen; ++i)
    {
        if ('(' == s[i])
            stack[++top] = '(';
        else if (')' == s[i])
        {
            while (top > -1 && '(' != stack[top])
                s[RPNlen++] = stack[top--];
            --top; // discard '('
        }
        else
        {
            if ('*' == s[i] || '/' == s[i])
            {
                while (top > -1 && ('*' == stack[top] || '/' == stack[top]))
                    s[RPNlen++] = stack[top--];
                stack[++top] = s[i];
            }
            else if ('+' == s[i] || '-' == s[i])
            {
                while (top > -1 && stack[top] != '(')
                    s[RPNlen++] = stack[top--];
                stack[++top] = s[i];
            }
            else
            {
                s[RPNlen++] = s[i];
            }
        }
    }
    while (top > -1)
        s[RPNlen++] = stack[top--];
    s[RPNlen] = '\0';
    free(stack);
}

int main(void) {
    char s[] ="a+((b*c-d)/(e-f)*g)+h";
    printf("infix: %s\n", s);
    infixToRPN(s);
    printf("  RPN: %s\n", s);
    return 0;
}