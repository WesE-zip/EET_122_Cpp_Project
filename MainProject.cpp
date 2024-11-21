#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string ReadMsg(string thing){
    string inp;

    cout << "Input the " << thing << ": ";

    getline(cin, inp);
  

    return inp;
}

string separate(string inp){
    string outp;

    for(int i = 0;i < inp.length();i++){
        if(isalpha(inp[i])){
            outp.push_back(inp[i]);
        }
    }

    return outp;
}

int main() {
    string word, cut;
    word = ReadMsg("string");

    cut = separate(word);

    cout << word <<"\n";
    cout << cut << "\n";


    return 0;
}