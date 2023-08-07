#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *createNode(int value = 0) // create node
{
    ListNode *newnode = new ListNode;
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

int sizeOf(ListNode *head)
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

int insAtBeg(ListNode *&head, int value) // Insert at Beginning
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
    return 0;
}

int insAtEnd(ListNode *&head, int value) // Insert at End
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
    return sizeOf(head) - 1;
}

int insAtIndex(ListNode *&head, int value, int index) // Insert at given Index
{
    if (index < 0 || sizeOf(head) < index)
    {
        // Invalid Index
        return -1;
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
    return index;
}

int delAtBeg(ListNode *&head)
{
    if (head == NULL)
    {
        return -1;
    }

    ListNode *temp = head;
    head = head->next;
    int data = temp->data;
    delete temp;
    return data;
}

int delAtEnd(ListNode *&head)
{
    if (head == NULL)
    {
        return -1;
    }

    if (head->next == NULL)
    {
        int data = head->data;
        delete head;
        head = NULL;
        return data;
    }

    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int data = temp->next->data;
    delete temp->next;
    temp->next = NULL;
    return data;
}

int delAtIndex(ListNode *&head, int index)
{
    if (index < 0 || head == NULL)
    {
        return -1;
    }

    if (index == 0)
    {
        return delAtBeg(head);
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
            return -1;
        }

        int data = temp->data;
        prev->next = temp->next;
        delete temp;
        return data;
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
            index = insAtBeg(head, value);
            if (index < 0)
                cout << "-- Node can't be inserted at the specified index"<< endl;
            else
                cout << "++ Node is inserted at the specified index"<< endl;
            display(head);
            break;
        }
        case 2: // insert at end
        {
            cout << "Enter data value: ";
            cin >> value;
            index = insAtEnd(head, value);
            if (index < 0)
                cout << "-- Node can't be inserted at the specified index"<< endl;
            else
                cout << "++ Node is inserted at the specified index"<< endl;
            display(head);
            break;
        }
        case 3: // insert at index
        {
            cout << "Enter data value: ";
            cin >> value;
            cout << "Enter index: ";
            cin >> index;
            index = insAtIndex(head, value, index);
            if (index < 0)
                cout << "-- Node can't be inserted at the specified index"<< endl;
            else
                cout << "++ Node is inserted at the specified index"<< endl;
            display(head);
            break;
        }
        case 4: // delete at beg
        {
            index = delAtBeg(head);
            if (index < 0)
                cout << "-- Node can't be deleted at the specified index"<< endl;
            else
                cout << "++ Node is deleted at the specified index"<< endl;
            display(head);
            break;
        }
        case 5: // delete at end
        {
            index = delAtEnd(head);
            if (index < 0)
                cout << "-- Node can't be deleted at the specified index"<< endl;
            else
                cout << "++ Node is deleted at the specified index"<< endl;
            display(head);
            break;
        }
        case 6: // delete at index
        {
            cout << "Enter index: ";
            cin >> index;
            int data = delAtIndex(head, index);
            if (data < 0)
                cout << "-- Node can't be deleted at the specified index"<< endl;
            else
                cout << "++ Node with data " << data << " is deleted at the specified index"<< endl;
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
