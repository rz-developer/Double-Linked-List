#include <iostream>



using namespace std;

struct node{
    int info;
    node* next;
    node* prev;

    node(int value, node* n = 0, node* p = 0)
    : info(value), next(n), prev(p){};
};

node* first = NULL;
node* last = NULL;

node* inserfirst(int value){
    node* n = new node(value);
    if (first != NULL && last != NULL){
        n->next = first;
        first->prev = n;
        first = n;
        return n;
    } else {
        first = n;
        last = n;
        return n;
    }
}

node* inserlast(int value){
    node* n = new node(value);
    if (first != NULL && last != NULL){
        n->prev = last;
        last->next = n;
        last = n;
        return n;
    } else {
        first = n;
        last = n;
        return n;
    }
}

node* inserbefore(int value , node* pos){
    node* n = new node(value);
    n->next = pos;
    pos->prev->next = n;
    pos->prev = n;
    return n;
}

node* inserafter(int value, node* pos){
    node* n = new node(value);
    n->next = pos->next;
    pos->next->prev = n;
    pos->next = n;
    return n;
}

void deletefirst(){
    if (first != NULL && last != NULL){
        node* temp = first;
        first = temp->next;
        temp->next = NULL;
        first->prev = NULL;
        delete temp;
    } else {
        first = NULL;
        last = NULL;
    }
}

void deletelast(){
    if (first != NULL && last != NULL){
        node* temp = last;
        last = last->prev;
        temp->prev = NULL;
        last->next = NULL;
        delete temp; 
    }else {
        first = NULL;
        last = NULL;
    }
}

void deleteafter(node* pos){
    node* temp = pos->next;
    pos->next = temp->next;
    temp->next->prev = pos;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}

int search(int key){
    node* p = first;
    int i = 1;
    while (p->info != key){
        p = p->next;
        i++;
    }
    return i;
}

void print(node* pos){
    while(pos != NULL){
        cout << pos->info << " ";
        pos = pos->next;
    } cout << endl;
}

int main(){
	cout<<"Data Awal (6)\n";
	inserfirst(6);
	print(first);
	
	cout<<"insert first (9)\n";
    inserfirst(9);
    print(first);
    
    cout<<"insert Last (2)\n";
    inserlast(2);
    print(first);
    
    cout<<"insert Before (5)\n";
    inserbefore(5, first->next);
    print(first);
    
    cout<<"insert After (1)\n";
    inserafter(1, first->next->next);
    print(first);
    
    cout <<"Delete First\n";
    deletefirst();
    print(first);
    
    cout<<"Delete Last\n";
    deletelast();
    print(first);
    
    cout<<"Delete After\n";
    deleteafter(first);
    print(first);
    
    int cari;
    cout << "Elemen yang ingin dicari : ";
    cin >> cari;
    cout << "elemen "<< cari <<" ada di urutan ke-" << search(cari);

    return 0;
}
