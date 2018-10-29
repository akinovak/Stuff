#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

struct state {

    int Mouse, Cat, turn;
    state(int M, int C, int t) {
        Mouse = M;
        Cat = C;
        turn = turn;
    }
};

struct node {

    int Mouse, Cat;
    bool turn;
    vector<node*> children;
    int value = -1;

    node(int M, int C, bool OldTurn) {
        Mouse = M;
        Cat = C;
        turn = !OldTurn; //mouse=true, cat=false
    }

    int tryWithZero() {

        for(auto it=children.begin();it!=children.end();it++) {
            if((*it)->value == 0)
                return 0;
        }
        return -1;
    }
    int tryWithOne() {
        for(auto it=children.begin();it!=children.end();it++) {
            if((*it)->value == 1)
                return 1;
        }
        return -1;
    }
    int tryWithTwo() {
        for(auto it=children.begin();it!=children.end();it++) {
            if((*it)->value == 2)
                return 2;
        }
        return -1;
    }

    void MouseTry() {
        int res;
        res = tryWithOne();
        if(res == 1) {
            value = 1;
            return;
        }
        res = tryWithZero();
        if(res == 0)
        {
            value = 0;
            return;
        }
        value = 2;
        return;
    }
    void CatTry() {
        int res;
        res = tryWithTwo();
        if(res == 2) {
            value = 2;
            return;
        }
        res = tryWithZero();
        if(res == 0)
        {
            value = 0;
            return;
        }
        value = 1;
        return;
    }

};



struct graph {

    vector<vector<int> > lista;
    unordered_set<state*> states;

    void playGame(node *root) {

        int mousePos = root->Mouse;
        int catPos = root->Cat;

        if(mousePos == catPos)
            return;
        if(mousePos == 0)
            return;
        state *s = new state(root->Mouse, root->Cat, root->turn);
        auto it = states.find(s);
        if(it == states.end()) {
            states.insert(s);
        }
        else {
            return;
        }

        if(root->turn) {
            for(auto it=lista[mousePos].begin();it!=lista[mousePos].end();it++) {
                
                root->children.push_back(new node(*it, catPos, root->turn));
            }
        }
        else {
            for(auto it=lista[catPos].begin();it!=lista[catPos].end();it++) {

                if(*it != 0)
                    root->children.push_back(new node(mousePos, *it, root->turn));
            }
        }


    }

    void evaluate(node *root) {

        if(root->Mouse == 0) {
            root->value = 1;
        }
        if(root->Mouse == root->Cat) {
            cout << root->Cat << endl;
            root->value = 2;
        }
        
        state *s = new state(root->Mouse, root->Cat, root->turn);
        auto it = states.find(s);
        if(it == states.end()) {
            root->value = 0;
            //cout << root->Cat << endl;
            return;
        }

        for(auto it=root->children.begin();it!=root->children.end();it++) {
            if((*it)->value == -1) {
                evaluate(*it);
            }
        }

        if(root->turn) {
            root->MouseTry();
        }
        else {
            root->CatTry();
        }
    }

    void inicijalizuj(vector<vector<int> > input) {
        
        for(auto it=lista.begin();it!=lista.end();it++)
            it->clear();
        lista.clear();

        lista.resize(input.size());

        for(int i=0;i<lista.size();i++) {

            for(int j=0;j<input[i].size();j++) {

                lista[i].push_back(input[i][j]);
            }

        }

    }



};

int main(int argc, char const *argv[])
{
    graph g;
    
    vector< vector<int> > 
    a{ { 2,5 },{ 3 },{ 0, 4, 5 },{ 1, 4 }, {2, 3}, {0, 3}};
    g.inicijalizuj(a);

    node *n = new node(1, 2, 0);

    g.playGame(n);
    g.evaluate(n);

    cout << n->value << endl;
    
    return 0;
}
