#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int num;
    Node *next;
};

class LinkedList {
public:
    Node *head;
    Node *tail;
    int count;
public:
    LinkedList()
    {
        head = new Node;
        head->next = nullptr;
        tail = head;
    }
    Node* getHead(){ return head; }
    void insertItem(int);
    void replaceItem(int, int);
    void displayList(Node*);
    void deleteItem(int);
    void searchItem(int);
    void insertItem(int, int);
};

void LinkedList::insertItem(int number)
{
    Node *temp = new Node;
    temp->num = number;
    temp->next = nullptr;
    tail->next = temp;
    tail = temp;
}

void LinkedList::insertItem(int index, int number)
{
    Node *temp = head;
    for(int i = 0; i < index; i++)
    {
        if(temp->next != nullptr)
        {
            temp = temp->next;
        }
        else
        {
            insertItem(number);
            return;
        }
    }

    Node *tempNew = new Node;
    tempNew->num = number;
    tempNew->next = temp->next;
    temp->next = tempNew;
}

void LinkedList::replaceItem(int index, int number)
{
    Node *temp = head;
    if(temp->next == nullptr)
    {
        cout << "Linked List empty" << endl;
        return;
    }
    if(index < 0)
    {
        cout << "Index should be greater than 0" << endl;
        return;
    }
    for(int i = 0; i < index; i++)
    {
        if(temp->next != nullptr)
        {
            temp = temp->next;
        }
        else
        {
            cout << "Index out of bounds" << endl;
            return;
        }
    }

    Node *tempNew = new Node;
    tempNew->num = number;
    tempNew->next = temp->next->next;
    if(temp->next == tail)
    tail=tempNew;
    temp->next = tempNew;
}

void LinkedList::deleteItem(int index)
{
    if(index > count)
    {
        cout << "Linked List Index OverFlow" << endl;
        return;
    }

    if(index < 0)
    {
        cout << "Linked List Index UnderFlow" << endl;
        return;
    }

    Node *temp = head->next;
    Node *prev = head;

    if(temp == nullptr)
    {
        cout << "List Empty" << endl;
        return;
    }

    for(int i = 0; i < index; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(tail == temp)
    {
        tail = prev;
    }

    prev->next = temp->next;
    cout << "Deleted the node at index : " << index << " successfully." << endl;
}

void LinkedList::displayList(Node *n)
{
    if(n->next == nullptr)
    {
        cout << endl;
        return;
    }
    cout << n->next->num << " ";
    displayList(n->next);
}

void LinkedList::searchItem(int item)
{
    Node *temp = head;
    if(temp->next == nullptr)
    {
        cout << "Linked List Empty" << endl;
        return;
    }
    int i = 0;
    while(temp->next != nullptr)
    {
        temp = temp->next;
        if(temp->num == item)
        {
            cout << "Number Found at : " << i << " index." << endl;
            return;
        }
        i++;
    }
    cout << "Number not found!!!" << endl;
}



int main()
{
    LinkedList list;
    while(1)
    {
        cout << "CHOICES : \n";
        cout << "1. INSERT AN ITEM\n";
        cout << "2. INSERT AN ITEM AT AN INDEX\n";
        cout << "3. DELETE AN ITEM\n";
        cout << "4. SEARCH FOR AN ITEM\n";
        cout << "5. REPLACE AN ITEM\n";
        cout << "6. DISPLAY THE LIST\n";
        cout << "0. EXIT THE PROGRAM\n\n";
        int a;
        cout <<"\tENTER THE CHOICE : \n\t";
        cin >> a;
        int i,num;

        switch(a)
        {
            case 0:
                exit(0);
            case 1:
                cout << "Please Enter the item to be inserted:\n";
                cin >> num;
                list.insertItem(num);
                break;
            case 2:
                cout << "Please Enter the index:\n";
                cin >> i;
                cout << "Please Enter the number:\n";
                cin >> num;
                list.insertItem(i,num);
                break;
            case 3:
                cout << "Please enter the index of the number to be deleted:\n";
                cin >> i;
                list.deleteItem(i);
                break;
            case 4:
                cout << "Please Enter the item to be searched:\n";
                int num;
                cin >> num;
                list.searchItem(num);
                break;
            case 5:
                cout << "Please Enter the index of the item to be replaced:\n";
                cin >> i;
                cout << "Please Enter the number:\n";
                cin >> num;
                list.replaceItem(i, num);
                break;
            case 6:
                cout << "The contents of the list are:\n";
                list.displayList(list.getHead());
                break;
        }
    }
}