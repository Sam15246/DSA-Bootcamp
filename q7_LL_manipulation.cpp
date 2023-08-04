#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *createNode(int value = 0) // create node
{
    // Using malloc to create/allocate a node in C
    // struct ListNode* newnode = (struct ListNode *)malloc(sizeof(struct ListNode *));

    // Using malloc to create/allocate a node in C++
    // ListNode* newnode = (ListNode *)malloc(sizeof(ListNode *));

    // Using new to create/allocate a node in C++
    ListNode *newnode = new ListNode;

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}
int sizeOf(ListNode *&head)
{
    int size = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size = size + 1;
    }
    return size;
}
void insAtBeg(ListNode *&head, int value) // Insert at Beginning
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
}
void insAtEnd(ListNode *&head, int value) // Insert at End
{
    ListNode *newnode = createNode(value);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insAtIndex(ListNode *&head, int value, int index) // Insert at given Index
{
    if (index < 0 || sizeOf(head) < index)
    {
        // Invalid Index
        return;
    }
    else if (index == 0)
    {
        insAtBeg(head, value);
    }
    else
    {
        ListNode *newnode = createNode(value);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            ListNode *temp = head;
            while (index > 1)
            {
                temp = temp->next;
                index -= 1;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void delAtBeg(ListNode *&head)
{
    if (head == NULL)
    {
        return;
    }

    ListNode *temp = head;
    head = head->next;
    delete temp;
}

void delAtEnd(ListNode *&head)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void delAtIndex(ListNode *&head, int index)
{
    if (index < 0 || head == NULL)
    {
        return;
    }

    if (index == 0)
    {
        delAtBeg(head);
    }
    else
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        int i = 0;

        while (temp != NULL && i < index)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }

        if (temp == NULL)
        {
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
}

void display(ListNode *head) // Display using List Traversal
{
    cout << "\nList:";
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        temp = temp->next;
    }
}

int main()
{
    int choice, index, value;
    ListNode *head = NULL;
    while (1)
    {
        cout << "\n\n=============MENU=============\n";
        cout << "\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given index\n0.Exit\n\n";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1: // insert at beg
        {
            cout << "Enter data value: ";
            cin >> value;
            insAtBeg(head, value);
            display(head);
            break;
        }
        case 2: // insert at end
        {
            cout << "Enter data value: ";
            cin >> value;
            insAtEnd(head, value);
            display(head);
            break;
        }
        case 3: // insert at index
        {
            cout << "Enter data value: ";
            cin >> value;
            cout << "Enter index: ";
            cin >> index;
            insAtIndex(head, value, index);
            display(head);
            break;
        }
        case 4: // delete at beg
        {
            delAtBeg(head);
            display(head);
            break;
        }
        case 5: // delete at end
        {
            delAtEnd(head);
            display(head);
            break;
        }
        case 6: // delete at index
        {
            cout << "Enter index: ";
            cin >> index;
            delAtIndex(head, index);
            display(head);
            break;
        }
        case 0:
        {
            cout << "\n===========THE END===========\n ";
            return 0;
        }
        default:
        {
            cout << "Invalid choice (choose 0-6)";
        }
        }
    }
}
