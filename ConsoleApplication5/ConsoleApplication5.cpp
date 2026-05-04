#include <iostream>
#include <cstring>
using namespace std;


int main() {
    setlocale(LC_ALL, "rus");
    cout<< "Введите последовательность до 30"<<endl;
    string s;
    cin >> s; 

    int L = s.length();
    if (L >= 30) {
        cout << "длина последовательности должна быть меньше 30" << endl;
        return 1;

        }
    for (int i = 0; i < L; ++i) {
        if (s[i] != '0' && s[i] != '1') {
            cout << "ошибка последовательность должна состоять только из 0 и 1" << endl;
            return 1;
            }
        }

    
    int D[30];   
    int R[30];
    cout << "шифруем" << endl;
    D[0] = s[0]- '0';

    for (int i = 1; i < L; ++i){
        if (s[i] == s[i - 1]) {
            D[i] = 1;
        }
        else {
            D[i] = 0;
        }
    }
    for (int i = 0; i < L; ++i){
        cout << D[i];        
        }

    cout<<"\n";

    cout << "расшифруем" << endl;


    R[0] = D[0];
    for (int i = 1; i < L;++i) {
        if (D[i] == 1) {
            R[i] = R[i-1];
        }
        else {
            R[i] = 1- R[i-1];
        }
    }
    for (int i = 0; i < L; ++i) {
        cout << R[i];
    }
        
    cout << "\n";


    cin.ignore();

    cout << "Введите две строки: " << endl;


    char proto_stroka_nomer1[1000],proto_stroka_nomer2[1000];

    gets_s(proto_stroka_nomer1,1000);
    gets_s(proto_stroka_nomer2,1000);
    
    string stroka1 = proto_stroka_nomer1;
    string stroka2 = " " + string(proto_stroka_nomer2) + " ";

    string word;
    for (int i = 0; i <= stroka1.length(); i++) {

        if (i < stroka1.length() && stroka1[i] != ' ') {
            word += stroka1[i];
        }
        else {
            if (!word.empty()) {

                string temp = " " + word + " ";

                if (stroka2.find(temp) == -1)
                    cout << word << " ";

                word.clear();
            }
        }
    }
    
}
