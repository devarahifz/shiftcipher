/**
 * Nama : Devara Hifzhurrahman
 * NPM  : 140810190019
 * Kelas: A
 */

#include <iostream>
using namespace std;

string enkripsi(string plainteks, int key){
    bool isSpasi;
    for (int i = 0; i < plainteks.length(); i++){
        if (plainteks[i] == 32 ){
            isSpasi = true;
        }
        else{
            isSpasi = false;
        }
        
        if (isSpasi){
            plainteks[i] = ' ';
        }
        else{
            if (plainteks[i] >= 97){
                plainteks[i] = ((plainteks[i] - 97) + key) % 26;
                plainteks[i] += 97;
            }
            else{
                plainteks[i] = ((plainteks[i] - 65) + key) % 26;
                plainteks[i] += 65;
            }
        }
    }
    return plainteks;
}

string dekripsi(string cipherteks, int key){
    bool isSpasi;
    for (int i = 0; i < cipherteks.length(); i++){
        if (cipherteks[i] == 32){
            isSpasi = true;
        }
        else{
            isSpasi = false;
        }

        if (isSpasi){
            cipherteks[i] = ' ';
        }
        else{
            if (cipherteks[i] >= 97){
                cipherteks[i] = ((cipherteks[i] - 97) - key) % 26;
                if (cipherteks[i] + 97 < 97){
                    cipherteks[i] += 97 + 26;
                }
                else{
                    cipherteks[i] += 97;
                }
            }
            else{
                cipherteks[i] = ((cipherteks[i] - 65) - key) % 26;
                if (cipherteks[i] + 65 < 65){
                    cipherteks[i] += 65 + 26;
                }
                else{
                    cipherteks[i] += 65;
                }
            }
        }
    }
    return cipherteks;
}

int main(){
    char loop;
    string plainteks, cipherteks;
    int key;
    do{
        system("cls");
        cout << "==== PROGRAM SHIFT CIPHER ====\n";
        cout << "Masukkan Plainteks : "; getline(cin >> ws, plainteks);
        cout << "Masukkan Key : "; cin >> key;
        
        cipherteks = enkripsi(plainteks, key);
        cout << "Hasil Enkripsi : " << cipherteks << endl;

        plainteks = dekripsi(cipherteks, key);
        cout << "Hasil Dekripsi : " << plainteks << endl;

        cout << "Apakah Anda ingin mengulang ? (Y/N)"; cin >> loop;
    }while (loop == 'Y' || loop == 'y');
    return 0;
}