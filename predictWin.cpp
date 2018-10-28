#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

struct node {

    list<int> array;
    int A, B, sum;
    node *levi = nullptr;
    node *desni = nullptr;
    bool turn; //a=1,b=0

    node(list<int> Carray,int oldA,int oldB, int oldSum,bool oldTurn) {

        for(auto it=Carray.begin();it!=Carray.end();it++)
            array.push_back(*it);
        A = oldA;
        B = oldB;
        turn = !oldTurn;
        sum = oldSum;
    }

};

void ispis(node *root) {
        cout << "Niz :" << endl;
        for(auto it=root->array.begin();it!=root->array.end();it++) {
            cout << *it << " ";
        }
        cout << endl << "A: " << root->A << " B: " << root->B << " Sum: " << root->sum << endl;
}

void constructTree(node *root) {

        //ispis(root);
        if((root->array).empty())
            return;
        
        list<int> sendArray;
        sendArray.assign(root->array.begin(), root->array.end());
        int tmpValue = root->array.front();
        if(root->turn) {
            root->A += tmpValue;
        }
        else {
            root->B += tmpValue;
        }

        sendArray.pop_front();        
        root->levi = new node(sendArray, root->A, root->B, root->sum-tmpValue, root->turn);
        //cout << "Cao od levog" << endl;
        //ispis(root->levi);
        constructTree(root->levi);

        if(!sendArray.empty()) {

            tmpValue = sendArray.back();
            if(root->turn) {
                root->A += tmpValue;
            }
            else {
                root->B += tmpValue;
            }

            sendArray.pop_back();
            root->desni = new node(sendArray, root->A, root->B, root->sum-tmpValue, root->turn);
            //cout << "Cao od desnog" << endl;
            //ispis(root->desni);
            constructTree(root->desni);

        }
}



int compute(node *root) {

    if(root->array.empty())
        return root->A - root->B;

    if(root->levi && root->desni) {
        if(root->turn) {
            return max(compute(root->levi), compute(root->desni));
        }
        else {
            return min(compute(root->levi), compute(root->desni));
        }
    }

    if(root->levi && root->desni==nullptr) {
        return compute(root->levi);
    }
    if(root->levi==nullptr && root->desni) {
        return compute(root->desni);
    }
}

int main() {

    list<int> array = {47, 16, 23, 31, 42};
    node *n = new node(array, 0, 0, 247, 0);
    constructTree(n);
    int res = compute(n);

    if(res > 0)
        cout << "1";
    else 
        cout << "0";

    return 0;
}