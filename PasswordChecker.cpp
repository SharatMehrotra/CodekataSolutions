#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long
#define ui unsigned ll
#define us unsigned short
ll user;
ll admin;
ll minletter;
ll mindigit;
ll minspecial;
bool isletter(char c){                                              // to check if it's an upper or lower case letter
    if(c>='a' && c<='z' || c>='A' && c<='Z') return true;
    return false;
}
bool isnum(char c){                                                 // to check if it's a number
    if(c>='0' && c<='9') return true;
    return false;
}
bool checksize(string &s,ll limit){                                 // to check if size of string is more than the reqd. limit
    if(s.size() < limit) return false;
    return true;
}
bool iteration1(string &s){                                          // check to satisfy all conditions for a user's password
    if(!checksize(s,user)) return false;
    ll letter=0;
    ll digit=0;
    for(ll i=0;i<s.size();i++){
        if(isletter(s[i])) letter++;
        if(isnum(s[i])) digit++;
    }
    if(digit < mindigit || letter < minletter) return false;
    return true;
}
bool iteration2(string s){                                          // check to verify is password satisfies the criteria for admin.
    if(!checksize(s,admin)) return false;
    ll special=0;
    for(ll i=0;i<s.size();i++){
        if(!isletter(s[i]) && !isnum(s[i])) special++;
    }
    if(special < minspecial) return false;
    return true;
}
bool feedback(string &s,bool feedback1,bool feedback2, char answer){        // feedback for password according to its type (user or admin)
    if(!feedback1){
        if(checksize(s,user)){
            cout<<"password should have at least "<<minletter<<" letter(s) and "<<mindigit<<" number(s)\n";
            return false;
        }
        if(answer == 'N')
            cout<<"password should be more than"<<" "<<user<<" character(s)\n";
        else 
            cout<<"password should be more than"<<" "<<admin<<" character(s)\n";
        return false;
    }
    if(!feedback2){
        if(checksize(s,admin)){
            cout<<"password should have at least "<<minspecial<< " special character(s)\n";  
            return false;
        }
        if(answer == 'N')
            cout<<"password should be more than"<<" "<<user<<" character(s)\n";
        else 
            cout<<"password should be more than"<<" "<<admin<<" character(s)\n";
        return false;        
    }
    return true;
}
int main() {
      // #ifndef ONLINE_JUDGE
      // freopen("input", "r", stdin);
      // freopen("output", "w", stdout);
      // freopen("error", "w", stderr);
      //  #endif
        IOS;
        string s;
        cout<<"Enter password:\n";
        cin>>s;
        /*
        set the limits manually for string size, min number of letters,digits,special characters.
        then check if its an admin password.
        give feedback accordingly.
        print perfect it satisfies all criteria.
        */
        user=7;
        admin=10;
        mindigit=1;
        minletter=1;
        minspecial=1;
        bool f1 = iteration1(s);
        bool f2 = true;
        cout<<"Are you an admin (Y/N)?\n";  // check if it's an admin password
        char answer;
        cin>>answer;
        if(answer == 'Y')
            f2 = iteration2(s);
        if(feedback(s,f1,f2,answer)){
            cout<<"Perfect!"<<"\n";
        }
}