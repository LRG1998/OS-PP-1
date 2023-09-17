#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(){
            data = 0;
            next = NULL;
        }

        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class LinkedList{
    
    private:
        Node* head;
    public:
    //default constructor.  Basically copied so I have a framework to work with. 
        LinkedList(){
            head = NULL;
        }
        ~LinkedList() {
            cout<<"In destructor \n";
            Node* curr = head;
            while(curr!=NULL){
                Node* saveNext = curr->next;
                delete curr;
                curr = saveNext;
            }
        }

        //New node function
        void addNode(int data) {
            Node* newNode = new Node(data);

            //Empty case code
            if(head == NULL) {
                //if the head is a NULL value, the new node becomes the head. 
                head = newNode;
                return;
            }
            Node* temp = head;
            while(temp->next!= NULL){
                //So long as the next node isn't NULL, the temporary value's next value is shifted until the next node from temp is NULL, this enables making a new node at the end.
                temp=temp->next;
            }
            temp-> next = newNode;
            
        }
        void deleteNode(int key) {
            Node* prev =  NULL; //points to node prior to current. 
            Node* curr = head; //Sets current node to the head. "Curr" is an insult I'm sure, though. So I guess we're insulting the nodes. 
            //Case of empty list.
            if(curr/*Again with the insults*/ == NULL){
                return;
            }
            //search
            bool found = false;
            while(curr -> next != NULL && !found){
                if(curr->data == key){
                    found = true;
                }else{
                    prev = curr;
                    curr = curr -> next;
                }
            }

            if(prev==NULL){
                head = curr -> next;
            }else{
                prev -> next = curr -> next;
            }
            delete curr;
        }
        void printList() {
            Node* temp  = head;
            //In case user is trying to delete an already empty list.
            if(head == NULL){
                cout<<"List is already empty." << endl;
                return;
            }else{
                cout<<"Elements of the list are: ";
            }
            while(temp!=NULL){
                cout<<temp->data<< " ";
                temp = temp -> next;
            }
            cout<<endl;
        }

};