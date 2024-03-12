#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    LinkedList(const LinkedList& other) : head(nullptr) {
        Node* temp = other.head;
        while (temp != nullptr) {
            push_back(temp->data);
            temp = temp->next;
        }
    }

    LinkedList* clone() const {
        return new LinkedList(*this);
    }

    LinkedList* operator+(const LinkedList& other) const {
        LinkedList* result = new LinkedList(*this);
        Node* temp = other.head;
        while (temp != nullptr) {
            result->push_back(temp->data);
            temp = temp->next;
        }
        return result;
    }

    LinkedList* operator*(const LinkedList& other) const {
        LinkedList* result = new LinkedList();
        Node* temp1 = head;
        while (temp1 != nullptr) {
            Node* temp2 = other.head;
            while (temp2 != nullptr) {
                if (temp1->data == temp2->data) {
                    result->push_back(temp1->data);
                    break;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return result;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    cout << "List1: ";
    list1.display();

    LinkedList<int> list2;
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    cout << "List2: ";
    list2.display();

    LinkedList<int>* cloneList = list1.clone();
    cout << "Clone of List1: ";
    cloneList->display();

    LinkedList<int>* sumList = list1 + list2;
    cout << "Sum of List1 and List2: ";
    sumList->display();

    LinkedList<int>* intersectList = list1 * list2;
    cout << "Intersection of List1 and List2: ";
    intersectList->display();

    delete cloneList;
    delete sumList;
    delete intersectList;
}
