class Solution {
public:
    struct Trie{
    struct Node{
        Node *child[12];
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
            int idx = ch - '0';
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
            int idx = ch - '0';
            if (cur->child[idx] == nullptr) return nullptr;
            cur = cur->child[idx];
        }
        return cur;
    }

    int CountWord(string &s) {
        Node* res = find(s);
        return (res ? res->IsEnd : 0);
    }

    int CountPrefix(string &s) {
        Node* res = find(s);
        return (res ? res->Prefix : 0);
    }
};
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie sol;
        for(auto val : arr1) {
            string s = to_string(val);
            sol.insert(s);
        }   
        int ans = 0;
        for(auto val : arr2) {
            string cur = "", s = to_string(val);
            for(auto c : s) {
                cur += c;
                if (sol.CountPrefix(cur) > 0) {
                    ans = max(ans, (int)cur.size());
                }
            }
        }
        return ans;
    }
};