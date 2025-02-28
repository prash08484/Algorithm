// Function to convert an infix expression to a postfix expression.
int hash(char c) // to set preference order :
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    return 1;
}
string infixToPostfix(string s)
{
    // step 1 : if you get operand then print asap
    // if get operator then remove all the operator that have greater or equal precedence and print
    // if get (  then push in stack
    // if get ) the pop till you not get it's opening bracket

    string res = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            // pop till you not got : "("
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            while ((st.empty() == 0) && (st.top() != '(') && (hash(st.top()) >= hash(c)))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
        else
        {
            // you have got char
            res += c;
        }
    }
    while (st.empty() == 0 && st.top() != '(')
    {
        res += st.top();
        st.pop();
    }
    return res;
}
