// 1. Develop a menu driven program demonstrating the following operations on a Stack using array:
// (i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include <iostream>
using namespace std;

class Stack {
    int t, s;
    float *st;

public:
    Stack() {
        t = -1;
        s = 100;
        st = new float[s];
    }

    void push(float n) {
        if (t >= s - 1) {
            cout << "Cannot push as the stack is full\n";
            return;
        }
        st[++t] = n;
    }

    float pop() {
        if (t == -1) {
            cout << "Cannot pop as the stack is empty\n";
            return -1; 
        }
        return st[t--];
    }

    bool isEmpty() {
        return (t == -1);
    }

    bool isFull() {
        return (t >= s - 1);
    }

    void display() {
        if (t == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "The stack currently is (top to bottom):\n";
        for (int i = t; i >= 0; i--) {
            cout << st[i] << "  ";
        }
        cout << endl;
    }

    float peak() {
        if (t == -1) {
            cout << "Stack is empty, nothing to peek\n";
            return -1;
        }
        return st[t];
    }

    int size() {
        return t + 1;
    }
};

int main() {
    float n;
    Stack s;
    int choice;

    cout << "push-1\npop-2\nisEmpty-3\nisFull-4\ndisplay-5\npeek-6\ncheck size-7\nExit-8\n";

    do {
        cout << "Choose the operation you want to execute:\n";
        cin >> choice;
    switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> n;
            s.push(n);
            break;
        case 2:
            n = s.pop();
            if (n != -1)
            cout << "Popped value: " << n << endl;
            break;
        case 3:
            cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
            break;
        case 4:
            cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl;
            break;
        case 5:
            s.display();
            break;
        case 6:
            n = s.peak();
            if (n != -1)
            cout << "The top element is: " << n << endl;
            break;
        case 7:
            cout << "Size is: " << s.size() << endl;
            break;
        case 8:
            break;
        
    }

    } while (choice != 8);

    return 0;
}
