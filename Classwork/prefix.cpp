
#include <bits/stdc++.h>
using namespace std;

int getPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperand(char c)
{
    return isalnum(c);
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    stack<char> st;
    string postfixResult = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isOperand(c))
        {
            postfixResult += c;
        }
        else if (c == ')')
        {
            st.push(c);
        }
        else if (c == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                postfixResult += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && getPrecedence(c) < getPrecedence(st.top()))
            {
                postfixResult += st.top();
                st.pop();
            }

            if (c == '^')
            {
                while (!st.empty() && getPrecedence(c) == getPrecedence(st.top()))
                {
                    postfixResult += st.top();
                    st.pop();
                }
            }

            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfixResult += st.top();
        st.pop();
    }

    reverse(postfixResult.begin(), postfixResult.end());

    return postfixResult;
}

int main()
{
    string infix = "a*(b+c)/d";

    cout << "Infix Expression: " << infix << endl;
    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;

    return 0;
}