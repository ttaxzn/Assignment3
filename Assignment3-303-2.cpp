#include <iostream>
using namespace std;

class Node {
public:
        int data;
        Node* next;
};

Node* SortedMerge(Node* a, Node* b);
void FrontBackSplit(Node* source,
                                        Node** frontRef, Node** backRef);

void MergeSort(Node** headRef)
{
        Node* head = *headRef;
        Node* a;
        Node* b;

        if ((head == NULL) || (head->next == NULL)) {
                return;
        }

        FrontBackSplit(head, &a, &b);

        MergeSort(&a);
        MergeSort(&b);

        *headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
        Node* result = NULL;
        if (a == NULL)
                return (b);
        else if (b == NULL)
                return (a);

        if (a->data <= b->data) {
                result = a;
                result->next = SortedMerge(a->next, b);
        }
        else {
                result = b;
                result->next = SortedMerge(a, b->next);
        }
        return (result);
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
        Node* fast;
        Node* slow;
        slow = source;
        fast = source->next;

        while (fast != NULL) {
                fast = fast->next;
                if (fast != NULL) {
                        slow = slow->next;
                        fast = fast->next;
                }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
}

void printList(Node* node)
{
        while (node != NULL) {
                cout << node->data << " ";
                node = node->next;
        }
}

void push(Node** head_ref, int new_data)
{
        Node* new_node = new Node();

        new_node->data = new_data;

        new_node->next = (*head_ref);

        (*head_ref) = new_node;
}

int main()
{
        Node* res = NULL;
        Node* a = NULL;

        push(&a, 12);
        push(&a, 8);
        push(&a, 18);
        push(&a, 2);
        push(&a, 9);
        push(&a, 38);

        cout << "Unsorted Linked List is: \n";
        printList(a);
        cout<<endl;

        MergeSort(&a);

        cout << "Sorted Linked List is: \n";
        printList(a);
        cout<<endl;
        return 0;
}
