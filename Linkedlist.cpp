#include <iostream>
using namespace std;
class Node 
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr)
	 {}
};

class LinkedList
 {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the linked list
    void insertEnd(int value)
	 {
        Node* newNode = new Node(value);
        if (head == nullptr)
		 {
            head = newNode;
        } else
		 {
            Node* temp = head;
            while (temp->next != nullptr) 
			{
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display the linked list
    void display() 
	{
        Node* temp = head;
        while (temp != nullptr)
		 {
            cout << temp->data << " ";
            temp = temp->next;
        }
       cout <<endl;
    }

    // Function to search for a value in the linked list
    bool search(int value) 
	{
        Node* temp = head;
        while (temp != nullptr) 
		{
            if (temp->data == value) 
			{
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to update the value at a specific position in the linked list
    void updateAtPosition(int position, int value)
	 {
        Node* temp = head;
        for (int i = 1; i < position && temp != nullptr; ++i) 
		{
            temp = temp->next;
        }

        if (temp != nullptr) {
            temp->data = value;
        } else {
           cout << "Position out of bounds." <<endl;
        }
    }

    // Function to insert a node at a specific position in the linked list
    void insertAtPosition(int position, int value) 
	{
        Node* newNode = new Node(value);

        if (position == 1) 
		{
            newNode->next = head;
            head = newNode;
        } else 
		{
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; ++i)
			 {
                temp = temp->next;
            }

            if (temp != nullptr) {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
               cout << "Position out of bounds." <<endl;
            }
        }
    }

    // Function to delete a node from the beginning of the linked list
    void deleteFromBeginning() 
	{
        if (head != nullptr)
		 {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
         cout << "List is empty. Cannot delete from the beginning." <<endl;
        }
    }

    // Function to delete a node from the end of the linked list
    void deleteFromEnd() 
	{
        if (head == nullptr) 
		{
           cout << "List is empty. Cannot delete from the end." <<endl;
            return;
        }

        if (head->next == nullptr)
		 {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) 
		{
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Function to delete a node from a specific position in the linked list
    void deleteFromPosition(int position)
	 {
        if (position == 1) 
		{
            deleteFromBeginning();
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1 && temp != nullptr; ++i) 
			{
                temp = temp->next;
            }

            if (temp != nullptr && temp->next != nullptr) 
			{
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
             cout << "Position out of bounds." <<endl;
            }
        }
    }

    // Destructor to free the memory occupied by the linked list
    ~LinkedList() 
	{
        Node* temp;
        while (head != nullptr) 
		{
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() 
{
    LinkedList list;

    // Inserting elements at the end
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);

    // Displaying the linked list
  	cout << "Linked List: ";
    list.display();

    // Searching for an element
    int searchValue = 2;
    if (list.search(searchValue)) {
       cout << searchValue << " found in the list." <<endl;
    } else {
        std::cout << searchValue << " not found in the list." <<endl;
    }

    // Updating a value at a specific position
    int positionToUpdate = 2;
    int newValue = 4;
    list.updateAtPosition(positionToUpdate, newValue);
   cout << "Updated value at position " << positionToUpdate << ": ";
    list.display();

    // Inserting a new value at a specific position
    int positionToInsert = 2;
    int valueToInsert = 5;
    list.insertAtPosition(positionToInsert, valueToInsert);
    cout << "Linked List after inserting " << valueToInsert << " at position " << positionToInsert << ": ";
    list.display();

    // Deleting a node from the beginning
    list.deleteFromBeginning();
    cout << "Linked List after deleting from the beginning: ";
    list.display();

    // Deleting a node from the end
    list.deleteFromEnd();
    cout << "Linked List after deleting from the end: ";
    list.display();

    // Deleting a node from a specific position
    int positionToDelete = 1;
    list.deleteFromPosition(positionToDelete);
    cout << "Linked List after deleting from position " << positionToDelete << ": ";
    list.display();

    return 0;
}
