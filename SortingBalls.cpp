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
void sortingballs(ll num,vector<ll>&count){ // instead of sorting, maintain count and just print in order
    count[num]++;
    for(int i=0;i<60;i++){
        if(count[i]>0)
            cout<<i<<" ";
    }
    cout<<"\n";
}
int main() {
      // #ifndef ONLINE_JUDGE
      // freopen("input", "r", stdin);
      // freopen("output", "w", stdout);
      // freopen("error", "w", stderr);
      //  #endif
        IOS;
        vector<ll>count(60,0);
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
        if(count[num]>0) {
            cout<<"Number already picked!\n";
            continue;
        }
        sortingballs(num,count);            // time: O(60)
                                            // memory: O(60)
        }
}