#include <bits/stdc++.h>
using namespace std;
class LogBook{
    unordered_map<string ,string>mp;
public:
    void addcontact(string name,string number){
        mp[name]=number;
    }
    void findnumber(string name){
        if(mp.find(name)!=mp.end()){
            cout<<name<<"--->"<<mp[name]<<endl;
        }
        else{
            cout<<"Not found";
        }
    }
    void printAll(){
        for(auto &p : mp){
            cout<<p.first<<"--->"<<p.second<<endl;
        }
    }
};
int main(){
    LogBook book;
    book.addcontact("Rahul", "9876543210");
    book.addcontact("Ramesh", "9123456780");
    book.findnumber("Rahul");
    return 0;
}