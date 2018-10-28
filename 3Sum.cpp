#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<int> > sum3(vector<int> niz) {

     unordered_map<int, unordered_set<int> > mapa;
     vector< vector<int> > matrica;
     int br = 0;

     for(int i=0;i<niz.size();i++) {

         auto it=mapa.find(niz[i]);
         if(it == mapa.end()) {
             mapa.emplace(niz[i], unordered_set <int>({i}));
         }
        else {
            it->second.emplace(i);
        }
     }

    for(int i=0;i<niz.size();i++) {

        int first = niz[i];

        for(int j=i+1;j<niz.size();j++) {

            int second = niz[j];

            //cout << 0-first-second << endl;

            auto it = mapa.find(0 - first - second);
            if(it != mapa.end()) {
                
                //TODO
                // AKO SVI ISTI PROVERI JE L IMA TACNO 3

                if(it->first == first || it->first == second) {

                    if(it->second.size() > 1) {

                        // int third = it->first;
                        // matrica[br].push_back(first);
                        // matrica[br].push_back(second);
                        // matrica[br++].push_back(third);
                        

                    }

                }
                else {

                    matrica.push_back(vector<int>());
                     matrica[br].push_back(first);
                    matrica[br].push_back(second);
                    matrica[br++].push_back(it->first);
                    

                    //CUVAJ INDEXE RESENJA
                }
            }

        }

        break;

    }

     return matrica;
}

int main() {

    vector<int> nums;
    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        int e;
        cin >> e;
        nums.push_back(e);
    }


     vector< vector<int>> matrica = sum3(nums);

    for(int i=0;i<matrica.size();i++) {

        for(int j=0;j<matrica[i].size();j++) {

            cout << matrica[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}