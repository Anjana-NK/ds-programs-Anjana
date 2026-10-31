#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (char c : postfix)
    {
        // If operand
        if (isdigit(c))
        {
            s.push(c - '0');
        }

        // If operator
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            if (c == '+')
                s.push(a + b);

            else if (c == '-')
                s.push(a - b);

            else if (c == '*')
                s.push(a * b);

            else if (c == '/')
                s.push(a / b);

            else if (c == '^')
            {
                int result = 1;

                for (int i = 0; i < b; i++)
                    result *= a;

                s.push(result);
            }
        }
    }

    cout << "Result = " << s.top();

    return 0;
}