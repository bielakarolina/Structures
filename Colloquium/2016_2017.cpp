//
// Created by Karolina on 03.05.2018.
//

#include <iostream>
using namespace std;


//2.Dana jest struktura HT, która opisuje tablicę haszującą rozmiaru size, przechowywującą liczby nieujemne:
//
//struct HT {
//    int* table;
//    int size;
//};
//Tablica korzysta z funkcji haszującej int hash(int x) i liniowego rozwiązywania konfliktów (ujemne wartości w tablicy table 
//oznaczają wolne pola).
//
//Doskonałością takiej tablicy nazywamy liczbę elementów x takich, że pozycja x w tablicy to hash(x) % size 
  //(a więc x jest na "swojej" pozycji).
//
//Proszę napisać funkcję void enlarge(HT* ht), która powiększa tablicę dwukrotnie i wpisuje elementy w takiej kolejności, 
//by doskonałość powstałej
//        tablicy była największa. Funkcja powinna być możliwie najszybsza.
struct HT {
    int* table;
    int size;
};

int getHash(int val,int size){
    return val%size;
}
//nie działa i nie wiem jak to zrobić
void insertnew(HT *ht, int key, int oldindeks, bool dosko[]){
    int l=getHash(key,ht->size);
    if(ht->table[l]==-1) {
        ht->table[l]=key;
        cout<<"Dodano "<<key<<endl;
        ht->table[oldindeks]=-1;
        dosko[l]=true;
    }
    else if(!dosko[l]){

        cout<<"Doskonałość zaburzona"<<endl;
        cout<<l<<" "<<ht->size<<" "<<oldindeks<<endl;

        //przeniosimy na koniec tam gdzie jest miejsce
        swap(ht->table[l],ht->table[oldindeks]);
        dosko[oldindeks]=true;
    }
}

void insert(HT *ht, int key,int ind){
    int l=ind;
    if(ht->table[l]==-1) {
        ht->table[l]=key;
        cout<<"Dodano "<<key<<endl;
    }

}
void enlarge(HT* ht){
    int newsize=2*ht->size;
    ht->size=newsize;
    bool dosko[ht->size];
    for(int i=0;i<ht->size;i++) {
        dosko[i]=false;
    }
    for(int i=ht->size/2;i<ht->size;i++)
        ht->table[i] = -1;
    for(int j=0;j<ht->size;j++)
        for(int i=0;i<ht->size;i++){
        insertnew(ht,ht->table[i],i,dosko);
    }
}



int main() {
    //tworzenie HashTable
    HT *ht = new HT;
    ht->size = 5;
    ht->table = new int [ht->size];


    //ustawianie wszystkich pól na NULL
    for (int i = 0; i < ht->size; i++) {
        ht->table[i] = -1;
    }
    insert(ht,5,0);
    insert(ht,3,1);
    insert(ht,1,2);
    insert(ht,1,3);
    insert(ht,2,4);
    for (int i = 0; i < ht->size; i++) {
        cout<<ht->table[i]<<endl;
    }
    enlarge(ht);
    for (int i = 0; i < ht->size; i++) {
        cout<<ht->table[i]<<" ";
    }
}


//3. Dany jest ciag klocków (k1, ..., kn). Klocek ki zaczyna sie na pozycji ai i ciagnie sie do pozycji bi
//        (wszystkie pozycje to liczby naturalne) oraz ma wysokosc 1. Klocki układane sa po kolei. Jesli
//        klocek nachodzi na którys z poprzednich, to jest przymocowywany na szczycie poprzedzajacego
//klocka. Na przykład dla klocków o pozycjach (1,3), (2,5), (0,3), (8,9), (4,6) powstaje konstrukcja
//o wysokosci trzech klocków (vide rysunek). Prosze podac mozliwie jak najszybszy algorytm,
//        który oblicza wysokosc powstałej konstrukcji (bez implementacji) oraz oszacowac jego złozonosc
//obliczeniowa.
//0 1 2 3 4 5 6 7 8 9 10 x
//        k1
//k2
//        k3
//k4
//        k5
//Rysunek 1: Przykład konstrukcji.
