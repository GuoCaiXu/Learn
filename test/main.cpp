# include <iostream>
# include <string>

using namespace std;

int main(){

    string name = "3519610554", temp_name;
    string keys = "1234", temp_keys;

    while(1){
        cout << "ÇëÊäÈëÄãµÄÕËºÅ:";
        cin >> temp_name;
        cout << "ÇëÊäÈëÄãµÄÃÜÂë£º";
        cin >> temp_keys;
        if (temp_name == name && temp_keys == keys){
            system("cls");
            cout << "µÇÂ¼³É¹¦!" << endl;
            break;
        }
        else{
            system("cls");
            cout << "ÃÜÂë»òÕËºÅ´íÎóÇëÖØÐÂÊäÈë!" << endl;
        }
        system("pause");
        system("cls");
    }
    return 0;
}