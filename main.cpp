#include <iostream>
#include <random>
using namespace std;



int main(){
    //Deklarálás
    int x, y, z, zs, a;
    int* xp = &x;
    int* yp = &y;
    int* zp = &z;
    int* zsp = &zs;
    int* ap = &a;

    //Randomolás
    srand(time(NULL));
    // [x, y, z, zs, a, xp, yp, zp, zsp, ap]
    int poz[10];
    int szerep[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i<10; i++){
        int k = rand()%10;
        while (szerep[k] == 1){
            k = rand()%10;
        }
        szerep[k] = 1;
        poz[i] = k;
    }
    int kartyak[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //Játék
    while (true) {
        cout << "-------------------" << endl;
        for (int i : kartyak) {
            cout << i << " ";
        }
        cout << endl;
        int szam[2];
        cout << "Elso valasztas: " << endl;
        cin >> szam[0];
        cout << "Masodik valasztas: " << endl;
        cin >> szam[1];
        szam[0]--;
        szam[1]--;
        int* eredm[2];
        int eredmindex[2];
        bool hiba = false;
        for (int i = 0; i < 2; i++) {
            if (szam[i] == poz[0]) {
                eredm[i] = &x;
                eredmindex[i] = 0;
            } else if (szam[i] == poz[1]) {
                eredm[i] = &y;
                eredmindex[i] = 1;
            } else if (szam[i] == poz[2]) {
                eredm[i] = &z;
                eredmindex[i] = 2;
            } else if (szam[i] == poz[3]) {
                eredm[i] = &zs;
                eredmindex[i] = 3;
            } else if (szam[i] == poz[4]) {
                eredm[i] = &a;
                eredmindex[i] = 4;
            } else if (szam[i] == poz[5]) {
                eredm[i] = xp;
                eredmindex[i] = 5;
            } else if (szam[i] == poz[6]) {
                eredm[i] = yp;
                eredmindex[i] = 6;
            } else if (szam[i] == poz[7]) {
                eredm[i] = zp;
                eredmindex[i] = 7;
            } else if (szam[i] == poz[8]) {
                eredm[i] = zsp;
                eredmindex[i] = 8;
            } else if (szam[i] == poz[9]) {
                eredm[i] = ap;
                eredmindex[i] = 9;
            } else {
                cout << "Ezt mar felhasznaltad! Ujra!" << endl;
                hiba = true;
                break;
            }
        }
        if (hiba){
            continue;
        }

        if (eredm[0] == eredm[1]) {
            cout << "Talalt!" << endl;
            poz[eredmindex[0]] = -1;
            poz[eredmindex[1]] = -1;
            kartyak[szam[0]] = 1;
            kartyak[szam[1]] = 1;

        } else {
            cout << "Nem talalt!" << endl;
            cout << "Memoriacimek: " <<  eredm[0] << " | " << eredm[1] << endl;
        }

        int count = 0;
        for (int i : kartyak) {
            if (i == 1) {
                count += 1;
            }
        }


        if (count == 10) {
            break;
        }

    }
    cout << "Game Over!";
    return 0;
}