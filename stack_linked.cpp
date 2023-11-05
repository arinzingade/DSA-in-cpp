

#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* t;
};

Stack* c() {
    Stack* s = new Stack;
    s->t = nullptr;
    return s;
}

bool e(Stack* s) {
    return s->t == nullptr;
}

void p(Stack* s, int v) {
    Node* n = new Node;
    n->data = v;
    n->next = s->t;
    s->t = n;
}

int o(Stack* s) {
    if (e(s)) {
        std::cout << "Empty. Cannot pop." << std::endl;
        return -1;
    }
    int v = s->t->data;
    Node* n = s->t;
    s->t = s->t->next;
    delete n;
    return v;
}

int k(Stack* s) {
    if (e(s)) {
        std::cout << "Empty. No top element." << std::endl;
        return -1;
    }
    return s->t->data;
}

void ds(Stack* s) {
    while (!e(s)) {
        o(s);
    }
    delete s;
}

int main() {
    Stack* s = c();

    int ch, v;

    std::cout << "Arin Zingade" << std::endl;
    std::cout << "0801IT221035" << std::endl;

    do {
        std::cout << "Stack Operations:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> ch;

        switch (ch) {
            case 1:
                std::cout << "Enter a value to push: ";
                std::cin >> v;
                p(s, v);
                break;
            case 2:
                v = o(s);
                if (v != -1) {
                    std::cout << "Popped: " << v << std::endl;
                }
                break;
            case 3:
                v = k(s);
                if (v != -1) {
                    std::cout << "Top element: " << v << std::endl;
                }
                break;
            case 4:
                std::cout << "Quitting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (ch != 4);

    ds(s);

    return 0;
}
