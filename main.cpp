// Задание 1. Шифр Цезаря

#include <iostream>
#include <string>
#include <cctype> // std::isalpha

using std::cout;
using std::endl;
using std::string;

string getCipher(string &text, bool encryptMode, int offset) {
    string cipher;

    for (char &letter: text) {
        if (std::isalpha(letter)) {
            int juggling = letter >= 'a' ? 'a' : 'A';
            cipher += (encryptMode)
                      ? ((letter + offset - juggling) % 26) + juggling
                      : ((letter - offset - juggling) % 26) + juggling;
        } else {
            cipher += letter;
        }
    }

    return cipher;
}

string encrypt(string &text, int offset = 1) {
    return getCipher(text, true, offset);
}

string decrypt(string &text, int offset = 1) {
    return getCipher(text, false, offset);
}

int main() {
    int offset = 3;
    string encryptText;
    string decryptText;
    string origin = "Lorem ipsum dolor sit amet consectetur adipiscing "
                  "elit sed do eiusmod tempor incididunt ut labore et "
                  "dolore magna aliqua Ut enim ad minim veniam quis nostrud "
                  "exercitation ullamco laboris nisi ut aliquip ex ea commodo "
                  "consequat Duis aute irure dolor in reprehenderit in voluptate "
                  "velit esse cillum dolore eu fugiat nulla pariatur Excepteur "
                  "sint occaecat cupidatat non proident sunt in culpa qui "
                  "officia deserunt mollit anim id est laborum";

    encryptText = encrypt(origin, offset);
    decryptText = decrypt(encryptText, offset);

    cout << "original: " << origin << endl;
    cout << "------------" << endl;
    cout << "encryptText: " << encryptText << endl;
    cout << "------------" << endl;
    cout << "decryptText: " << decryptText << endl;
}