#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ABBADiv1 {
public:
	string canObtain(string initial, string target);
    void go(string initial, string target);
private:
    bool condition = false;
       
};

string ABBADiv1::canObtain(string initial, string target) {
    
    ABBADiv1::go(initial, target);
                  
    return (condition)?"Possible":"Impossible";
}
void ABBADiv1::go(string initial, string target) {
	if(initial.length() == target.length()) condition = (initial == target);
    
    string conv1 = target;
    string conv2 = target;
    
    if(target[target.length()-1] == 'A') {
        conv1 = conv1.substr(0, conv1.length()-1);
    	go(initial, conv1);
    }
    
    if(target[0] == 'B') {
        conv2 = conv2.substr(1, conv2.length());
        reverse(conv2.begin(), conv2.end());
        go(initial, conv2);
    }    
}
