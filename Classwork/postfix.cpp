#include <bits/stdc++.h>
using namespace std;

int evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    default:
        return 0;
    }
}

int evaluatePrefix(string prefix)
{
    reverse(prefix.begin(), prefix.end());

    stack<int> st;

    for (int i = 0; i < prefix.length(); i++)
    {
        char c = prefix[i];

        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int op1 = st.top();
            st.pop();

            int op2 = st.top();
            st.pop();

            int ans = evaluate(op1, op2, c);
            st.push(ans);
        }
    }

    return st.top();
}

int main()
{
    string prefix = "-+8/632";

    cout << "Prefix Expression: " << prefix << endl;
    cout << "Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}