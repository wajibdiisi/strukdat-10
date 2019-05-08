/*
Nama Program: Queue Linked List
Nama		: Ahmad Irfan Fadholi
NPM			: 140810180034
Tanggal		: 8 Mei 2019
Deskripsi	: Queue Circular Linked List dengan maksimal element 5 
*/
#include <iostream>
using namespace std;

const int maxElemen=5;

struct QueueList{
	char info;
	QueueList* next;
};

struct Queue{
	QueueList *head;
	QueueList *tail;
};

typedef QueueList* pointer;
typedef pointer List;

void createQueue(Queue &Q){
	Q.head=NULL;
	Q.tail=NULL;
}

void createList(pointer &pBaru){
	pBaru=new QueueList;
	cout << "Masukkan Huruf : "; cin>>pBaru->info;
	pBaru->next=NULL;
}

void push(Queue& Q, pointer pBaru){
	if(Q.head==NULL){
		Q.head=pBaru;
		Q.tail=pBaru;
	}
	else{
		Q.tail->next=pBaru;
		Q.tail=pBaru;
	}
}

void pop(Queue &Q, pointer pHapus){
	if(Q.head==NULL){
		cout<<"Queue Kosong"<<endl;
	}else{
		pointer pHapus;
		pHapus=Q.head;
		Q.head=Q.head->next;
		pHapus->next=NULL;
	}
}

void print(Queue Q){
	if(Q.head==NULL){
		cout<<"Queue Kosong"<<endl;
	}
	else{
		pointer pBantu=Q.head;
		cout<<endl<<"Queue = [";
		while(pBantu!=NULL){
			cout<<pBantu->info;
			if(pBantu->next!=NULL){
				cout<<", ";
			}
			pBantu=pBantu->next;
		}
		cout<<"]"<<endl;
	}
}

int main(){
	Queue Q;
	pointer p, pHapus;
	int n,choice;
	
	createQueue(Q);
	cout<<"Masukkan Banyak Data : ";cin>>n;
		for(int i=0; i<n; i++){
			createList(p);
			push(Q,p);
	}
	do{
        cout<<"1.Push\n";
        cout<<"2.Pop\n";
        cout<<"3.Print \n";
        cout<<"4.Quit\n-----------\n";
        cout<<"> Masukkan Pilihan : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            if (n>=5){
            	cout<<"Queue Penuh\n";
			}
			else{
			createList(p);
			push(Q,p);
			}
			break;
		case 2:
			pop(Q,p);
			n--;
			break;
        case 3:
        	print(Q);
	   		break;
		case 4:
			break;
	   	default:
	    cout<<"Pilihan Salah\n";
	}
    }
    while(choice != 4);
    return 0;
}
