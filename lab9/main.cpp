#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class ReplaceMyString {
public:
    void replacemystring(const string& findStr, const string& replaceStr) {
        ifstream inFile("main.cpp");  
        ofstream outFile("rmain.cpp");  

        if (inFile.is_open() && outFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                size_t pos = line.find(findStr);
                while (pos != string::npos) {
                    line.replace(pos, findStr.length(), replaceStr);
                    pos = line.find(findStr, pos + replaceStr.length());
                }
                outFile << line << endl; 
            }

            inFile.close();  
            outFile.close();  
            
        }
        
    }
};

int main() {
    ReplaceMyString my;
    my.replacemystring("IU", "IU is best");
    return 0;
}
