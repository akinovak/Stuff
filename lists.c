#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
     int val;
     struct ListNode *next;
}Cvor;

Cvor* add(Cvor **l, int n) {

    Cvor *novi = (Cvor *) malloc(sizeof(Cvor));
    if (novi == NULL)
        return NULL;

    novi->val = n;
    novi->next = NULL;

    novi->next = *l;
    return novi;
}

Cvor* push(Cvor **l, int n) {

    Cvor *novi = (Cvor *) malloc(sizeof(Cvor));
    novi->val = n;
    novi->next = NULL;
    Cvor *tmp = *l;

    if(*l == NULL) {
        return novi;
    }
    else {
        while(tmp->next != NULL) {
        tmp = tmp->next;
        }

        tmp->next = novi;
        return *l;
    }

}

Cvor* addLists(Cvor *l1, Cvor *l2) {

    Cvor *result = NULL;
    //Cvor *resultStart = result;
    int carry = 0;

    while(l1 != NULL && l2 != NULL) {

        int sum = l1->val + l2->val;
        if(sum > 10) {


        }
        else {

            result = push(&result, sum);
            l1 = l1->next;
            l2 = l2->next;
        }
    }


    return result;
}

int main() {

    Cvor *l1 = NULL;
    //l1 = add(&l1, 1);
    l1 = add(&l1, 2);
    l1 = add(&l1, 3);
    l1 = push(&l1, 1);

    Cvor *l2 = NULL;
    l2 = add(&l2, 1);
    l2 = add(&l2, 1);
    l2 = add(&l2, 1);

    Cvor *l3 = addLists(l1, l2);

    while(l3 != NULL) {

        printf("%d ", l3->val);
        l3 = l3->next;
    }

    

    // while(l1 != NULL) {
    //     printf("%d ", l1->val);
    //     l1 = l1->next;
    // }

    return 0;
}