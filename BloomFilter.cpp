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
bool isprime(int x){                                    // to check if number is prime
    for(int i=2;i<=sqrt(x);i++){
        if(x%i == 0) return false;
    }
    return true;
}                                       
struct BloomFilter{                                     // bloom filter
    vector<int>bits;
    int k;
    int elements;
    int size;
    BloomFilter(int e,int l){                   // constructor
        elements=e;
        k=l;
        size=0;
        vector<int>temp(e,0);
        bits = temp;
    }
    void add(string s){                         // add string to bloom filter
        vector<int>hashedbits=hash(s);
        for(int i=0;i<k;i++){
            bits[hashedbits[i]]=1;
        }
        size++;
    }
    bool contains(string s){                       // check if string exists
        vector<int>hashedbits=hash(s);        
        for(int i=0;i<k;i++){
            if(!bits[hashedbits[i]]) return false;      // return false if any of the bits are unset
        }
        return true;
    }
    vector<int> hash(string s){                         // k hash values at which the bits are set to 1
        vector<int>buffer;
        // hash func
        vector<int>hs(k);
        int c=1003;
        for(int i=0;i<k;++i){
            while(!isprime(c)) c++;
            int hash = h(s,c);
            long long int hashval = (hash%elements + elements)%elements;
            buffer.push_back(hashval);
        }
        return buffer;
    }
    int h(string s,int seed){                               // hash function used.
        ll hash=1;
        for(int i=0;i<s.size();i++){
            hash = ((hash*seed)%elements + (ll)pow((s[i]-'a'+1),i) %elements)%elements;
        }
        return hash;
    }
};
int main() {
      // #ifndef ONLINE_JUDGE
      // freopen("input", "r", stdin);
      // freopen("output", "w", stdout);
      // freopen("error", "w", stderr);
      //  #endif
        IOS;
        fstream word;
        word.open("words.txt",ios::in);             // open the list of words
        string s;
        BloomFilter* bloomfilter = new BloomFilter(500000,1);           // m=500000 k=1 with a collision probability of 0.5
        while(getline(word, s)){
            bloomfilter->add(s);
        }
        word.close();
        // PART 2- TESTING WITH RANDOM WORDS
        cout<<bloomfilter->contains("gooplichubyoyo")<<"\n";
        cout<<bloomfilter->contains("apple")<<"\n";
        cout<<bloomfilter->contains("banana")<<"\n";
        cout<<bloomfilter->contains("bonomovocosoaozzzcqworo")<<"\n";
        cout<<bloomfilter->contains("hello")<<"\n";

}