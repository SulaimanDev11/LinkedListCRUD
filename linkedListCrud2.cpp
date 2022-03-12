#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct node{
	int data;
	node *next,*prev;
}*head=NULL,*tail=NULL,*temp,*curr;
class student{
	private:
		int i=0,del;
	public:
		void CreatFun(){
			 temp=new node;
			 cout<<"Enter data: ";
			 cin>>temp->data;
			 temp->next=NULL;
			 temp->prev=NULL;
		}
		
		void AddNode(){
			CreatFun();
			if(head==NULL){
				head=temp;
				tail=temp;
			}
			else{
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
			}			
		}
		
		void AddNodeBefore(){
			CreatFun();
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
		
		void specificNode(int no){
			CreatFun();
			curr=head;
			while(curr!=NULL){
				if(i==no){
					temp->next=curr->next;
					curr->next->prev=temp;
					curr->next=temp;
					temp->prev=curr;
				}
				i++;
				curr=curr->next;
			}
		} 
		void searchNode(){
			cout<<"\nEnter Data to search node";
			cin>>i;
			curr=head;
			while(curr!=NULL){
				if(i==curr->data){
					cout<<"\nData found\n";
					getch();
					break;
				}		
				curr=curr->next;
			}
		}
		void display(){
			curr=head;
			while(curr!=NULL){
				cout<<curr->data<<endl;
				curr=curr->next;
			}
			getch();
		}
		void deleteNode(){
			curr=head;
			cout<<"Enter data to delete :";
			cin>>del;
			while(curr!=NULL){
				if(curr->next->data==del){
					temp=curr->next;
					curr->next=curr->next->next;
					curr->next->prev=curr;
					delete temp;
					break;
				}
				curr=curr->next;
			}
		}
};
int main(){
	student obj;
	int no,op;
	while(true){
		system("cls");
		cout<<"\n1. ADD NODE\n\n2.ADD BEFORE\n\n3. SPECIFIC POINT\n\n4. DELETE NODE\n\n5. SEARCH NODE\n\n6. DISPLAY\n\n\t Enter option: ";
		cin>>op;
		switch(op){
			case 1:{
				obj.AddNode();
				break;
			}
			case 2:{
				obj.AddNodeBefore();
				break;
			}	
			case 3:{
				cout<<"Enter place for node: ";
				cin>>no;
				obj.specificNode(no);
				break;
			}	
			case 4:{
				obj.deleteNode();
				break;
			}	
			case 5:{
				obj.searchNode();
				break;
			}	
			case 6:{
				obj.display();
				break;
			}			
		}
	} 
}
