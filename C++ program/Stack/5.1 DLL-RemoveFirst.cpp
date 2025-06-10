#include <iostream>

using namespace std;


class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            this->next = nullptr;
            this->prev = nullptr;
        }
};


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList() {
            Node* temp = head;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            cout << "Head: " << head->value << endl;
        }

        void getTail() {
            cout << "Tail: " << tail->value << endl;
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        Node* removeLast() {
            if (length == 0) return nullptr;
            Node* temp = tail;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
                temp->prev = nullptr;
            }
            length--;
            return temp;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        Node* removeFirst() {
            if (length == 0) return nullptr;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
                temp->next = nullptr;
            }
            length--;
            return temp;
        }

};



int main() {
        
    DoublyLinkedList* myDLL = new DoublyLinkedList(2);
    myDLL->append(1);

    // (2) Items - Returns 2 Node
    cout << myDLL->removeFirst()->value << endl;
    // (1) Item -  Returns 1 Node
    cout << myDLL->removeFirst()->value << endl;
    // (0) Items - Returns nullptr
    cout << myDLL->removeFirst() << endl;
        
}


