
                while (!st.empty() && getPrecedence(c) == getPrecedence(st.top()))
                {
                    postfixResult += st.top();
                    st.pop();
                }
            