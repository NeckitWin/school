#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top; // wskazuje na górny element stosu

public:
    // Konstruktor inicjalizujący pusty stos
    Stack() : top(nullptr) {}

    // Funkcja do dodawania elementu na stos
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << "Dodano element: " << value << std::endl;
    }

    // Funkcja do usuwania elementu ze stosu
    void pop() {
        if (isEmpty()) {
            std::cout << "Stos pusty." << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        std::cout << "Usunięto element: " << temp->data << std::endl;
        delete temp;
    }

    // Funkcja do sprawdzania górnego elementu stosu
    int peek() {
        if (isEmpty()) {
            std::cout << "Stos pusty." << std::endl;
            return -1;
        }
        return top->data;
    }

    // Funkcja sprawdzająca, czy stos jest pusty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;

    stack.push(11);
    stack.push(22);
    stack.push(33);

    std::cout << "Górny element stosu: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); // próba usunięcia elementu z pustego stosu

    return 0;
}