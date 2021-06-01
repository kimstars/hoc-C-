#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node *pre;
};

Node *lastNode(Node *root){
    while(root && root->next){
        root = root->next;
    }
    return root;
}

Node *partition(Node *l, Node *h){
    int x = h->data;
    Node *i = l->pre;
    for(Node *j = l; j != h; j = j->next){
        if( j->data <= x){
            i = (i == NULL)? l : i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == NULL)? l : i->next;
    swap(i->data, h->data);
    return i;
}

void quickSort(Node *l, Node *h){
    if(h != NULL && l != h && l != h->next){
        Node *p  = partition(l,h);
        quickSort(l, p->pre);
        quickSort(p->next, h);
    }
}

void QuickSort(Node *head){
    Node *last = lastNode(head);
    quickSort(head, last);

}

void printList(Node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void push(Node ** head_ref ,int new_data){
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->pre = NULL;
    new_node->next = (*head_ref);
    if((*head_ref) != NULL){
        (*head_ref)->pre = new_node;
    }
    (*head_ref) = new_node;
}

int main(){
    srand(time(0));
    int n;
    Node *a = NULL;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        push(&a, rand()%100 + 1);
    }
    cout << "before \n";
    printList(a);
    QuickSort(a);

    cout << "\nafter quickSort \n";
    printList(a);
    return 0;

}