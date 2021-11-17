#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node(int dt)
    {
        data = dt;
    }
};
class LinkedList
{
private:
    Node *head;
    int length;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    // Prints The whole LinkedList
    void print()
    {
        Node *cur;
        cur = head;
        cout << "head -> ";
        while (cur != NULL)
        {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "tail" << endl;
    }
    void append(int dt)
    {
        if (head == NULL)
        {
            head = tail = new Node(dt);
            length++;
        }
        else
        {
            tail = tail->next = new Node(dt);
            length++;
        }
    }
    // Add an element to begging of the LinkedList
    void prepend(int dt)
    {
        Node *temp = new Node(dt);
        temp->next = head;
        head = temp;
        length++;
    }
    // Remove given element from them LinkedList
    void del(int dt)
    {
        Node *cur = head;
        Node *prev = NULL;
        Node *temp = NULL;
        while (cur != NULL && cur->data != dt)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head)
        {
            temp = head;
            head = head->next;
            delete temp;
            length--;
        }
        else if (cur == NULL && prev != NULL)
            return;
        else
        {
            prev->next = cur->next;
            delete cur;
            length--;
        }
    }
    // returns length of the LinkedList
    int len()
    {
        return length;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "LinkedList is Empty" << endl;
            return (int)NULL;
        }
        Node *cur = head;
        Node *prev = NULL;
        int val;
        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head)
        {
            head = NULL;
            delete cur;
            length--;
            return cur->data;
        }
        prev->next = NULL;
        val = cur->data;
        delete cur;
        length--;
        return val;
    }
    // reverses the LinkedList
    void reverse()
    {
        tail = head;
        Node *cur = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    void insertNextTo(int pos, int value)
    {
        Node *cur = head;
        while (cur != NULL && cur->data != pos)
        {
            cur = cur->next;
        }
        if (cur == NULL)
            return;
        Node *temp = new Node(value);
        temp->next = cur->next;
        cur->next = temp;
        length++;
    }
    void update(int oldVal, int newVal)
    {
        Node *cur = head;
        while (cur != NULL && cur->data != oldVal)
        {
            cur = cur->next;
        }
        if (cur == NULL)
            return;
        cur->data = newVal;
    }
    // deletes all node from the heap memory
    void delLinkedList(Node *temp)
    {
        Node *cur = temp;
        Node *temp1 = temp;
        if (temp1->next != NULL)
        {
            temp1 = temp1->next;
            delLinkedList(temp1);
        }
        delete cur;
    }
    ~LinkedList()
    {
        delLinkedList(head);
    }
};

int main()
{
    LinkedList l1;
    int len, value, choice, pos, newVal;
    l1.append(22);
    l1.append(87);
    l1.append(65);
    l1.append(9);
    l1.append(27);
    while (choice != 9)
    {
        cout << endl
             << "Select a Below LinkedList actions: " << endl
             << "1.Insert" << endl
             << "2.Delete" << endl
             << "3.Update" << endl
             << "4.Reverse" << endl
             << "5.Append" << endl
             << "6.Prepend" << endl
             << "7.Pop" << endl
             << "8.Length" << endl
             << "9.Quit" << endl;
        cout << "Current linked list: " << endl;
        l1.print();
        cout << endl;
        cout << "Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value after which to insert: ";
            cin >> pos;
            cout << "Enter the value: ";
            cin >> value;
            l1.insertNextTo(pos, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            l1.del(value);
            break;
        case 3:
            cout << "Enter old value: ";
            cin >> value;
            cout << "Enter new value: ";
            cin >> newVal;
            l1.update(value, newVal);
            break;
        case 4:
            cout << "Reversing the LinkedList..." << endl;
            l1.reverse();
            break;
        case 5:
            cout << "Enter value to append: ";
            cin >> value;
            l1.append(value);
            break;
        case 6:
            cout << "Enter a value to Prepend: ";
            cin >> value;
            l1.prepend(value);
            break;
        case 7:
            l1.pop();
            break;
        case 8:
            cout << "Length is " << l1.len() << endl;
            break;
        case 9:
            cout << "Thank You =)" << endl
                 << "Final LinkedList: " << endl;
            break;
        default:
            cout << "Enter a valid choice..." << endl;
            break;
        }
        l1.print();
    }

    return 0;
}