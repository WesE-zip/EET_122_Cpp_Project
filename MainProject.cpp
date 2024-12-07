#include <iostream>
#include <cstring>
#include <string>
using namespace std;


string word, cut, encripted, inpToDcr, cutDcr, DCRed; //Variable declaration of the main variables
string Vkey, VkeyT, Akey;//Declaration of variables for the encription methods
int CesarShiftnum;
int a, b, Ainv;

const string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //Declaration of an alphabet string

//Function to clear the main variables
void clear() {
    word = "";
    cut = "";
    encripted = "";
    inpToDcr = "";
    cutDcr = "";
    DCRed = "";
}

//Function to separate out everything but letters and make them uppercase
string separate(string inp){
    string outp;
    
    for(int i = 0;i < inp.length();i++){
        if(isalpha(inp[i])){
            outp.push_back(toupper(inp[i]));
        }
    }

    return outp;
}

/*
string ReadThing(string thing){
    string inp;

    cout << "Input the " << thing << ": ";
    cin.ignore();
    getline(cin, inp);  

    return inp;
}
*/

//Reads the plaintext and assingns the Uppercase letter only form to the variable cut
void ReadPlain(){
    cout << "Input the Plaintext: ";
    cin.ignore();
    getline(cin, word);
    cut = separate(word);    
}

//Reads the Cyphertext and assingns the Uppercase letter only form to the variable cutDcr
void ReadCypher(){
    cout << "Input the Cyphertext: ";
    cin.ignore();
    getline(cin, inpToDcr);
    cutDcr = separate(inpToDcr);    
}

//Prints the encription output
void encrOutp(string data){
    cout << "The Plaintext is: " << word << endl<< data << endl << "The Cyphertext is: " << encripted << endl;
}

//Prints the decription output
void dcrOutp(string data){
    cout << "The Cyphertext is: " << inpToDcr << endl<< data << endl << "The decripted Plaintext is: " << DCRed << endl;
}


//Encripts using Ceasar Cypher
void CeasarEncr(){
    //Variable declaration
    string outp;
    bool test = false;
    int shift;
    
    

    for(int i = 0;i < cut.length();i++){ //Goes through the plain text
        for(int l = 0; l < alph.length();l++){ //Goes through the alphabet for each letter
            if(cut[i] == alph[l]){
                if((l + CesarShiftnum) < 26){ //gives the positon of the encriped char making sure to not go out of bounds
                    shift = l + CesarShiftnum;
                } else {
                    shift = (l + CesarShiftnum) - 26;
                }
                outp.push_back(alph[shift]); //Pushes back each char to the output
                test = true;
            }
        }
        test = false;
    }


    encripted = outp;
}

//Decripts using Ceaser Cypher
void CeasarDcr(){
    //Variable declaration
    string outp;
    bool test = false;
    int shift;
    

    for(int i = 0;i < cutDcr.length();i++){ //Goes through the Cyphertext
        for(int l = 0; l < alph.length();l++){ //Goes through the alphabet for each letter
            if(cutDcr[i] == alph[l]){
                if((l - CesarShiftnum) >= 0){ //gives the positon of the encriped char making sure to not go out of bounds
                    shift = l - CesarShiftnum;
                } else {
                    shift = (l - CesarShiftnum) + 26;
                }
                outp.push_back(alph[shift]); //Pushes back each char to the output
                test = true;
            }
        }
        test = false;
    }

    DCRed = outp;
    
}

//Runs the Ceaser Cypher menu
void runCeasar(){
    int t; //Input num
    string sh = "The shiftnum is: ";
    cout << "Input shiftnum: ";//reading the shiftnum
    cin >> CesarShiftnum;
    sh += to_string(CesarShiftnum); //Preaparing the shiftnum output
    while(t != 0){
        cout << "Press 0 to exit\nPress 1 to encript\nPress 2 to decript \n"; //Menu prompt and t read
        cin >> t;
        if(t == 1){ //runs encription
            ReadPlain(); //reads the plaintext
            CeasarEncr(); //Encripts with Ceaser cypher
            encrOutp(sh); //outputs
        }else if(t == 2){ //runs decription
            ReadCypher(); //reads the cyphertext
            CeasarDcr(); //decripts
            dcrOutp(sh); //outputs
        }else if(t != 0){
            cout << "ERROR" << endl; //In case they input sompthing else
        }
    }

    cout << "End Ceaser Cypher" << endl;
    clear(); //Clears in out vars
}

//makes a key for vigenere cypher
void makeKeyV(int t) {
    //variable declaration
    int L;
    int KL = VkeyT.length();
    string K = VkeyT;

    if(t == 1){//so encription or decription can come first
        L = cut.length();
    }
    if(t == 2){
        L = cutDcr.length();
    }


    while(L >= K.length()){ //Repeats the keyword and adds it
        for(int i = 0; i < KL && K.length() <= L; i++) {
            K.push_back(VkeyT[i]);
        }
    }

    Vkey = K;
}

//Encripts with vigenere cypher
void VigenereEncr(){
    //variable declaration
    string outp;
    int a, b, t, f;

    for(int i = 0; i < cut.length(); i++) { //Loops through plaintext
        //finds the positon of the chars in the alphabet
        a = alph.find(cut[i]);
        b = alph.find(Vkey[i]);
        //Does the math to encript
        t = (a + b) % 26;
        //makes sure there is no out of bounds
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

//Decripts with Vigenere Cypher
void VigenereDcr(){
    //Variable declaration
    string outp;
    int a, b, t, f;

    for(int i = 0; i < cutDcr.length(); i++) { //loops through cyphertext
        //finds the positon of the chars in the alphabet
        a = alph.find(cutDcr[i]);
        b = alph.find(Vkey[i]);
        //Does the math to decript
        t = (a - b) % 26;
        //makes sure it is not going out of bounds
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

//Runs Vigenere cypher menu
void runVigenere() {
    int t; //Input num
    cout << "Input the key: ";//keyword input
    cin >> VkeyT;

    while(t != 0){
        cout << "Press 0 to exit\nPress 1 to encript\nPress 2 to decript \n"; //Menu
        cin >> t;
        if(t == 1){ //Encription
            ReadPlain(); //Reads plaintext
            makeKeyV(t); //makes the key for vigenere cypher
            VigenereEncr(); //Encripts 
            encrOutp("The key is: " + VkeyT); //Outputs
        }else if(t == 2){ //Decription
            ReadCypher(); //Reads Cyphertext
            makeKeyV(t); //makes the key for viginere cypher
            VigenereDcr(); //Decripts
            dcrOutp("The key is: " + VkeyT); //Outputs
        }else if(t != 0){ //Incase they input sompthing else
            cout << "ERROR" << endl;
        }
    }

    cout << "End Vigenere Cypher" << endl;
    clear();
}

//Makes an autokey which is a different type of key for Vigenere
void makeKeyA() {
    //variable declaration
    int L;
    string K = Akey;
    string msg;
    msg = cut;

    K += msg.substr(0, (msg.length() - 2)); //Makes the key which is the key letter with the plaintext added onto it minus the last letter

    Vkey = K;
}

//Runs the autokey cypher menu
void runAutokey() {
    int t; //Input num
    cout << "Input the key: "; //Gets the key letter
    cin >> Akey;
    //Starts right into encription since it must come first
    ReadPlain(); //Reads plaintext
    makeKeyA(); //Makes autokey
    VigenereEncr(); //Uses the Vigenere Encription to encript
    encrOutp("The key is: " + Akey); //Outputs
    while(t != 0){
        cout << "Press 0 to exit\nPress 1 to encript\nPress 2 to decript \n"; //Menu 
        cin >> t;
        if(t == 1){ //Encription
            ReadPlain(); //Reads plaintext
            makeKeyA(); //Makes autokey
            VigenereEncr(); //Uses the Vigenere Encription to encript
            encrOutp("The key is: " + Akey); //Outputs
        }else if(t == 2){ //Decription
            ReadCypher(); //Reads Cyphertext
            VigenereDcr(); //Uses the Vigenere Decription to Decript
            dcrOutp("The key is: " + Akey); //Outputs
        }else if(t != 0){ //Incase they input sompthing else
            cout << "ERROR" << endl;
        }
    }

    cout << "End Autokey Cypher" << endl;
    clear();
}

/*void AffineEncr() {
    string outp;
    int n;
    for(int i = 0; i < cut.length(); i++) {
        n = (a * (alph.find(cut[i])) + b) % 26;
        if((n) < 26){
            if(n < 0){
                n = n + 26;
            }else{
                n = n;
            }
        }else{
            n = n - 26;
        }
        outp.push_back(alph[n]);
    }
    encripted = outp;
}

void AffineDcr() {
    string outp;
    int f, n;
    for(int i = 0; i < 26; i++) {
        if((((a % 26) * (i % 26)) % 26) == 1) {
            Ainv = i;
            //cout << "\n test  " + Ainv << " \n ";
        }
    }

    for(int i = 0; i < cutDcr.length(); i++) {
        n = (Ainv * (alph.find(cutDcr[i]) - b)) % 26;
        if((n) < 26){
            if(n < 0){
                n = n + 26;
            }else{
                n = n;
            }
        }else{
            n = n - 26;
        }
        outp.push_back(alph[n]);
    }

    DCRed = outp;
}

void runAffine() {
    int t; //Input num
    cout << "Input the A: "; //Gets the a
    cin >> a;
    cout << "Input the B: "; //Gets the b
    cin >> b;
    string A = ("A is: "); //Preparing A and B outputs
    string B = (" B is: ");
    A += to_string(a);
    B += to_string(b);
    while(t != 0){
        cout << "Press 0 to exit\nPress 1 to encript\nPress 2 to decript \n"; //Menu 
        cin >> t;
        if(t == 1){ //Encription
            ReadPlain(); //Reads plaintext
            AffineEncr(); //Uses the Affine Encription to encript
            encrOutp(A + B); //Outputs
        }else if(t == 2){ //Decription
            ReadCypher(); //Reads Cyphertext
            AffineDcr(); //Uses the Affine Decription to Decript
            dcrOutp(A + B); //Outputs
        }else if(t != 0){ //Incase they input sompthing else
            cout << "ERROR" << endl;
        }
    }

    cout << "End Affine Cypher" << endl;
    clear();
}*/

//Runs the main menu
void run(){
    int t; //Input num


    while(t != 0){
        cout << "Press 1 for Ceaser Cypher \nPress 2 for Vigenere Cypher \nPress 3 for Autokey Cypher \nPress 0 to exit" << endl; //menu text
        cin >> t;
        cin.ignore();
        if(t == 1){ //Runs Ceaser Cypher menu
            runCeasar();
        }else if(t == 2) { //Runs Vigenere menu
            runVigenere();
        }else if(t == 3){ //Runs Autokey menu
            runAutokey();
        }else if(t != 0){ //Incase they input sompthing else
            cout << "ERROR" << endl;
        }
    }
}

int main() {
    
    run(); //Runs main menu





    return 0;
}