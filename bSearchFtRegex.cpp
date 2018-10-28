#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

using namespace std;

struct struktura {
    
    vector<string> reci;
    int n;

    void priprema() {
        reci.clear();
    }

    int reciSize() {
        return reci.size();
    }

    void addRec(string rec) {

        if(reci.empty()) {
            reci.push_back(rec);
            return;
        }
        
        auto it = reci.begin();

        while(it !=reci.end() && *it < rec) {
            it++;
        }

        reci.insert(it, rec);
    }

    pair<int,int> findWords(int l, int d, char slovo, 
    int tmpPozicija) {

        if(l > d)
            return make_pair(-1, -1);

        int sredina = l + (d-l)/2;

        cout << "Reci : " << reci[sredina][tmpPozicija] << " " <<  slovo << endl;
        int brLevi;
        if(reci[sredina][tmpPozicija] == slovo) {
            int start, end;
            for(brLevi=sredina;brLevi>=l;brLevi--) {
                if(reci[brLevi][tmpPozicija] != slovo)
                {
                    start = brLevi+1;
                    break;
                }
            }
            if(brLevi == l-1) {
                start = l;
            }
            int brDesni;
            for(brDesni=sredina;brDesni<=d;brDesni++) {
                if(reci[brDesni][tmpPozicija] != slovo)
                {
                    end = brDesni-1;
                    break;
                }
            }

            if(brDesni == d+1)
                end = d;

            return make_pair(start, end);
        }

        if(reci[sredina][tmpPozicija] > slovo) {
            return findWords(l, sredina-1, slovo, tmpPozicija);
        }

        if(reci[sredina][tmpPozicija] < slovo) {
            return findWords(sredina+1, d, slovo, tmpPozicija);
        }

    }

    bool findWord(string rec) {

        int L = 0, D = reciSize() -1;

        for(int i=0;i<rec.length();i++) {

            if(rec[i] == '.')
                continue;
            
            pair<int, int> res = findWords(L, D, rec[i], i);
            
            L = res.first;
            D = res.second;
            cout << L << " " << D << endl;
            if(L == -1 || D==-1)
                return false;

        }

        return true;

    }

    void ispis() {

        for(auto it=reci.begin();it!=reci.end();it++) {
            cout << (*it) << endl;
        }
        cout << endl;
    }

};

int main() {

    struktura s;

    s.priprema();
    s.addRec("aaa");
    s.addRec("aab");
    s.addRec("abb");
    s.addRec("ccc");
    s.addRec("bbb");
    //s.ispis();
    
    cout << s.findWord("b.k");
    return 0;

}