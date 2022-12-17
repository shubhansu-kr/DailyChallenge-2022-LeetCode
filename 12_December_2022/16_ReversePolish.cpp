// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};

class Solution
{
    // Runtime error: Integer overflow
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<long long> st;
        long long a, b;
        for (auto &it : tokens)
        {
            if (it == "/" || it == "*" || it == "+" || it == "-")
            {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();

                if (it == "*"){st.push(a*b);}
                else if (it == "+"){st.push(a+b);}
                else if (it == "-"){st.push(a-b);}
                else{st.push(a/b);}
            }
            else{st.push(stoi(it));}
        }
        return st.top();
    }
};

int main()
{
    cout << (4 / -3) << endl;
    return 0;
}