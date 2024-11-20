#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string ReadMsg(){
    string inp;

    cout << "Input the string: ";

    getline(cin, inp);
  

    return inp;
}


int main() {
    string word;
    word = ReadMsg();

    cout << word <<"\n";


    return 0;
}