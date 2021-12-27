#include <iostream>
#include <ctype.h> //fot the function isdigit()

using namespace std;
class Stack
{
private:
    int size;
    char *arr = NULL;
    int top = -1;

public:
    Stack(int len)
    {
        size = len;
        arr = new char[len];
    }
    void push(char val)
    {
        if (top == size - 1)
        {
            cout << "Stack is full\n";
            return;
        }
        else
            top++;
        arr[top] = val;
    }
    char pop()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return (char)NULL;
        }
        int current = top;
        top--;
        return arr[current];
    }
    char peek()
    {
        if (top >= 0 && top < size)
            return arr[top];
        else
            return (char)NULL;
    }
};
int precedence(char val)
{
    if (val == '^')
        return 3;
    else if (val == '/' || val == '*')
        return 2;
    else if (val == '+' || val == '-')
        return 1;
    else
        return 0;
}
string infixToPostFix(string infix)
{
    int len = infix.size();
    Stack stack(len);
    stack.push('#');
    string postfix;
    for (int i = 0; i < len; i++)
    {
        char cur_val = infix[i];
        if (isdigit(cur_val))
        { // To check if a charachter is number or not
            postfix += cur_val;
        }
        else if (cur_val == '(')
        {
            stack.push('(');
        }
        else if (cur_val == '^')
        {
            stack.push(cur_val);
        }
        else if (cur_val == ')')
        {
            while (stack.peek() != '#' && stack.peek() != '(')
            {
                postfix += stack.pop();
            }
            stack.pop(); // To remove '('
        }
        else
        {
            if (precedence(cur_val) > precedence(stack.peek()))
            {
                stack.push(cur_val);
            }
            else
            {
                while (stack.peek() != '#' && precedence(cur_val) <= precedence(stack.peek()))
                {
                    postfix += stack.pop();
                }
                stack.push(cur_val);
            }
        }
    }
    while (stack.peek() != '#')
    {
        postfix += stack.pop();
    }
    return postfix;
}
int main()
{
    cout << "Convert Infix Expression into Post Expression\n";
    cout << "Enter \"quit\" to terminate program..\n";
    string infix = "3^4/(5*3)+2";
    while (1)
    {
        cout << ">> ";
        cin >> infix;
        if (infix == "quit")
            break;
        cout << "Post Fix Expression: ";
        cout << infixToPostFix(infix) << '\n';
    }

    return 0;
}
