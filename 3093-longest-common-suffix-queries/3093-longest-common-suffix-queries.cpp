class Solution {
public:

    struct Node {
        int child[26];
        int bestIdx, bestLen;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
            bestLen = 1e9;
        }
    };

    struct Trie {

        vector<Node> trie;

        Trie() {
            trie.push_back(Node());
        }

        void update(int node, int len, int idx) {

            if(len < trie[node].bestLen) {
                trie[node].bestLen = len;
                trie[node].bestIdx = idx;
            }
            else if(len == trie[node].bestLen) {
                trie[node].bestIdx = min(trie[node].bestIdx, idx);
            }
        }

        void insert(string &s, int idx) {

            int node = 0;
            int len = s.size();

            update(node, len, idx);

            for(int i = len - 1; i >= 0; i--) {

                int c = s[i] - 'a';

                if(trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.push_back(Node());
                }

                node = trie[node].child[c];

                update(node, len, idx);
            }
        }

        int find(string &s) {

            int node = 0;

            for(int i = s.size() - 1; i >= 0; i--) {

                int c = s[i] - 'a';

                if(trie[node].child[c] == -1)
                    break;

                node = trie[node].child[c];
            }

            return trie[node].bestIdx;
        }
    };

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        for(int i = 0; i < wordsContainer.size(); i++) {
            trie.insert(wordsContainer[i], i);
        }
        vector<int> ans;
        for(auto &q : wordsQuery) {
            ans.push_back(trie.find(q));
        }
        return ans;
    }
};