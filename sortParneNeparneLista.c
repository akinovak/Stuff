#include <stdio.h>
#include <stdlib.h>

typedef struct Cvor {

    int val;
    struct Cvor *next;

}Cvor;

Cvor *push(Cvor **glava, int n) {

    Cvor *novi = (Cvor*)malloc(sizeof(Cvor));
    novi->val = n;
    novi->next = NULL;

    if(*glava == NULL) {
        return novi;
    }
    
    Cvor *tmp = *glava;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = novi;
    return *glava;

}

Cvor* add(Cvor **glava, int k) {

     Cvor *pom = *glava;
     while(pom->next->val != k) 
         pom = pom->next;
    
    printf("EeEEE %d\n", pom->next->next->val);
    Cvor *brisi = pom->next;
    pom->next = pom->next->next;
    free(brisi);

    Cvor *novi = (Cvor*)malloc(sizeof(Cvor));
    novi->val = k;
    novi->next = NULL;

    if(k%2) {

    }
    else {

        Cvor *tmp = *glava;

        if(novi->val < tmp->val) {

            novi->next = *glava;
            return novi;
        }

        while(novi->val > tmp->next->val) {
            tmp = tmp->next;

        }

        novi->next = tmp->next;
        tmp->next = novi;
        return *glava;

    }

}

int main() {

    Cvor *l1 = NULL;

    l1 = push(&l1, 6);
    l1 = push(&l1, 4);
    l1 = push(&l1, 8);
    l1 = push(&l1, 12);
    l1 = push(&l1, 10);


    Cvor *pom = l1;
    while(pom != NULL) {
        printf("%d ", pom->val);
        pom = pom->next;
    }

    Cvor *tmp = l1->next;

    while(tmp != NULL) {

        l1 = add(&l1, tmp->val);
        tmp = tmp->next;
    }

    while(l1 != NULL) {
        printf("%d ", l1->val);
        l1 = l1->next;
    }

    return 0;
}