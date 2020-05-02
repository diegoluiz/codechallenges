#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> s;
    stack<int> m;

public:
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (m.empty())
        {
            m.push(x);
        }
        else
        {
            m.push(m.top() < x ? m.top() : x);
        }
    }

    void pop()
    {
        s.pop();
        m.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return m.top();
    }
};
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    auto *minStack = new MinStack();

    minStack->push(-1);
    minStack->top(); // -1
    minStack->push(0);
    minStack->top(); // 0
    minStack->push(-3);
    minStack->getMin(); // -3
    minStack->top();    // -3

    minStack->push(-2);
    minStack->getMin(); // -3
    minStack->top();    // -2
    minStack->pop();

    minStack->pop();
    minStack->top(); // 0
    minStack->pop();
    minStack->top();    // -1
    minStack->getMin(); // -1

    minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin();
    minStack->pop();
    minStack->top();
    minStack->getMin();

    minStack = new MinStack();
    minStack->push(512);
    minStack->push(-1024);
    minStack->push(-1024);
    minStack->push(512);
    minStack->pop();
    minStack->getMin();
    minStack->pop();
    minStack->getMin();
    minStack->pop();
    minStack->getMin();

    return 0;
}
