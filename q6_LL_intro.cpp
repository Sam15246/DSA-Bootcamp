#include <iostream>
using namespace std;

struct node
{
    char x;
    node *next;
};

int main()
{
    // Static declaration
    node n1 = {'H', nullptr};
    node n2 = {'E', nullptr};
    node n3 = {'L', nullptr};
    node n4 = {'L', nullptr};
    node n5 = {'O', nullptr};

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    node *temp1 = &n1;
    while (temp1 != nullptr)
    {
        cout << temp1->x;
        temp1 = temp1->next;
    }

    cout << endl;

    // Dynamic declaration
    node *dn1 = new node{'H', nullptr};
    node *dn2 = new node{'E', nullptr};
    node *dn3 = new node{'L', nullptr};
    node *dn4 = new node{'L', nullptr};
    node *dn5 = new node{'O', nullptr};

    dn1->next = dn2;
    dn2->next = dn3;
    dn3->next = dn4;
    dn4->next = dn5;

    node *temp2 = dn1;
    while (temp2 != nullptr)
    {
        cout << temp2->x;
        temp2 = temp2->next;
    }

    cout << endl;

    // Deleting the dynamically allocated nodes.
    delete dn1;
    delete dn2;
    delete dn3;
    delete dn4;
    delete dn5;

    return 0;
}
