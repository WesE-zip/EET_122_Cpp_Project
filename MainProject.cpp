#include <iostream>
#include <cstring>
#include <string>
using namespace std;


string word, cut, encripted, inpToDcr, cutDcr, DCRed;
string Vkey, VkeyT, Akey;
int CesarShiftnum;
int Lnums[200];

const string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void clear() {
    word = "";
    cut = "";
    encripted = "";
    inpToDcr = "";
    cutDcr = "";
    DCRed = "";
}

string separate(string inp){
    string outp;
    
    for(int i = 0;i < inp.length();i++){
        if(isalpha(inp[i])){
            outp.push_back(toupper(inp[i]));
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

void toNum(string inp) {

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
    clear();
}

void makeKeyV(int t) {
    int L;
    int KL = VkeyT.length();
    string K = VkeyT;

    if(t == 1){
        L = cut.length();
    }
    if(t == 2){
        L = cutDcr.length();
    }


    while(L >= K.length()){
        for(int i = 0; i < KL && K.length() <= L; i++) {
            K.push_back(VkeyT[i]);
        }
    }

    Vkey = K;
}

void VigenereEncr(){
    string outp;
    int a, b, t, f;
    for(int i = 0; i < cut.length(); i++) {
        a = alph.find(cut[i]);
        b = alph.find(Vkey[i]);
        t = (a + b) % 26;
        if((t) < 26){
            if(t < 0){
                f = t + 26;
            }else{
                f = t;
            }
        }else{
            f = t - 26;
        }
        outp.push_back(alph[f]);
    }
    encripted = outp;
}

void VigenereDcr(){
    string outp;
    int a, b, t, f;
    for(int i = 0; i < cutDcr.length(); i++) {
        a = alph.find(cutDcr[i]);
        b = alph.find(Vkey[i]);
        t = (a - b) % 26;
        if((t) < 26){
            if(t < 0){
                f = t + 26;
            }else{
                f = t;
            }
        }else{
            f = t - 26;
        }
        outp.push_back(alph[f]);
    }
    DCRed = outp;
}

void runVigenere() {
    int t;
    cout << "Input the key: ";
    cin >> VkeyT;

    while(t != 0){
        cout << "Press 0 to exit\nPress 1 to encript\nPress 2 to decript \n";
        cin >> t;
        if(t == 1){
            ReadPlain();
            makeKeyV(t);
            cout << Vkey << endl;
            VigenereEncr();
            encrOutp("The key is: " + VkeyT);
        }else if(t == 2){
            ReadCypher();
            makeKeyV(t);
            VigenereDcr();
            dcrOutp("The key is: " + VkeyT);
        }else if(t != 0){
            cout << "ERROR" << endl;
        }
    }

    cout << "End Vigenere Cypher" << endl;
    clear();
}

void makeKeyA(int t) {
    int L;
    string K = Akey;
    string msg;

    if(t == 1){
        L = cut.length();
        msg = cut;
    }
    if(t == 2){
        L = cutDcr.length();
        msg = cutDcr;
    }

    K += msg.substr(0, (msg.length() - 2));

    Vkey = K;
}

void run(){
    int t;


    while(t != 0){
        cout << "Press 1 for Ceaser Cypher \nPress 2 for Vigenere Cypher \nPress 0 to exit" << endl;
        cin >> t;
        cin.ignore();
        if(t == 1){
            runCeasar();
        }else if(t == 2) {
            runVigenere();
        }else if(t != 0){
            cout << "ERROR" << endl;
        }
    }
}

int main() {
    
    run();





    return 0;
}