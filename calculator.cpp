#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Calculator {
private:
    stack<string> history;

public:
    void performOperation(char op, double num1, double num2) {
        double result;

        switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 == 0) {
                    cout << "Error: Cannot divide by zero.\n";
                    return;
                }
                result = num1 / num2;
                break;
            default:
                cout << "Invalid operator.\n";
                return;
        }

        cout << "Result: " << result << "\n";
        string entry = to_string(num1) + " " + op + " " + to_string(num2) + " = " + to_string(result);
        history.push(entry);
    }

    void showHistory() {
        if (history.empty()) {
            cout << "No calculations yet.\n";
            return;
        }

        cout << "\n--- Calculation History (Latest First) ---\n";
        stack<string> temp = history;
        while (!temp.empty()) {
            cout << temp.top() << "\n";
            temp.pop();
        }
    }
};

int main() {
    Calculator calc;
    double num1, num2;
    char op;
    int choice;

    do {
        cout << "\n--- Simple Calculator ---\n";
        cout << "1. Perform Operation (+, -, *, /)\n";
        cout << "2. Show History\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter first number: ";
                cin >> num1;
                cout << "Enter operator (+ - * /): ";
                cin >> op;
                cout << "Enter second number: ";
                cin >> num2;
                calc.performOperation(op, num1, num2);
                break;

            case 2:
                calc.showHistory();
                break;

            case 3:
                cout << "Exiting calculator. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
