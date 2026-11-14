#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* down;
    Node* up;

    Node(int n) {
        data = n;
        next = NULL;
        down = NULL;
        up = NULL;
    }
};

class TwoDList {
    Node* head;
    Node* head2;

public:

    TwoDList() {
        head = NULL;
        head2 = NULL;
    }

    void layer1(int n) {
        Node* newNode = new Node(n);

        // First node of layer 1
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Insert at beginning of layer 1
        newNode->next = head;
        head->up = newNode;
        head = newNode;
    }

    void layer2(int n) {
        Node* newNode = new Node(n);

        // Layer 1 must exist first
        if (head == NULL) {
            cout << "Invalid: Create layer 1 first." << endl;
            delete newNode;
            return;
        }

        // First node of layer 2
        if (head2 == NULL) {
            head2 = newNode;

            // Connect first nodes vertically
            head->down = newNode;
            newNode->up = head;

            return;
        }

        // Insert at beginning of layer 2
        newNode->next = head2;

        // Connect vertically
        head->down = newNode;
        newNode->up = head;

        head2 = newNode;
    }

    void output() {
        Node* temp1 = head;
        Node* temp2 = head2;

        cout << "Layer 1: ";

        while (temp1 != NULL) {
            cout << temp1->data << " ";
            temp1 = temp1->next;
        }

        cout << endl;

        cout << "Layer 2: ";

        while (temp2 != NULL) {
            cout << temp2->data << " ";
            temp2 = temp2->next;
        }

        cout << endl;
    }
};

int main() {

    TwoDList ll;

    ll.layer1(2);
    ll.layer1(2);
    ll.layer1(2);

    ll.layer2(3);
    ll.layer2(3);
    ll.layer2(3);

    ll.output();

    return 0;
}