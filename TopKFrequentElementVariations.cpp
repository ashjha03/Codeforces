class MostFrequentElement {
    map<int, int> freq;
    multiset<pair<int, int>> rev;
public:

    void insert(int ele){
        if(freq[ele])   rev.erase({freq[ele], ele});
        freq[ele]++;
        rev.insert({freq[ele], ele});
    }

    MostFrequentElement(vector<int> &arr){
        int n = arr.size();
        for(int i=0; i<n; i++){
            insert(arr[i]);
            cout << rev.rbegin()->second << ' ';
        }
    }
};

class MostKFrequentElements {
    int k;
    map<int, int> freq;
    multiset<pair<int, int>> top, rem;
public:
    void balance(){
        while (top.size() > k) {
            auto mini = top.begin();
            rem.insert(*mini);
            top.erase(mini);
        }
    }
    void balance2(){
        while (top.size() < k && !rem.empty()) {
            auto maxi = prev(rem.end());
            top.insert(*maxi);
            rem.erase(maxi);
        }
    }
    void insert(int ele){
        if (freq[ele] > 0) {
            if (top.count({freq[ele], ele})) {
                top.erase(top.find({freq[ele], ele}));
            } else {
                rem.erase(rem.find({freq[ele], ele}));
            }
        }
        freq[ele]++;
        
        top.insert({freq[ele], ele});
        balance();
    }
    void remove(int ele){
        if (freq[ele] > 0) {
            if (top.count({freq[ele], ele})) {
                top.erase(top.find({freq[ele], ele}));
            } else {
                rem.erase(rem.find({freq[ele], ele}));
            }
            freq[ele]--;
            if (freq[ele] == 0) {
                freq.erase(ele);
            } else {
                rem.insert({freq[ele], ele});
            }
            balance2();
        }
    }
    MostKFrequentElements(vector<int> &arr, int k){
        this->k = k;
        for(auto x: arr){
            insert(x);
        }
    }
    vector<int> result(){
        vector<int> res;
        for(auto it = top.begin(); it != top.end(); it++)   res.push_back(it->second);
        return res;
    }
};

class MostKFrequentElementsSum {
    int x;
    long long sum;

    map<int, long long> freq;
    multiset<pair<int, int>> top;
    multiset<pair<int, int>> rem;

public:
    MostKFrequentElementsSum(int x) : x(x), sum(0) {}

    void balance() {
        while (top.size() > x) {
            auto mini = top.begin();
            sum -= mini->second * 1ll * mini->first;
            rem.insert(*mini);
            top.erase(mini);
        }
    }

    void balance2() {
        while (top.size() < x && !rem.empty()) {
            auto maxi = prev(rem.end());
            sum += maxi->second * 1ll * maxi->first;
            top.insert(*maxi);
            rem.erase(maxi);
        }
    }

    void insert(int ele) {
        if (freq[ele] > 0) {
            if (top.count({freq[ele], ele})) {
                sum -= ele * 1ll * freq[ele];
                top.erase(top.find({freq[ele], ele}));
            } else {
                rem.erase(rem.find({freq[ele], ele}));
            }
        }
        freq[ele]++;
        
        top.insert({freq[ele], ele});
        sum += ele * 1ll * freq[ele];
        balance();
    }

    void remove(int ele) {
        if (freq[ele] > 0) {
            if (top.count({freq[ele], ele})) {
                sum -= ele * 1ll * freq[ele];
                top.erase(top.find({freq[ele], ele}));
            } else {
                rem.erase(rem.find({freq[ele], ele}));
            }
            freq[ele]--;
            if (freq[ele] == 0) {
                freq.erase(ele);
            } else {
                rem.insert({freq[ele], ele});
            }
            balance2();
        }
    }

    long long result() {
        return sum;
    }
};
