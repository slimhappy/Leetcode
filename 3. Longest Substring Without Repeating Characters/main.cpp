#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void display(unordered_map<char,int> myhash_map,string str)
{
    cout << str << endl;
    for (auto& x: myhash_map)
        cout << x.first << ": " << x.second << endl;
    cout << endl;
}

int main ()
{
    string s="aab";
    unordered_map<char,int> myhash_map;
    int start= -1;
    int Max=0;
    cout<<s.length()<<endl;
    for(int i=0;i<s.length();i++){
       if(myhash_map.find(s[i])!= myhash_map.end() &&myhash_map[s[i]]>=start){
           start = myhash_map[s[i]];
       }
       Max = max(Max,i-start);
       myhash_map[s[i]]=i;
    }
    cout<<Max<<endl;

    return 0;

}
