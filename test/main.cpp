# include <iostream>
# include <string>

using namespace std;

int main(){

    string name = "3519610554", temp_name;
    string keys = "1234", temp_keys;

    while(1){
        cout << "����������˺�:";
        cin >> temp_name;
        cout << "������������룺";
        cin >> temp_keys;
        if (temp_name == name && temp_keys == keys){
            system("cls");
            cout << "��¼�ɹ�!" << endl;
            break;
        }
        else{
            system("cls");
            cout << "������˺Ŵ�������������!" << endl;
        }
        system("pause");
        system("cls");
    }
    return 0;
}