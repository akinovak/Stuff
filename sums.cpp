#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public :
    void swap(vector<int> &niz, int a, int b)
    {
        int pom = niz[a];
        niz[a] = niz[b];
        niz[b] = pom;
    }

public :
    void quicksort(vector<int> &niz, int l, int d)
{
    if(l >= d)
        return;
    cout << "Ovde";
    int pivot = niz[l];
    
    int s = l;
    
    for(int i = l+1; i <= d; i++)
    {
        if(niz[i] <= pivot)
        {
            s++;
            swap(niz, niz[i], niz[s]);
        }
    }
    
    swap(niz, niz[l], niz[s]);
    
    quicksort(niz, l, s-1);
    quicksort(niz, s+1, d);
}
    
public :
    
    int bSearch(vector<int> niz, int l, int d, int target) {
        
        if(l > d)
            return -1;
        
        int s = (d - l)/2;
        
        if(niz[s] == target) {
            return s;
        }
        else if(niz[s] < target) {
            bSearch(niz, s+1, d, target);
        }
        else {
            bSearch(niz, l, s-1, target);
        }
        
    }

    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        quicksort(nums, 0, nums.size());
        int found = 0;
        cout << "Ovde";
        for(int i=0;i<nums.size();i++) {
            cout << "Ovde";
            int potentialSolution = bSearch(nums, i, nums.size(), target - nums[i]);
            if(potentialSolution != -1) {
                
                vector<int> solution;
                solution.push_back(i);
                solution.push_back(potentialSolution);
                cout << "Ovde";
                return solution; 
            }
        }
        
        
    }
};


int main() {
    
    vector<int> niz;
    int n;
    int target;
    cin >> target;
    cin >> n;

    for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            niz.push_back(tmp);
        }

    vector<int> resenje = Solution().twoSum(niz, target);

    for(int i=0;i<resenje.size();i++)
        cout << resenje[i] + " ";
    cout << "/n";

    return 0;
}