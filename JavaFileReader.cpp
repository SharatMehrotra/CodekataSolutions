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
string removespaces(string s){ // function to remove all kinds of whitespace.
    string ans;
    int i=0;
    while(i<s.size() && s[i]==' ' || s[i]=='\t') i++;
    for(int i=0;i<s.size();i++){
        if(s[i] != ' ' && s[i] !='\t') ans.push_back(s[i]);
    }
    return ans;
}
int main() {
      // #ifndef ONLINE_JUDGE
      // freopen("input", "r", stdin);
      // freopen("output", "w", stdout);
      // freopen("error", "w", stderr);
      //  #endif
    IOS;
    fstream newfile;
    int count=0;
    bool partOfComment=false;
   newfile.open("java.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      string s;
      while(getline(newfile, s)){ //read data from file object and put it into string.
        // trim the string of spaces
        s=removespaces(s); // removing tab space and normal space
        if(s.size() > 0){           
            bool partOfString = false;
            bool commentLine = s.substr(0,2) == "//" || s.substr(0,2) == "/*"; // check for comment

            if(!commentLine && !partOfComment){                                 // if not a part of comment, then inc counter
                    count++;
            }
            if((partOfComment || !partOfComment && s.substr(0,2)=="/*" )){ // to check for cases like /**/ int y;
                int n = s.size();
                bool close = false;
                for(int i=0;i<n;i++){
                    if(i< n-3 && s.substr(i,2) == "*/"){
                        cout<<s<<"\n";
                        close = true;  
                    }
                    else if(i < n-3 && s.substr(i,2) == "//") break;
                    else if(s.substr(i,2) == "/*") close = false;
                    else if(close) count++;
                }
            }
            for(int i=0;i<s.size();i++){                                    //read line to see if a multiline comment starts or ends. adjust boolean accordingly
                char prev = (i > 0) ? s[i-1] : 0;
                char curr = s[i];

                if(!partOfString && !partOfComment && prev == '/' && curr == '*'){
                    partOfComment = true;
                }
                else if(!partOfString && partOfComment && prev == '*' && curr == '/'){
                    partOfComment = false;
                }
                else if(curr == '"') {                                       // to check if the comment symbols are actually part of a string. adjust boolean accordingly
                    partOfString = !partOfString;
                }
            }
        }
      }
   }
    cout<<count;            // print the number of lines
    newfile.close(); //close the file object
}