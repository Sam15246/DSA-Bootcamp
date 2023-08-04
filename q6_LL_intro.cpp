#include <iostream>
using namespace std;

struct node
{
    char x;
    node *next;
};

int main()
{

    node n1 = {'H', nullptr};
    node n2 = {'E', nullptr};
    node n3 = {'L', nullptr};
    node n4 = {'L', nullptr};
    node n5 = {'O', nullptr};

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    node *temp = &n1;
    while (temp != nullptr)
    {
        cout << temp->x;
        temp = temp->next;
    }

    
    // Dynamic declaration
    node* n1 = new node{'H', nullptr};
    node* n2 = new node{'E', nullptr};
    node* n3 = new node{'L', nullptr};
    node* n4 = new node{'L', nullptr};
    node* n5 = new node{'O', nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    temp* current = n1;
    while (temp != nullptr)
    {
        cout << temp->x;
        temp = temp->next;
    }
    cout << endl;

    
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete temp;

    return 0;
}
