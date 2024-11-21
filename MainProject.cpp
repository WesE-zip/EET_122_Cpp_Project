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


int main() {
    string word;
    word = ReadMsg("string");

    cout << word <<"\n";


    return 0;
}