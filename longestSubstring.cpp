#include <iostream>
#include <string>
#include <vector>

using namespace std;

int length(string s) {

    vector<int> lastOcc;
    lastOcc.resize(30);

    for(int i=0;i<30;i++)
        lastOcc[i] = -1;
    
    int globalMax = 0, tmpMax = 0;

    for(int i=0;i<s.length();i++) {

        char tmp = s[i];
        cout << tmp << endl;

        if(lastOcc[tmp-'a'] != -1) {

            tmpMax = 0;
            int pom = i;
            i = lastOcc[tmp-'a'];
            
            for(int i=0;i<30;i++)
                lastOcc[i] = -1;
        }
        else {

            
            lastOcc[tmp-'a'] = i;
            tmpMax++;
            if(globalMax < tmpMax)
                globalMax = tmpMax;
        }

        for(int i=0;i<30;i++)
            cout << lastOcc[i] << " ";
        cout << endl;
     }

    return globalMax;

}

int main() {

    string s;
    cin >> s;

    int resenje = length(s);

    cout << resenje << "\n";

    return 0;
}