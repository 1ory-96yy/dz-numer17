#include <iostream>

template<typename T>
class TemplateQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    TemplateQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(const T& val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty, cannot dequeue.\n";
        }
        else {
            Node* temp = front;
            front = front->next;
            if (front != nullptr) {
                front->prev = nullptr;
            }
            else {
                rear = nullptr;
            }
            delete temp;
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    T peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty.\n";
            throw std::out_of_range("Queue is empty.");
        }
        else {
            return front->data;
        }
    }

    void show() const {
        Node* temp = front;
        std::cout << "Queue elements: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~TemplateQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    TemplateQueue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.show();
    std::cout << "Peek: " << intQueue.peek() << std::endl;
    intQueue.dequeue();
    intQueue.show();
    TemplateQueue<double> doubleQueue;
    doubleQueue.enqueue(3.14);
    doubleQueue.enqueue(2.718);
    doubleQueue.show();
    std::cout << "Peek: " << doubleQueue.peek() << std::endl;

    return 0;
}
