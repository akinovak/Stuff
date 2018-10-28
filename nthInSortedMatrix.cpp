#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthElem(vector< vector<int> > &matrica, int k) {

    priority_queue<int, vector<int>, greater<int> > hip;

    for(int i=0;i<matrica.size();i++) {
        for(int j=0;j<matrica.size();j++) {

            hip.push(matrica[i][j]);
        }
    }

    for(int i=0;i<k-1;i++) {
        if(!hip.empty())
            hip.pop();
        else 
            break;
    }

    if(!hip.empty())
        return hip.top();

}

int main(int argc, char const *argv[])
{
    vector< vector<int> > matrica;
    int n;
    cin >> n;
    matrica.resize(n);

    for(int i=0;i<n;i++) {
        
        for(int j=0;j<n;j++) {
            int tmp;
            cin >> tmp;
            matrica[i].push_back(tmp);
        }
    }

    int k;
    cin >> k;
    cout << kthElem(matrica, k);

    return 0;
}
