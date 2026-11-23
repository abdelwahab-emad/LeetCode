class ProductOfNumbers {
    vector<int> pref;
public:
    ProductOfNumbers() {
        pref = {1};
    }
    
    void add(int num) {
        if (num == 0) {
            pref = {1};
        } else {
            pref.push_back(pref.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = (int)pref.size() - 1;
        if (k > n) return 0;
        return pref.back() / pref[n - k];
    }
};