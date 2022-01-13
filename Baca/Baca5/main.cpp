// VAN THE HO

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1000

template<typename T>
class Stack {
    int top;

public:
    T a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }

    void push(T x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow";
        } else {
            a[++top] = x;
        }
    };

    void pop() {
        if (top < 0) {
            cout << "Stack Underflow";
        } else {
            top--;
        }
    };

    T peek() {
        if (top < 0) {
            cout << "Stack is Empty";
            return 0;
        } else {
            char x = a[top];
            return x;
        }
    };

    bool isEmpty() {
        return (top < 0);
    };
};

void countTrueStatements(const string &prefix, int n, bool flag[], int arr[], int i, int k, int &count);

void isTautology(const string &prefix, int n, bool flag[], int arr[], int i, int k, bool &check);

string convertInfixToPrefix(string infix, Stack<char> stack);

bool evaluateValue(string prefix, int arr[26]);

bool isOperator(char symbol);

int getNumberOfVariables(const string &basicString, bool flag[26]);

void evaluateByMode(char mode);

void mode_T();

void mode_P();

void mode_F();

void mode_1();

void mode_0();


int main() {

    char key;

    bool quit = false;

    while (!quit) {

        cin >> key;
        switch (key) {
            case 'T':
                mode_T();
                break;
            case 'P':
                mode_P();
                break;
            case 'F':
                mode_F();
                break;
            case '0':
                mode_0();
                break;
            case '1':
                mode_1();
                break;
            case 'W':
                quit = true;
                break;
            default:
                cout << "Default";
        }
    }

    return 0;
}


int getNumberOfVariables(const string &basicString, bool flag[26]) {
    int count = 0;
    for (char i: basicString) {
        if (isalnum(i)) {
            flag[i - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (flag[i]) count++;
    }

    return count;
}

// TODO
void isTautology(const string &prefix, int n, bool flag[], int arr[], int i, int k, bool &check) {
    if (!check) return;

    if (i == n) {
        if (!evaluateValue(prefix, arr)) { check = false; }
        return;
    }

    while (!flag[k]) k++;
    arr[k] = 0;
    isTautology(prefix, n, flag, arr, i + 1, k + 1, check);
    arr[k] = 1;
    isTautology(prefix, n, flag, arr, i + 1, k + 1, check);
}

// TODO
void countTrueStatements(const string &prefix, int n, bool flag[], int arr[], int i, int k, int &count) {
    if (i == n) {
        if (evaluateValue(prefix, arr)) { count++; }
        return;
    }

    while (!flag[k]) k++;
    arr[k] = 0;
    countTrueStatements(prefix, n, flag, arr, i + 1, k + 1, count);
    arr[k] = 1;
    countTrueStatements(prefix, n, flag, arr, i + 1, k + 1, count);

}

bool isOperator(char symbol) {
    switch (symbol) {
        case '|':
        case '~':
        case '=':
        case '>':
        case '&':
            return true;
        default:
            return false;
    }
}

int precedence(char c) {
    if (c == '~')
        return 3;
    else if (c == '|' or c == '>' or c == '=' or c == '&')
        return 2;
    else
        return 1;
}

void reverse(string &str) {
    for (int i = 0; i < str.length() / 2; i++) {
        char temp = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = temp;
    }
}

// DONE
string convertInfixToPrefix(string infix, Stack<char> stack) {
    string prefix;

    reverse(infix);

    for (char &i: infix) {
        if (i == '(') {
            i = ')';
        } else if (i == ')') {
            i = '(';
        }
    }


    for (char &i: infix) {
        if ((i >= 'a' && i <= 'z')) {
            prefix += i;
        } else if (i == '(') {
            stack.push(i);
        } else if (i == ')') {
            while ((stack.peek() != '(') && (!stack.isEmpty())) {
                prefix += stack.peek();
                stack.pop();
            }
            if (stack.peek() == '(') {
                stack.pop();
            }
        } else if (isOperator(i)) {
            if (stack.isEmpty()) {
                stack.push(i);
            } else {
                if (precedence(i) > precedence(stack.peek())) {
                    stack.push(i);
                } else if (precedence(i) == precedence(stack.peek())) {
                    while (!stack.isEmpty() and stack.peek() == '~') {
                        prefix += stack.peek();
                        stack.pop();
                    }
                    stack.push(i);
                } else {
                    while ((!stack.isEmpty()) && (precedence(i) < precedence(stack.peek()))) {
                        prefix += stack.peek();
                        stack.pop();
                    }
                    stack.push(i);
                }
            }
        }
    }

    while (!stack.isEmpty()) {
        prefix += stack.peek();
        stack.pop();
    }

    reverse(prefix);
    return prefix;

}

bool NOT(int a) {
    return a == 0;
}

bool OR(int a, int b) {
    return !(a == 0 and b == 0);
}

bool AND(int a, int b) {
    return (a == 1 and b == 1);
}

bool IMPL(int a, int b) {
    return !(a == 1 and b == 0);
}

bool EQUAL(int a, int b) {
    return a == b;
}

bool evaluateValue(string prefix, int arr[26]) {
    Stack<int> stack;
    reverse(prefix);
    for (char j: prefix) {

        if (isalnum(j))
            stack.push(arr[j - 'a']);

        else {

            int o1, o2;

            if (j == '~') {
                o1 = stack.peek();
                stack.pop();
            } else {
                o1 = stack.peek();
                stack.pop();
                o2 = stack.peek();
                stack.pop();
            }

            switch (j) {
                case '~':
                    stack.push(NOT(o1));
                    break;
                case '=':
                    stack.push(EQUAL(o1, o2));
                    break;
                case '>':
                    stack.push(IMPL(o1, o2));
                    break;
                case '&':
                    stack.push(AND(o1, o2));
                    break;
                case '|':
                    stack.push(OR(o1, o2));
                    break;
                default:
                    break;
            }
        }
    }

    //reverse(prefix);
    return stack.peek();
}

void mode_T() {
    evaluateByMode('T');
}

void mode_P() {

    evaluateByMode('P');
}

void mode_F() {

    evaluateByMode('F');
}

void mode_0() {
    evaluateByMode('0');
}

void mode_1() {
    evaluateByMode('1');
}

void evaluateByMode(char mode) {
    char c;
    if (mode == '0' or mode == '1') {
        cin >> c;
    }

    string infix;
    cin >> infix;

    int count = 0;
    Stack<char> stack;
    string prefix = convertInfixToPrefix(infix, stack);

    bool flag[26]{false};
    int arr[26]{0};


    int numOfVariables = getNumberOfVariables(prefix, flag);

    if (mode == '1') {
        arr[c - 'a'] = 1;
        flag[c - 'a'] = false;
    } else if (mode == '0') {
        arr[c - 'a'] = 0;
        flag[c - 'a'] = false;
    }

    bool check = true;
    if (mode == 'T') {
        isTautology(prefix, numOfVariables, flag, arr, 0, 0, check);
    } else {
        countTrueStatements(prefix, numOfVariables, flag, arr, 0, 0, count);
    }

    switch (mode) {
        case 'T':
            if (check) {
                cout << "TAK" << endl;
            } else {
                cout << "NIE" << endl;
            }
            break;
        case 'F':
            cout << pow(2, numOfVariables) - count << endl;
            break;
        case 'P':
            cout << count << endl;
            break;
        case '0':
        case '1':
            if (count == pow(2, numOfVariables)) {
                cout << "TAK" << endl;
            } else {
                cout << "NIE" << endl;
            }
        default:
            break;
    }

}
