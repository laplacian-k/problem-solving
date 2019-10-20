#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Aaagmnrs {
public:
	vector<string> anagrams(vector<string> phrases);
    vector<int> makeAlphaSet(string phrases);
};

vector<int> Aaagmnrs::makeAlphaSet(string p) {
    vector<int> s(26, 0);
    for(int i = 0; i < p.length(); i++) {
        if(p[i] == ' ') continue;
        if('A' <= p[i] && p[i] <= 'Z') s[p[i]-'A'] += 1;
        else s[p[i]-'a'] += 1;
    }
    
    return s;
}
vector<string> Aaagmnrs::anagrams(vector<string> phrases) {
    // algorithm
    vector<string> ret;
    vector<bool> canUse(phrases.size(), true);
    
    for(int i = 0; i < phrases.size(); i++) {
        if(!canUse[i]) continue;
        vector<int> base = makeAlphaSet(phrases[i]);
        
        for(int j = i+1; j < phrases.size(); j++) {
            if(!canUse[j]) continue;
        	vector<int> target = makeAlphaSet(phrases[j]);
            
            bool isDiff = false;
            for(int k = 0; k < 26; k++) {
                if(base[k] != target[k]){
                    isDiff = true;
                    break;
                }
            }
            if(!isDiff) canUse[j] = false;
        }
    }      
    
    for(int i = 0; i < phrases.size(); i++) {
    	if(canUse[i]) ret.push_back(phrases[i]);
    }
    return ret;          
}
