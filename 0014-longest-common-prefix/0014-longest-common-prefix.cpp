class Solution {
public:
struct Trie{
    struct Node{
        Node *child[26];
        int IsEnd, Prefix;
        Node(){
            memset(child, 0, sizeof child);
            IsEnd = Prefix = 0;
        }
    };

    Node *root = new Node();
    void insert(string &s){
        Node *cur = root;
        for(auto ch : s){
            int idx = ch - 'a';
            if(cur->child[idx] == 0){
                cur->child[idx] = new Node();
            }
            cur = cur->child[idx];
            cur->Prefix++;
        }
        cur->IsEnd++;
    }

    Node* find(string &s) {
        Node *cur = root;
        for (auto ch : s) {
            int idx = ch - 'a';
            if (cur->child[idx] == nullptr) return nullptr;
            cur = cur->child[idx];
        }
        return cur;
    }
    int CountPrefix(string &s) {
        Node* res = find(s);
        return (res ? res->Prefix : 0);
    }
};
    string longestCommonPrefix(vector<string>& strs) {
        Trie sol;            
        for(auto & s : strs) {
            sol.insert(s);
        }
        int n = strs.size();
        string re = "";
        for (auto c : strs[0]) {
            re += c;
            if (sol.CountPrefix(re) != n) {
                re.pop_back();
                break;
            }
        }
        return re;
    }
};