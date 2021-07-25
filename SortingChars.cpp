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
// make heap in vector
void sortchars(string s){               //sorting all characters after ignoring whitespaces
    if(s.size()==0) return;
    ll n = s.size();
    int count[26];
    memset(count,0,sizeof(count));

    for(int i=0;i<n;i++){                                                  // converting all upper to lower, 
                                                                            //ignore punctuation, and maintain count
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]=(char)(s[i]+32);
            }
            count[s[i]-'a']++;
        }
    }

    for(int i=0;i<26;i++){                                                  // print the sorted sequence.
        while(count[i]--){
            cout<<(char)('a'+i);
        }                                                   // Time Complexity: O(N)
                                                            // Memory: O(26)
    }
}
int main() {
      // #ifndef ONLINE_JUDGE
      // freopen("input", "r", stdin);
      // freopen("output", "w", stdout);
      // freopen("error", "w", stderr);
      //  #endif
        IOS;
        string s;
        cin>>s;                     // take string as input.
        sortchars(s);
}