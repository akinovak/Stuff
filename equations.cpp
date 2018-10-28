#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

struct graf {

    vector<vector <pair<int, double> > > lista;
    vector<bool> obidjeni;

    vector<double> izracunaj(vector<pair<int, int>> queries) {

        vector<double> resenje;
        for(auto it=queries.begin();it!=queries.end();it++) {

            if((*it).first < 0 || (*it).first>= lista.size() || 
             (*it).second < 0 || 
             (*it).second>= lista.size()) {
                 resenje.push_back(-1.0);
             }
             else {
            
                for(int i=0;i<obidjeni.size();i++)
                    obidjeni[i] = false;
                resenje.push_back(naciPut((*it).first, (*it).second, 1.0));

             }


        }

        return resenje;

    }

    double naciPut(int start, int end, double tmpPut) {

        obidjeni[start] = true;
        if(start == end) {
            return tmpPut;
        }

        for(auto it=(lista[start]).begin();it!=lista[start].end();it++) {

            if(!obidjeni[(*it).first]) {
                return naciPut((*it).first, end, tmpPut*(*it).second);
            }

        }
    }

    void inicijalizacija(int n) {

        ocisti(n);
        for(int i=0;i<n;i++) {

            obidjeni[i] = false;
            int brSuseda;
            cin >> brSuseda;

            for(int j=0;j<brSuseda;j++) {

                int sused;
                double grana;
                cin >> sused;
                cin >> grana;
                lista[i].push_back(make_pair(sused, grana));
                lista[sused].push_back(make_pair(i, 1/grana));
            }

        }   
    }

    void ocisti(int n) {

        lista.resize(n);
        obidjeni.resize(n);
    }


};

int main(int argc, char const *argv[])
{
    
    graf g;

    vector<pair<int, int> > queries;
    cout << "Unesi broj kverija" << endl;
    int brKverija;
    cin >> brKverija;

    for(int i=0;i<brKverija;i++) {

        int a, b;
        cin >> a >> b;
        queries.push_back(make_pair(a, b));

    }

    int n;
    cin >> n;

    g.inicijalizacija(n);

     vector<double> resenje = g.izracunaj(queries);

    //cout << g.naciPut(0, 2, 1) << endl;

    for(int i=0;i<resenje.size();i++) {
        cout << resenje[i] << " ";
    }
    cout << endl;

    return 0;
}