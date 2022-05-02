#include <iostream>
#include <stack>

using namespace std;

void InsertatBottom(int n, stack<int> &st){

    if(st.empty()){
        st.push(n);
        return;
    }
    int topele = st.top();
    st.pop();
    InsertatBottom(n, st);
    st.push(topele);
}

void ReverseStack(stack<int> &st)
{
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    ReverseStack(st);
    InsertatBottom(ele, st);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    ReverseStack(st);

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}