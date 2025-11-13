#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
     bool isEnd;
     unordered_map<char,TrieNode*>mp;
     TrieNode(){
        isEnd=false;
     }
};
class Trie {
    private:
       TrieNode*root;
    public:
       Trie(){
          root=new TrieNode();
       }

       void insert(const string &name){
        TrieNode*node=root;
        for(auto i:name){
            if(!node->mp[i]){
                node->mp[i]=new TrieNode();
            }
            node=node->mp[i];
        }
        node->isEnd=true;
       }

       void ExactMatch(const string &name){
        TrieNode *node=root;
        for(auto i:name){
            if(!node->mp[i]){
                cout<<"Not found";
                return;
            }
            node->mp[i];           
        }
        if(node->isEnd){
            cout<<"Yes Name is found";
        }
        else{
            cout<<"Name is not found";
        }
       }

       void suggestion(const string &prefix){
        TrieNode*node=root;
        for(auto i:prefix){
            if(!node->mp[i]){
                cout<<"Match not found";
                return;
            }
            node=node->mp[i];

        }
        vector<string>res;
        dfs(node,prefix,res);
        cout<<"Suggestion\n";
        for(auto i:res){
            cout<<i<<endl;
        }

       }

       void dfs(TrieNode*node,string prefix,vector<string>&res){
        if(node->isEnd){
            res.push_back(prefix);
        }
        for(auto p:node->mp){
            dfs(p.second,p.first+prefix,res);
        }
       }

       
    
};
int main(){
    Trie dict;
    dict.insert("apple");
    dict.insert("app");
    dict.insert("ape");
    dict.insert("bat");
    dict.ExactMatch("app");
    dict.suggestion("ap");
    return 0;
}