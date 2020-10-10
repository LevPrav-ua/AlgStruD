#include <iostream>
#define ss 5
//ss - это stack size, ничего плохого

class Stack {
    int stack[ss];
    int  index = -1;
public:
    int pop() {
        if (index > -1) {
            return stack[index--];
        }
        else {
            std::cout << "Stack is empty\n";
            return -1;
        }
    }
    void push(int num) {
        if (index == ss - 1) {
            std::cout << "Stack is full\n";
        }
        else {
            stack[++index] = num;
        }
    }

    void showStack() {
        for (int i = 0; i <= index; i++) {
            std::cout << stack[i] << " ";
        }
        std::cout << "\n";
    }

    void isEmpty() {
        if (index == -1) {
            std::cout << "Stack is empty\n";
        }
        else {
            std::cout << "Stack is not empty\n";
        }
    }
    bool isFull() {
        if (index == ss) {
            std::cout << "Stack is full\n";
            return true;
        }
        else {
            std::cout << "Stick your.... I mean Stack is not full\n";
            return false;
        }
    }
    int peek() {
        if (index == -1) {
            std::cout << "You cant take a number from the empty stack\n";
            return -1;
        }
        else if (index == ss ) {
            return stack[index-1];
        }
        else {
            return stack[index];
        }
    }
};

int main()
{
    //setlocale(0, "rus");
    Stack test;
   /* test.push(1);
    test.pop();
    test.pop();
    test.push(4);
    test.push(8);
    */
    test.push(1);
    test.push(4);
  //  test.showStack();
    test.push(8);
  //  test.push(8);
   // test.showStack();
    test.pop();
    test.push(8);
    test.pop();
    test.pop();
    test.push(5);
    test.pop();
    test.pop();
    std::cout << "Order: 1 -> 4-> 8-> <- 8-> <- <- 5-> <- <-\n";
    test.isEmpty();
    test.showStack();
    return 0;
}
