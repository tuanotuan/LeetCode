class FrequencyTracker {
public:
    vector < int > cnt = vector < int > (1e5+5,0);
    vector < int > fre = vector < int > (1e5+5,0);
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(cnt[number] > 0)
        fre[cnt[number]]--;
        cnt[number]++;
        fre[cnt[number]]++;
        return;
    }
    
    void deleteOne(int number) {
        if(cnt[number] <= 0) return;
        fre[cnt[number]]--;
        cnt[number]--;
        if(cnt[number] > 0)
        fre[cnt[number]]++;
        return;
    }
    
    bool hasFrequency(int frequency) {
        return fre[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */