/*
Nama        : Shania Salsabila
NPM         : 140810180014
Deskripsi   : excercise-01
Tahun       : 2019
*/
#include <iostream>

using namespace std;

struct Elemtlist{
	char nama[20], divisi[30];
	int gaji;
	Elemtlist* next;
};
typedef Elemtlist* pointer;
typedef pointer List;

void createList(List& First){
	First=NULL;
}

void createElmt(pointer& pBaru) {
	pBaru= new Elemtlist;
	cout<< "Masukkan Nama Pegawai  : ";
	cin>>pBaru->nama, 20;
	cout<< "Masukkan Divisi        : ";
	cin>>pBaru->divisi, 30;
	pBaru->next = NULL;
}

void insertFirst(List& First, pointer pBaru){
	if (First==NULL){
	First=pBaru;
}
	else {
	pBaru->next=First;
	First=pBaru;
	}
}
void traversal(List First){
 pointer pBantu;
    pBantu=First;
    while(pBantu != NULL){
        cout<<"Nama     : "<<pBantu->nama<<endl;
        cout<<"Divisi   : "<<pBantu->divisi<<endl;
        cout<<"Gaji     : "<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
    }
}
void deleteFirst(List& First,pointer pHapus){
	cout<<"Delete First"<<endl;
	if (First==NULL){
	pHapus= NULL;
	cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){
	pHapus=First;
	First=NULL;
	}
	else {
	pHapus=First;
	First=First->next;
	pHapus->next=NULL;
	}
}

void insertLast(List& First,pointer pBaru){
	pointer last;
	cout<<"Insert Last"<<endl;
	if (First==NULL){
	First=pBaru;
	}
	else {
	last=First;
	while (last->next!=NULL){
	last=last->next;
	}last->next=pBaru;
	}
	}

void deleteLast(List& First,pointer pHapus){
	pointer last,precLast;
	cout<<"Delete Last"<<endl;
	if (First==NULL){
	pHapus=NULL;
	cout<<"List kosong, tidak ada yang dihapus"<<endl;
	}
	else if (First->next==NULL){
	pHapus=First;
	First=NULL;
	}
	else {
	last=First;
	precLast=NULL;
	while (last->next!=NULL){
	precLast=last;
	last=last->next;
	}
	pHapus=last;
	precLast->next=NULL;
	}
}

int main(){
	pointer Baru,hapus;
	int x;
	List list;
	createList(list);
	while(x!=4){
	cout<<" =====Menu====== "<<endl;
	cout<<"|1.Insert First |"<<endl;
	cout<<"|2.Insert Last  |"<<endl;
	cout<<"|3.Delete First |"<<endl;
	cout<<"|4.Delete Last  |"<<endl;
	cout<<"|5.Exit         |"<<endl;
	cout<<"Pilihan = "; cin>>x;
	cout<<endl;

	switch(x){
	case 1:
	createElmt(Baru);
	insertFirst(list,Baru);
	cout<<endl;
	createElmt(Baru);
	insertFirst(list,Baru);
	cout<<endl;
	createElmt(Baru);
	insertFirst(list,Baru);
	traversal(list);
	cout<<endl;
	break;

	case 2:
	createElmt(Baru);
	insertLast(list,Baru);
	cout<<endl;
	createElmt(Baru);
	insertLast(list,Baru);
	cout<<endl;
	createElmt(Baru);
	insertLast(list,Baru);
	traversal(list);
	cout<<endl;
	break;

	case 3:
	deleteFirst(list,hapus);
	traversal(list);
	break;

	case 4:
	deleteLast(list,hapus);
	traversal(list);
	break;
	default:
		cout<<"Exit\n";
		exit(0);
		break;
	}
}
}

