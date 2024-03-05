#include <iostream>
#include "Stack.h"
#include "Node.h"
#include "Stack.cpp" 

int main() {
    // Create a stack object
    Stack stack;
    int value;
    int numValues;

    // Ask the user for the number of values they want to add to the stack
    cout << "Enter the number of values you want to add to the stack: ";
    cin >> numValues;

    // Prompt the user to enter values and add them to the stack
    cout << "Enter " << numValues << " values to add to the stack:\n";
    for (int i = 0; i < numValues; ++i) {
        cout << "Value " << i + 1 << ": ";
        cin >> value;
        stack.push(value);
    }

    int choice = 0;
    // Display menu and perform operations until user chooses to quit (option 6)
    while (choice != 6) {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Check if stack is empty\n";
        cout << "2. Push element onto stack\n";
        cout << "3. Pop element from stack\n";
        cout << "4. Get top element of stack\n";
        cout << "5. Get average value of stack elements\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform operations based on user's choice
        switch (choice) {
            case 1:
                // Check if stack is empty and print appropriate message
                if (stack.EmptyOrNo()) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Stack is not empty\n";
                }
                break;
            case 2:
                // Push value onto stack
                cout << "Enter value to push onto stack: ";
                cin >> value;
                stack.push(value);
                cout << "Value pushed onto stack\n";
                break;
            case 3:
                // Pop top element from stack
                if (stack.EmptyOrNo()) {
                    cout << "Stack is empty, cannot pop\n";
                } else {
                    stack.pop();
                    cout << "Top element popped from stack\n";
                }
                break;
            case 4:
                // Get top element of stack and print it
                if (stack.EmptyOrNo()) {
                    cout << "Stack is empty\n";
                } else {
                    cout << "Top element of stack: " << stack.top() << endl;
                }
                break;
            case 5:
                // Get average value of stack elements and print it
                if (stack.EmptyOrNo()) {
                    cout << "Stack is empty";
                } else {
                    cout << "Average value of stack elements: " << stack.average() << endl;
                }
                break;
            case 6:
                // Exit the program
                cout << "Exiting program\n";
                break;
            default:
                // Handle invalid choice
                cout << "Invalid choice, please try again\n";
        }
    }

    return 0;
}