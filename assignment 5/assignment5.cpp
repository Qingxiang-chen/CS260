#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
#define biggest 1e9

struct node{
	int data;
	node* next;
	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

//range (1-10^9)
//order  ascending integers

class list{
private:
	node* head;
	int maxn;
	int minn;
	int length;
public:
	list(){
		maxn = -1;
		minn = biggest;
		length = 0;
	}

	int Length(){
		return length;
	}

	node* AddNode(int data){
		if (data<0 || data>biggest) return NULL;
		node* newnode = new node(data);
		if (length == 0){
			head = newnode;
			goto end;
		}
		if (data <= minn){			//insert before the first node
			newnode->next = head;
			head = newnode;
			goto end;
		}
		node* temp = head;
		node* temp2 = NULL;			//the father of temp
		while (temp->next != NULL && temp->data <= data){
			temp2 = temp;
			temp = temp->next;
		}	
		if (temp->next == NULL ){	//insert after the lastest node
			temp->next = newnode;
			goto end;
		}
		else{	//inset to the midle of list
			temp2->next = newnode;
			newnode->next = temp;
		}
	end:
		length++;
		minn = min(minn, data);
		maxn = max(maxn, data);
		return newnode;	
	}

	void Show(){
		if (length == 0) {
			cout << "The list is empty !\n";
			return;
		}
		cout << "max: " << maxn << "  minn: " << minn << endl;
		cout << "List: ";
		node* temp = head;
		while (temp->next != NULL){
			cout << temp->data;
			temp = temp->next;
			cout << " -> ";
		}
		cout << temp->data << endl;
	}
};


//cin data -> cin 1  see the order data  cin 2 show the length 
int main(){
	list mylist; 
	int temp;
	while (cin >> temp){
		if (temp >= 0 && temp < biggest){
			mylist.AddNode(temp);
		}
		if (temp == -1){
			mylist.Show();
		}
		if (temp == -2){
			cout << "the length of list is "<<mylist.Length() << endl;;
		}
	}
	return 0;
}