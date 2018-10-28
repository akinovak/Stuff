#include <iostream>
#include <vector>
#include <utility> 
#include <iomanip>
#include <ctime>
#include <chrono>
#include <algorithm> 
#include <math.h>
#include <queue>
#include <unistd.h>

using namespace std;

// struct poredi {
//     bool operator()(int p1, int p2)
//     {
//         return p1 < p2;
//     }
// };

struct poredi {
    bool operator()(pair<string, time_t> &p1, pair<string, time_t> &p2)
    {
        if(p1.second < p2.second)
            return true;
        else
            return false;
    }
};

class User {

    private : 
            int id;
            string uname;
            
            vector< pair<string, time_t> > tweets;
    public : 
        vector<User*> following;

    public : User(string unamaex) {
        uname = unamaex;
        id = rand(); 
    }

    public : ~User() {
        following.clear();
        tweets.clear();
    }

    public : vector< pair<string, time_t> > getTweets() {

        return tweets;
    }


    public : void followUser(User *u) {

        following.push_back(u);
    }

    public : void postTweet(string s) {

        tweets.push_back(make_pair(s, time(NULL)));
    }

    // public : void unfollow(User *u) {

    //     following = std::remove(following.begin, following.end, u);
    // }

    public : void seeFeed() {

        priority_queue<pair<string, time_t>, 
        vector< pair<string, time_t> >, poredi> hip;
     //  priority_queue<int, vector<int>, poredi> hip;

        for(auto it = following.begin();
                it != following.end();it++) {

            vector< pair<string, time_t> > tmp = (*it)->getTweets();
            
            for(auto it2 = tmp.begin();it2!=tmp.end();it2++) {
                hip.push(*it2);
                // cout << "Odje sam" << endl;
            }
        }

        for(int i=0;i<5;i++) {

            auto top = hip.top();
            hip.pop();
            cout << top.first << " " << top.second << endl;
        }
        
        while(!hip.empty())
            hip.pop();

    }

    public : string printUser() {
        return uname + " " + to_string(id);
    }
    
};

string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    string pom;
    pom.resize(len);

    for (int i = 0; i < len; ++i) {
        pom[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return pom;
}

int main() {

    vector<User*> useri;

    int brUsera = 5;
    for(int i=0;i<5;i++) {
        string s;
        cin >> s;
        User *tmp = new User(s);
        useri.push_back(tmp);
    }

    int br = 0;

    for(int i=0;i<5;i++) {
        
        for(int j=0;j<5;j++) {
            string tweet = gen_random(10);
            tweet += to_string(br++);
            useri[i]->postTweet(tweet);
            sleep(3);
        }
    }

    useri[0]->followUser(useri[1]);
    useri[0]->followUser(useri[2]);
    useri[0]->followUser(useri[3]);
    useri[0]->followUser(useri[4]);


     useri[0]->seeFeed();

    return 0;
}