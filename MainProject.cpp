#include <iostream>
#include <cstring>
#include <string>
using namespace std;


string word, cut, encripted, inpToDcr, cutDcr, DCRed;
int CesarShiftnum;

const string alph = "abcdefghijklmnopqrstuvwxyz";

string separate(string inp){
    string outp;
    
    for(int i = 0;i < inp.length();i++){
        if(isalpha(inp[i])){
            outp.push_back(tolower(inp[i]));
        }
    }

    return outp;
}

string ReadThing(string thing){
    string inp;

    cout << "Input the " << thing << ": ";
    cin.ignore();
    getline(cin, inp);

  

    return inp;
}

void ReadPlain(){
    cout << "Input the Plaintext: ";
    cin.ignore();
    getline(cin, word);
    cut = separate(word);    
}

void ReadCypher(){
    cout << "Input the Cyphertext: ";
    cin.ignore();
    getline(cin, inpToDcr);
    cutDcr = separate(inpToDcr);    
}

int GetNum(string thing){
    int num;

    cout << "Input the " << thing << ": ";

    cin >> num;
    return num;
}

void encrOutp(string data){
    cout << "The Plaintext is: " << word << endl<< data << endl << "The Cyphertext is: " << encripted << endl;
}

void dcrOutp(string data){
    cout << "The Cyphertext is: " << inpToDcr << endl<< data << endl << "The decripted Plaintext is: " << DCRed << endl;
}


void CeasarEncr(){
    string outp;
    bool test = false;
    int shift;
    
    

    for(int i = 0;i < cut.length();i++){
        for(int l = 0; l < alph.length();l++){
            if(cut[i] == alph[l]){
                if((l + CesarShiftnum) < 26){
                    shift = l + CesarShiftnum;
                } else {
                    shift = (l + CesarShiftnum) - 26;
                }
                outp.push_back(alph[shift]);
                test = true;
            }
        }
        test = false;
    }


    encripted = outp;
}

void CeasarDcr(){
    string outp;
    bool test = false;
    int shift;
    

    for(int i = 0;i < cutDcr.length();i++){
        for(int l = 0; l < alph.length();l++){
            if(cutDcr[i] == alph[l]){
                if((l - CesarShiftnum) >= 0){
                    shift = l - CesarShiftnum;
                } else {
                    shift = (l - CesarShiftnum) + 26;
                }
                outp.push_back(alph[shift]);
                test = true;
            }
        }
        test = false;
    }

    DCRed = outp;
    
}

void runCeasar(){
    int t;
    string sh = "The shiftnum is: ";
    cout << "Input shiftnum: ";
    cin >> CesarShiftnum;
    sh += to_string(CesarShiftnum);
    while(t != 0){
        cout << "Press 0 to exit\nPress 1 to encript\nPress 2 to decript \n";
        cin >> t;
        if(t == 1){
            ReadPlain();
            CeasarEncr();
            encrOutp(sh);
        }else if(t == 2){
            ReadCypher();
            CeasarDcr();
            dcrOutp(sh);
        }else if(t != 0){
            cout << "ERROR" << endl;
        }
    }

    cout << "End Ceaser Cypher" << endl;
}


void run(){
    int t;


    while(t != 0){
        cout << "Press 1 for Ceaser Cypher \nPress 0 to exit" << endl;
        cin >> t;
        cin.ignore();
        if(t == 1){
            runCeasar();
        }else if(t != 0){
            cout << "ERROR" << endl;
        }
    }
}

int main() {
    
    run();





    return 0;
}