#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
       bool isEnd;
       string number;
       unordered_map<char,TrieNode*>mp;
       TrieNode(){
        number="";
        isEnd=false;
       }

};

class PhoneLogBook{
    private:
        TrieNode *root;
    public:
        PhoneLogBook(){
            root=new TrieNode();
        }
        // insert name
        void insert(const string & name,const string &number){
            TrieNode *node=root;
            for(auto c:name){
                if(node->mp.find(c)==node->mp.end()){
                    node->mp[c]=new TrieNode();
                }
                node=node->mp[c];
            }
            node->isEnd=true;
            node->number=number;
        }
        // exact name
        void search (const string &name){
            TrieNode *node=root;
            for(auto c:name){
                if(node->mp.find(c)==node->mp.end()){
                    cout<<"NO match found";
                    return;
                }
                node=node->mp[c];
            }
            if(node->isEnd){
                cout<<name<<"--->"<<node->number;
            }
            else{
                cout<<"contact not found";
            }

        }

        // for prefix match
        void prefixMatch(const string& prefix){
            TrieNode*node=root;
            for(auto c:prefix){
                if(node->mp.find(c)==node->mp.end()){
                    cout<<"Prefix not matched with any contact";
                    return;
                }
                node=node->mp[c];
            }
            vector<pair<string,string>>res;
            dfs(node,prefix,res);

        }

        void dfs(TrieNode*node,const string &prefix,vector<pair<string,string>>&res){
            if(node->isEnd){
                res.push_back({prefix,node->number});
            }
            for(auto c:node->mp){
                dfs(c.second,(prefix+ c.first),res);
            }
        }
            
       
};
int main(){
    PhoneLogBook logbook;
    logbook.insert("Rahul", "9876543210");
    logbook.insert("Ramesh", "9123456780");
    logbook.insert("Ragini", "9812345678");
    logbook.insert("Rohit", "9000000000");
    cout << " Search Results:\n";
    logbook.search("Rahul");
    logbook.search("Rohan");
    logbook.prefixMatch("Ro");
    return 0;
}