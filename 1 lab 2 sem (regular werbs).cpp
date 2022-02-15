#include <iostream>
#include <regex>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int input;
    ofstream ofile("output.txt", ios_base::trunc);
    ifstream ifile;
    string textOfFile, text;
    string nameOfFile;
    do {
        cout << "Введите название файла, с его расширением. (Например : test.txt)" << endl;
        getline(cin, nameOfFile);
        ifile.open(nameOfFile);
        if (!ifile) {
            cout << "Неверное имя файла." << endl;
            system("pause");
            system("cls");
        }
    } while (!ifile);
    cin >> input;
    string forRegex = "((0|1[0-9]{0,2}|2[0-5]{0,2}).){3}";
    if (input == 2) {
        forRegex = forRegex + "2[0-5]{0,2}";
    }
    else if (input == 0) {
        forRegex = forRegex + "0";
    }
    else if (input == 1) {
        forRegex = forRegex + "1[0-9]{0,2}";
    }
    regex rx(forRegex);
    while (!ifile.eof()) {
        getline(ifile, textOfFile);
        for (int i = 0; i < textOfFile.size(); i++) {
            if (textOfFile[i] == ' ') {
                if (regex_match(text, rx)) {
                    text.clear();
                    continue;
                }
                ofile << text;
                ofile << ' ';
                text.clear();
                continue;
            }
            else if (i == textOfFile.size() - 1) {
                text += textOfFile[i];
                if (regex_match(text, rx)) {
                    text.clear();
                    ofile << text;
                    text.clear();
                    continue;
                }
                ofile << text;
                ofile << ' ';
                text.clear();
                continue;
            }
            text += textOfFile[i];
        }
        ofile << endl;
    }
}

