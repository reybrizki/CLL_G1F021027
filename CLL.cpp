#include <iostream>
using namespace std;

// deklarasi circular double linked list
struct node{												// Dibuat oleh Nama : Rey Babul Rizki_NPM : G1F021027
	int data;
	node *prev;
	node *next;
};

node *head, *tail, *cur, *newNode, *del, *afterNode;

// Create Circular Double Linked List
void createCircularDoubleLinkedList(int data){
	head = new node();
	head->data = data;
	head->prev = head;
	head->next = head;
	tail = head;
}

// tambahAwal atau Insert First Double Linked list
void addFirst(int data){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
		newNode = new node();
	    newNode->data = data;
	    newNode->prev = tail;
	    newNode->next = head;
	    head->prev = newNode;
	    tail->next = newNode;
		head = newNode;
  }
}

// tambahAkhir atau Insert Last Circular Double Linked List
void addLast(int data){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
	}else{
	    newNode = new node();
	    newNode->data = data;
	    newNode->prev = tail;
	    newNode->next = head;
	    tail->next = newNode;
	    head->prev = newNode;
	    tail = newNode;
	}
}

// tambahTengah atau Insert Before Circular Double Linked List
void addMiddle( int data, int posisi ){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{

    if (posisi == 1){
      cout << "Posisi bukan posisi tengah!" << endl;
    }else if (posisi < 1){
      cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	newNode = new node();
    	newNode->data = data;

    	// tranversing
    	cur = head;
    	int nomor = 1;
    	while( nomor <  posisi - 1){
    		cur = cur->next;
        	nomor++;
      	}

    	afterNode = cur->next;
    	newNode->prev = cur;
    	newNode->next = afterNode;
    	cur->next = newNode;
    	afterNode->prev = newNode;
    }
  }
}

// Remove First atau Delete First
void removeFirst(){
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
		del = head;
    	head = head->next;
    	tail->next = head;
    	head->prev = tail;
    	delete del;
	}
}

// Remove Last atau Delete Last
void removeLast(){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
	}else{
    	del = tail;
    	tail = tail->prev;
    	tail->next = head;
    	head->prev = tail;
    	delete del;
	}
}

// Remove Middle
void removeMiddle(int posisi){
	if (head == NULL){
		cout << "Circular Double Linked List belum dibuat!";
  }else{
    if (posisi == 1){
    	cout << "Posisi bukan posisi tegah!" << endl;
    }else if (posisi < 1){
    	cout << "Posisi diluar jangkauan!" << endl;
    }else{
    	//tranversing
    	int nomor = 1;
    	cur = head;
		while(nomor < posisi - 1){
        	cur = cur->next;
        	nomor++;
    	}
    	del = cur->next;
    	afterNode = del->next;
    	cur->next = afterNode;
    	afterNode->prev = cur;
    	delete del;
    }
  }
}

// Print Circular Double Linked List
void printNode()
{
	if (head == NULL){
    	cout << "Circular Double Linked List belum dibuat!";
	}else{
    	cout << "INFO DATA" << endl;
    	cur = head;
    	while (cur->next != head){
    		// print
    		cout << "Data : " << cur->data << endl;
    		//step
    		cur = cur->next;
    	}
    //print Last Node
    cout << "Data : " << cur->data << endl;
  }
}

// searching (sequential)
void searchNode(node **head, int id){
    int currentID = 1;
    node *cur = *head;
    while (cur->next != 0 && currentID != id){
        cur = cur->next;
        currentID++;
    }
    cout << cur->data << " ditemukan pada data ke " << currentID;
}

int main(){
	cout << "Membuat Data Double Linked List" << endl;
	createCircularDoubleLinkedList(1);
	printNode();
	
	cout << "\nInsert First" << endl;
	addFirst(9);
	printNode();
	
	cout << "\nInsert Last" << endl;
	addLast(20);
	printNode();
	
	cout << "\nDelete First" << endl;
	removeFirst();
	printNode();
	
	cout << "\nInsert Last" << endl;
	addLast(14);
	printNode();
	
	cout << "\nDelete Last" << endl;
	removeLast();
	printNode();
	
	cout << "\nInsert Before" << endl;
	addMiddle(27, 2);
	printNode();
	
	cout << "\nDelete Before data ke 3" << endl;
	removeMiddle(2);
	printNode();
	
	cout << "\nSearching data : 20" << endl;  
	searchNode(&head, 2);
}
