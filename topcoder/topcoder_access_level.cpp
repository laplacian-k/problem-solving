#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AccessLevel {
public:
	string canAccess(vector<int> rights, int minPermission);
};

string AccessLevel::canAccess(vector<int> rights, int minPermission) {
    string ret = "";
    
    for(int i = 0; i < rights.size(); i++) {
        if(rights[i] >= minPermission) ret += "A";
        else ret += "D";
    }
    
    return ret;        
    
}
