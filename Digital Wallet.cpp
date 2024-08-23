#include <cmath>
#include <cstdio>
#include <vector>
#include<map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    map<int,int>balance;
    while(n--)
    {
       int id1;
        int bal;
        cin>>id1>>bal;
        balance[id1]=bal;
    }
    int t;
    cin>>t;
    while(t--)
    {
    int from_uid;
    int to_uid;
    int transferamount;
        cin>>from_uid>>to_uid>>transferamount;
        if(transferamount>balance[from_uid])
        {
            cout<<"Failure"<<endl;
        }
        else{
            balance[from_uid]-=transferamount;
            balance[to_uid]+=transferamount;
            cout<<"Success"<<endl;
        }
    }
   vector<pair<int, int>> sortedbalance;
    for (const auto& entry : balance) {
        sortedbalance.push_back(entry);
    }
    sort(sortedbalance.begin(), sortedbalance.end(), [](const pair<int, int>& p, const pair<int, int>& q) 
         {
        if (p.second == q.second) 
            return p.first<q.first;
        return p.second<q.second;
    });
    cout<<endl;
    for (const auto& entry :sortedbalance) 
    {
        cout<<entry.first<<" "<< entry.second<<endl;
    }
    return 0;
}