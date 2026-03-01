#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

  
    if (!fast || !fast->next)
        return NULL;

    
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << "no cycle";
        return 0;
    }

    Node* head = NULL;
    Node* tail = NULL;
    Node* nodes[N];

    for (int i = 0; i < N; i++) {
        Node* temp = new Node();
        cin >> temp->data;
        temp->next = NULL;
        nodes[i] = temp;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    int pos;
    cin >> pos;

    if (pos != -1) {
        tail->next = nodes[pos];
    }

    Node* cycleNode = detectCycle(head);

    if (cycleNode == NULL) {
        cout << "no cycle";
    } else {
        for (int i = 0; i < N; i++) {
            if (nodes[i] == cycleNode) {
                cout << "tail connects to node index " << i;
                break;
            }
        }
    }

    return 0;
}