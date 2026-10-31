#include <iostream>
#include <stack>
using namespace std;

int priority(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    string infix, postfix = "";
    stack<char> s;

    cin >> infix;

    for (char c : infix)
    {
        if (isalnum(c))
            postfix += c;

        else if (c == '(')
            s.push(c);

        else if (c == ')')
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }

        else
        {
            while (!s.empty() &&
                   priority(s.top()) >= priority(c))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << postfix;

    return 0;
}