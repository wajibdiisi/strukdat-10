/*
Nama Program: Queue Array
Nama		: Ahmad Irfan Fadholi
NPM			: 140810180034
Tanggal		: 8 Mei 2019
Deskripsi	: Queue Circular Array dengan maksimal element 5 
*/
#include <iostream>
using namespace std;

const int maxElemen=5; 

struct Queue{
    char isi[maxElemen];
    int head;
    int tail;
};
void createQueue(Queue &Q){
    Q.head=-1;
    Q.tail=-1;
}
void push(Queue &Q){
    if(Q.head==-1){
		Q.head++;
		Q.tail++;
		cin>>Q.isi[Q.head];
	}
	else{
		if(Q.tail<maxElemen-1){
			Q.tail++;
			cin>>Q.isi[Q.tail];
		}else{
			if(Q.head==0){
				cout<<"Queue penuh!"<<endl;
			}else{
				Q.tail=0;
				cin>>Q.isi[Q.tail];
			}
		}
	}
}
void pop(Queue &Q){
	if(Q.tail==-1){
		cout<<"Queue Kosong"<<endl;
	}else if(Q.head==Q.tail){
		Q.head=-1;
		Q.tail=-1;
	}else{
		if(Q.head<maxElemen-1){
			Q.head++;
		}else{
			Q.head=0;
		}
	}
}
void print(Queue Q){
	if(Q.head==-1){
		cout<<"Queue Kosong"<<endl;
	}else{
		int i=Q.head;
		cout<<endl<<"Queue = [";
		if(Q.head>Q.tail){
			while(i<maxElemen){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
			i=0;
			while(i<=Q.tail){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		else{
			while(i<=Q.tail){
				cout<<Q.isi[i];
				if(i!=Q.tail){
					cout<<", ";
				}
				i++;
			}
		}
		cout<<"]"<<endl;
	}
}

int main(){
    Queue Q;
	int n,choice;
	createQueue(Q);
	cout<<"Masukkan Banyak Data : ";cin>>n;
	for(int i=0; i<n; i++){
		cout<<"Masukkan Huruf : ";
		push(Q);
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
            push(Q);
	    	break;
		case 2:
			pop(Q);
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
