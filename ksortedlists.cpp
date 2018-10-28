#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}Cvor;

Cvor* pushBack(Cvor **glava, int k) {

    Cvor *novi = new ListNode(k);
    if(*glava == NULL) {
        novi->next = *glava;
        return novi;
    }

    Cvor *tmp = *glava;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = novi;
    return *glava;
}

void ispisiListu(Cvor *glava) {

    Cvor *tmp = glava;

    while(glava != NULL) {
        cout << glava->val << " ";
        glava = glava->next;
    }
    cout << endl;
} 


Cvor* mergeLists(vector<Cvor*> &liste) {

    Cvor *mergedList = NULL;
    priority_queue<int, vector<int>, greater<int> > hip;

    for(int i=0;i<liste.size();i++) {

        Cvor *tmpLista = liste[i];

        while(tmpLista != NULL) {
            hip.push(tmpLista->val);
            tmpLista = tmpLista->next;
        }

    }

    while(!hip.empty()) {

        int top = hip.top();
        cout << top << endl;
        hip.pop();

        mergedList = pushBack(&mergedList, top);
    }

    return mergedList;
}


int main() {

    vector<Cvor*> liste;
    int n;
    cin >> n;
    liste.resize(n);

    for(int i=0;i<n;i++) {
        int m, tmp;
        cin >> m;
        for(int j=0;j<m;j++) {
            cin >> tmp;
            liste[i] = pushBack(&liste[i], tmp);
        }
    }

    // for(int i=0;i<n;i++) {

    //     ispisiListu(liste[i]);
    // }

    Cvor *lista = mergeLists(liste);

    ispisiListu(lista);

    return 0;
}