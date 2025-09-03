#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

int main()
{
    string postfix;
    stack<int> st;
    map<char, int> values;

    int i, op1, op2, val;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    for (i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];
        if (isalpha(c))
        {
            if (values.find(c) == values.end())
            {
                cout << "Enter value for " << c << ": ";
                cin >> val;
                values[c] = val;
            }
            st.push(values[c]);
        }
        else
        {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            if (c == '+')
                st.push(op1 + op2);
            else if (c == '-')
                st.push(op1 - op2);
            else if (c == '*')
                st.push(op1 * op2);
            else if (c == '/')
                st.push(op1 / op2);
        }
    }
    cout << "Result: " << st.top();
    return 0;
}