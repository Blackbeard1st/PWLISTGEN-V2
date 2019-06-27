// Author Blackbeard1st //
// PWLISTGEN V2 Blackbeards Password List Generator for Pentesting/PW-cracking do what you want :)
// Choose your length 0 - inf. I recommend 8-16 should be enough.
// Characterset has all what you need in it.

//Update 27.06.2019:
//More options in filesize. (now -> 20MB,200MB,1GB,2GB,5GB,10GB,20GB) 
//characters are now more real.
//percent prozess will show now more accurate.
//the list will be generated in the folder where the program is started from

//should now work on Windows,Mac and Linux :)

//how to use?
//Terminal command:
//.  c++ PWLISTGEN_NEW.cpp -o PWLISTGEN
//.  ./PWLISTGEN

//have fun!


#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
using namespace std;

string RandomString (int len, string str)
{

    string newstr;
    int pos;
    while(newstr.size() != len) {
        pos = (int) ((rand() % (str.size() - 1)));
        newstr += str.substr((unsigned long) pos, 1);
    }

    return newstr;
}

int main() {


    cout << "How long do you want your character length?\n";
    int length;
    cin >> length;

    string buffer;

    int imax;
    cout << "\nHow many Passwords do you want to generate?\n(Depends on your System Memory (RAM) Based on 16 character length)\n\n";
    cout << "1: Million max.20MB\n";
    cout << "2: 10 Million = max.200MB\n";
    cout << "3: 50 Million = max.1GB\n";
    cout << "4: 100 Million = max.2GB\n";
    cout << "5: 250 Million = max.5GB\n";
    cout << "6: 500 Million = max.10GB\n";
    cout << "7: -> 1 Billion = max.20GB\n";
    cout << "\nSelect: 1-4:";
    int choose1;
    cin >> choose1;
    switch (choose1){
        case 1:     imax = 1000000;
            break;
        case 2:     imax = 10000000;
            break;
        case 3:     imax = 50000000;
            break;
        case 4:     imax = 100000000;
            break;
        case 5:     imax = 250000000;
            break;
        case 6:     imax = 500000000;
            break;
        case 7:     imax = 1000000000;
            break;
        default:
            break;
    }

    cout << "\nGenerate " << imax << " lines for...\n\n";

    cout << "Choose your Characterset 1-10: \n";
    cout << "\n1: 0123456789 ";
    cout << "\n2: abcdefghijklmnopqrstuvwxyz ";
    cout << "\n3: ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    cout << "\n4: 0123456789abcdefghijklmnopqrstuvwxyz ";
    cout << "\n5: 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    cout << "\n6: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    cout << "\n7: 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    cout << "\n8: 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!$%&=?@+*-_" << endl;
    cout << "=> ";
    string charset;
    int choose;
    cin >> choose;
    switch (choose) {
        case 1:
            charset = "0123456789";
            break;
        case 2:
            charset = "abcdefghijklmnopqrstuvwxyz";
            break;
        case 3:
            charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 4:
            charset = "0123456789abcdefghijklmnopqrstuvwxyz";
            break;
        case 5:
            charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 6:
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 7:
            charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 8:
            charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!$%&=?@+*-_";
            break;
    }

    // count of how many different lines //
    for (int i = 0; i <= imax; i++) {

        if (i == imax * 0.1) {
            cout << "10%...\n";
        } else if (i == imax * 0.2) {
            cout << "20%...\n";
        } else if (i == imax * 0.3) {
            cout << "30%...\n";
        } else if (i == imax * 0.4) {
            cout << "40%...\n";
        } else if (i == imax * 0.5) {
            cout << "50%...\n";
        } else if (i == imax * 0.6) {
            cout << "60%...\n";
        } else if (i == imax * 0.7) {
            cout << "70%...\n";
        } else if (i == imax * 0.8) {
            cout << "80%...\n";
        } else if (i == imax * 0.9) {
            cout << "90%...\n";
        } else if (i == imax) {
            cout << "100%...\n";
        }


        // length of string per line //
        string random_str = RandomString(length, charset);

        // show random string //
        // cout << random_str << endl; //
        // append random string for every line //
        buffer += random_str += "\n";
    }
    // open txt file //
    cout << "\nWrite into txt file...\n";

    ofstream passlist;
    passlist.open("mypwlist.txt");
    passlist << buffer;
    passlist.close();

    cout << "done ツ \n";

    return 0;
}
