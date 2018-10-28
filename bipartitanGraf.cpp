#include <iostream>
#include <vector>

using namespace std;

struct graf {

    vector<vector<int> > lista;
    vector<int> identfikatori;

    bool isBibartite(int root, int tmpIdentifikator) {

        identfikatori[root] = tmpIdentifikator;

        for(int i=0;i<lista[root].size();i++) {

            if(identfikatori[lista[root][i]] == tmpIdentifikator)
                return false;
            else if(identfikatori[lista[root][i]] == 2) {
                identfikatori[lista[root][i]]= !tmpIdentifikator;
                return isBibartite(lista[root][i], !tmpIdentifikator);
            }
            else if(identfikatori[lista[root][i]] == !tmpIdentifikator)
            {

            }
            
        }

        return true;

    }

    void inicijalizacija(int n) {

       ocisti(n); 

       for(int i=0;i<n;i++) {

           identfikatori[i]=2;  
           cout << "Unesi broj suseda" <<endl;
           int m;
           cin >> m;
           for(int j=0;j<m;j++) {

               int sused;
               cin >> sused;
               lista[i].push_back(sused);
               lista[sused].push_back(i);
           }
       }
    }



    void ocisti(int n) {

        identfikatori.clear();
        identfikatori.resize(n);
        for(int i=0;i<lista.size();i++)
            lista[i].clear();
        lista.clear();
        lista.resize(n);

    }


};


int main() {

    int n;
    cin >> n;
    graf g;
    g.inicijalizacija(n);

    cout << g.isBibartite(0, 0);

    return 0;
}