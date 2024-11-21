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

int GetNum(string thing){
    int num;

    cout << "Input the " << thing << ": ";

    cin >> num;
    return num;
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

string CeasarEncr(string inp, int shift){
    string outp;
    bool test = false;
    int shiftnum;
    
    string alph = "abcdefghijklmnopqrstuvwxyz";

    for(int i = 0;i < inp.length();i++){
        for(int l = 0; l < alph.length();l++){
            if(inp[i] == alph[l]){
                if((l + shift) < 26){
                    shiftnum = l + shift;
                } else {
                    shiftnum = (l + shift) - 26;
                }
                outp.push_back(alph[shiftnum]);
                test = true;
            }
        }
        test = false;
    }


    return outp;
}

int main() {
    string word, cut;
    word = ReadMsg("string");

    cut = separate(word);

    cout << word <<"\n";
    cout << cut << "\n";

    cout << CeasarEncr(cut, GetNum("number of the shift must be < 26")) << endl;



    return 0;
}