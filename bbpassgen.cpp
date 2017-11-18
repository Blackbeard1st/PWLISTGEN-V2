// Author Blackbeard1st //
// bbpassgen V1 (Blackbeard's random password generator) //
// Choose Your length 1 - inf. ( choose 8 or 16 :D for WPA/WPA2)
/* Choose how many lines you want for example a character length of 16 with
    1 Million lines = 17 MB
    10 Million = 170 MB
    100 Million = 1.7 GB
    200 Million = 3.4 GB
    300 Million = 5.1 GB
    400 Million = 6.8 GB
    500 Million = 8.5 GB
    600 Million = 10.2 GB
*/

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


    cout << "\nHow long do you want your character length? \n(recommended 16 for WPA2) \n\n => ";
    int length;
    cin >> length;

    string buffer;

    int imax = 0;
    cout << "\nChoose your size for 16 length, if you picked 8 length it's half the size!\n\n";
    cout << "1: 1 Million = 17 MB\n2: 10 Million = 170 MB\n3: 100 Million = 1.7 GB\n4: 200 Million = 3.4 GB\n";
    cout << "5: 300 Million = 5.1 GB\n6: 400 Million = 6.8 GB\n7: 500 Million = 8.5 GB\n8: 600 Million = 10.2 GB\n";
    cout << "\nChoose from 1-8: => ";
    int choose1;
    cin >> choose1;
    switch (choose1){
        case 1:     imax = 1000000;
            break;
        case 2:     imax = 10000000;
            break;
        case 3:     imax = 100000000;
            break;
        case 4:     imax = 200000000;
            break;
        case 5:     imax = 300000000;
            break;
        case 6:     imax = 400000000;
            break;
        case 7:     imax = 500000000;
            break;
        case 8:     imax = 600000000;
            break;
        default:
            break;
    }

    cout << "\nGenerate " << imax << " lines for...\n\n";

    cout << "Choose your Characterset: \n";
    cout << "\n1:  0123456789\n2:  abcdefghijklmnopqrstuvwxyz";
    cout << "\n3:  ABCDEFGHIJKLMNOPQRSTUVWXYZ\n4:  !§$%&/()=?@+-*<>-_";
    cout << "\n5:  0123456789 abcdefghijklmnopqrstuvwxyz\n6:  0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "\n7:  0123456789 !§$%&/()=?@+-*<>-_\n8:  abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "\n9:  0123456789 abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "\n10: 0123456789 abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ !§$%&/()=?@+-*<>-_\n" << endl;
    cout << "\nChoose from 1-10: => ";
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
            charset = "!§$%&/()=?@+-*<>-_";
            break;
        case 5:
            charset = "0123456789abcdefghijklmnopqrstuvwxyz";
            break;
        case 6:
            charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 7:
            charset = "0123456789!§$%&/()=?@+-*<>-_";
            break;
        case 8:
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 9:
            charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 10:
            charset = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!§$%&/()=?@+-*<>-_";
            break;
    }

    string path;
    cout << "\nChoose a path to create the txt file: \nexample => /root/file.txt or /Users/name/file.txt\n\n => ";
    cin >> path;
    cout << "\nGenerating...\n";
    // count of how many different lines //
    for (int i = 0; i <= imax; i++) {

        if (i == imax*0.1) {
            cout << "10%...\n";
        } else if (i == imax*0.2) {
            cout << "20%...\n";
        } else if (i == imax*0.3) {
            cout << "30%...\n";
        } else if (i == imax*0.4) {
            cout << "40%...\n";
        } else if (i == imax*0.5) {
            cout << "50%...\n";
        } else if (i == imax*0.6) {
            cout << "60%...\n";
        } else if (i == imax*0.7) {
            cout << "70%...\n";
        } else if (i == imax*0.8) {
            cout << "80%...\n";
        } else if (i == imax*0.9) {
            cout << "90%...\n";
        } else if (i == imax) {
            cout << "100%\n";
        }


        // length of string per line //
        string random_str = RandomString(length, charset);

        // show random string //
        // cout << random_str << endl; //
        // append random string for every line //
        buffer += random_str += "\n";
    }

    cout << "\nCopy to file => " << path << "...\n";
    // create or overwrite txt file //
    ofstream passlist;
    passlist.open(path);

    // show buffer //
    // cout << "buffer: " << endl << buffer; //
    passlist << buffer;
    passlist.close();

    cout << "...done ツ \n";
    cout << "closed\n";
    return 0;
}
