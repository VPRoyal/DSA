#include <bits/stdc++.h>

using namespace std;
class Node{
public:
    vector<Node*> children;
    int count;
    bool isEndOfWord;
    Node() : count(1), isEndOfWord(false), children(26, nullptr) {}
};
class Trie{
    private:
        Node* root;
        string txt;
    public:
        Trie(string text){
            root = new Node();
            txt=text;
            createTree();
        }
        Node* insertNode(char c, Node* currentNode){
            int C=c-'a';
            if(currentNode->children[C]==nullptr){
                Node* newNode = new Node();
                currentNode->children[C]=newNode;
                return newNode;
            }
            currentNode->children[C]->count++;
            return currentNode->children[C];
        }
        int countOccurrences(string gene){
            Node* temp=root;
            for(char c:gene){
                int C=c-'a';
                if(temp->children[C]!=nullptr) temp=temp->children[C];
                else return 0;
            }
            return temp->count;
        }
        void createTree(){
        for(int j=this->txt.size()-1; j>=0;j--){
                Node* temp=root;
            for(int i=j;i<this->txt.size();i++){
                temp=insertNode(this->txt[i],temp); 
            }
            }
        }
};
int main(){
    int n,p;
    cin>>n;
    vector<string> genes;
    vector<int> health;
    for(int i=0;i<n;i++){
        string gene;
        cin>>gene;
        genes.push_back(gene);
    }
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        health.push_back(h);
    }
    cin>>p;
    int maxHealth=0;
    int minHealth=INT_MAX;
    while(p--){
        int s,e;
        string str;
        cin>>s>>e>>str;
        unordered_map<string,int> occur;
        Trie* strands=new Trie(str);
        int hlth=0;
        for(int i=s;i<=e;i++){
            if(occur.find(genes[i])==occur.end()){
                int freq=strands->countOccurrences(genes[i]);
                occur[genes[i]]=freq;
                hlth+=freq*health[i];
            }else{
                 hlth+=occur[genes[i]]*health[i];
            }
        }
        maxHealth=max(maxHealth,hlth);
        minHealth=min(minHealth,hlth);
    }
    cout<<minHealth<<" "<<maxHealth<<endl;
    return 0;
}