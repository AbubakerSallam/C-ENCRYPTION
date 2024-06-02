#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

using namespace std;

string encrypt(string plaintext,string key) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) {
        int c = (int)plaintext[i] ^ (int)key[i];
        ciphertext += to_string(c);
    }
    return ciphertext;
}

string decrypt(string ciphertext,string key) {
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i+=2) {
        int c = stoi(ciphertext.substr(i,2));
        char p = (char)(c ^ (int)key[(i/2)]);
        plaintext += p;
    }
    return plaintext;
}

string generateKey(string plaintext) {
    string key = "";
    srand(time(0)); 
    for (int i = 0; i < plaintext.length(); i++) {
        int random = rand() % 256;
        key += to_string(random);
    }
    return key;
}

int main() {
    string plaintext, key, ciphertext;
    int choice;
    while (choice!=3) {
        cout<<"                         ###### Abubaker Sallam ######\n\n\n\n";
        cout << "1. Encrypt\n2. Decrypt\n3. Exit\n\n\nSelect an option:";
        cin >> choice;
        switch (choice) {
        case 1:
      {      cout << "Enter the plaintext: ";
            cin.ignore();
            getline(cin, plaintext);
            key = generateKey(plaintext);
            ciphertext = encrypt(plaintext, key);
            cout << "The ciphertext is: " << ciphertext<<"\n\n\n\n";           
            ofstream keyFile("key.txt");
            keyFile << key;
            keyFile.close();}
            system("pause");
            break;
        case 2:
        {    cout << "Enter the ciphertext: ";
            cin >> ciphertext;
            ifstream keyFile("key.txt");
            getline(keyFile, key);
            keyFile.close();
            plaintext = decrypt(ciphertext, key);
            cout << "The plaintext is: " << plaintext<< "\n\n\n\n";}
            system("pause");
            break;     
        default:
            cout << "Invalid option! Choose again.\n\n";
            break;
        }
    }
    return 0;
}