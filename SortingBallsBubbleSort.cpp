#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define ui unsigned ll
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0)
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define f first
#define INF pow(10,14)+7
void sortingballs(ll num,vector<ll>&arr){ // insert ball number in array and then use bubble sort. then print the values
    arr.push_back(num);
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<"\n";
}
int main() {
      // #ifndef ONLINE_JUDGE
      // freopen("input", "r", stdin);
      // freopen("output", "w", stdout);
      // freopen("error", "w", stderr);
      //  #endif
        IOS;
        vector<ll>arr;
        bool condition = true;
        while(condition){
        ll num;
        cin>>num;
        if(num == -1){
            condition = false;
            break;
        }
        if(num<0 || num>59){
            cout<<"Number should be between 0 and 59!\n";
            continue;
        }
        sortingballs(num,arr);          // time: O(60)
                                            // memory: O(60)
        }
}