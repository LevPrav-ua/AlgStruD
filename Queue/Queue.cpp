
#include <iostream>
#define qs 7

class Queue{
    int data[qs];
    int head = 0;
    int tail = 0;
    unsigned int size = 0;
 
public:
    void push(int num) {
        tail = (tail == qs) ? 0 : tail ;
        if (size != qs) {
            data[tail++] = num;
            size++;
        }
        else {
            std::cout << "Queue is full\n";
        }
    }
    int pop() {
        head = (head == qs) ? 0 : head;
        if (size != 0) {
            size--;
            return data[head++];
        }
        else {
            std::cout << "Queue is empty\n";
            head = tail = 0;
            return -1;
        }
    }

    int front() { 
        if (size != 0) { 
            return data[head];
        }
        else {
            std::cout << "Queue is empty \n";
            return -1;
        }
    }
    int back() {
        if (size != 0) {
            return data[tail-1];
        }
        else {
            std::cout << "Queue is empty \n";
            return -1;
        }
    }

    void show() {
        if (size != 0) {
            if (tail <= head) {
                for (int i = head; i < qs; i++) {
                    std::cout << data[i]<<" ";
                }
                for (int i = 0; i < tail; i++) {
                    std::cout << data[i] << ' ';
                }
                std::cout << "\n";
            }
            else {
                for (int i = head; i < tail; i++) {
                    std::cout << data[i] << " ";
                }
                std::cout << "\n";
            }
        }
        else {
            std::cout << "Queue is empty\n";
            head = tail = 0;
        }
    }
    void isEmpty() { if (size == 0) std::cout << "Queue is empty\n"; else std::cout<< "Queue is not empty\n"; }
    void isFull() { if (size == qs)  std::cout << "Queue is full\n"; else std::cout << "Queue is not full\n"; }
};

int main()
{
    Queue q;
    
    //q.pop();
    //q.isEmpty();
    //q.isFull();
    //q.show();
    //q.push(1);
    //q.push(4);
    //q.push(88);
    //q.pop();
    //q.show();
    //int i = 6;
    //while (i--) {
    //    q.push(5);
    //}
    //i = 9;
    //while (i--) {
    //   std::cout<< q.pop()<<" ";
    //}
    //q.isEmpty();
    //q.show();
    //

    q.push(1); q.pop(); q.push(8); q.push(5); q.push(1); q.push(1); q.pop(); 
    q.push(4); q.push(3); q.push(4);
    
    q.show();
    std::cout<<q.front() << " " << q.back();

    return 0;
}
