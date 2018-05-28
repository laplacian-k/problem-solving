#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Aaagmnrs {
public:
	vector<string> anagrams(vector<string> phrases);   
};
    
vector<string> Aaagmnrs::anagrams(vector<string> phrases) {
	// preprocessing
    for(int i = 0; i < phrases.size(); i++) {
        for(int j = 0; j < phrases[i].length(); j++) {
            if(phrases[i][j] == ' ') {
                phrases[i].erase(j, 1);
                continue;
            }
            if('A' <= phrases[i][j] && phrases[i][j] <= 'Z') phrases[i][j] = phrases[i][j]-'A'+'a';
        }
    }
    
    for(int i = 0; i < phrases.size(); i++) {
        vector<int> base(26, 0);
        for(int j = 0; j < phrases[i].length(); j++) {
        	base[phrases[i][j]-'a'] += 1;
        }
        
        
        for(int j = i+1; j < phrases.size(); j++) {
        	vector<int> target(26, 0);
            for(int k = 0; k < phrases[j].length(); k++) {
            	target[phrases[j][k]-'a'] += 1;
            }
            
            bool isDiff = false;
            for(int k = 0; k < 26; k++) {
                if(base[k] != target[k]){
                    isDiff = true;
                    break;
                }
            }
            if(isDiff) continue;
            else phrases.erase(phrases.begin()+j);
        }
        
    }            
        
    return phrases;         
}
