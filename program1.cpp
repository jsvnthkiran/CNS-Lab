#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isupper(ch)) {
            ch = ((ch - 65 + key) % 26) + 65;
        }
        else if(islower(ch)){
            ch=((ch-97+key)%26)+97;
        }
       
        result += ch;
    }
    return result;
}

string decrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isupper(ch)) {
            ch = ((ch - 65 - key + 26) % 26) + 65;
        }
        else if(islower(ch)){
            ch=((ch-97-key+26)%26)+97;
        }
       
        result += ch;
    }
    return result;
}

int main() {
    string text;
    cout<<"Enter input: ";
    getline(cin,text);
    int key = 3;
    string encrypted = encrypt(text, key);
    string decrypted = decrypt(encrypted, key);
    cout << "Original text: " << text << endl;
    cout << "Encrypted text: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;
    return 0;
}
