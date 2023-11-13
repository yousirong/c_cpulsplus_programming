#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const int Entry_max = 100;

vector<string> n_d = {"Park SH", "Kang JH", "Kim KS", "Lee YH", "Kang SH", "Bae JM", "Lee DI", "Lee BH", "Jang WH", "Chun WY"};
vector<int> num_d = {5023, 5002, 5008, 5067, 5038, 5381, 5125, 5165, 5684, 5752};
vector<string> e_d = {"parksh@email.com", "kangjh@email.com", "kimks@email.com", "leeyh@email.com", "kangsh@email.com", "baejm@email.com", "leedi@email.com", "leebh@email.com", "jangwh@email.com", "chunwy@email.com"};

class Val_I
{
public:
    int p_n;
    string e_add;
    Val_I() : p_n(-99) {}
    Val_I(int n, string em) : p_n(n), e_add(em) {}
};

class Entry
{
public:
    string p_name;
    Val_I val_i;
    Entry() : p_name(""), val_i(-1, "") {}
    Entry(string s, int n, string em) : p_name(s), val_i(n, em) {}
};

vector<Entry> vectorPhoneBook;

void insert(string name, int number, string email);
void remove(string name);
void update(string name, int number, string email);
void update(string name, int number);
void update(string name, string email);

int findp_n(string name);
string finde_add(string name);
string f_Name(int number);
string f_Name(string email);

int findLoc(string name)
{ // 항목의 색인을 찾는 도우미 기능
    for (auto i = 0u; i < vectorPhoneBook.size(); ++i)
    {
        if (vectorPhoneBook[i].p_name == name)
            return i;
    }
    return -1;
}

Val_I find(string name)
{ // Val_I특정 이름의 를 검색
    int loc = findLoc(name);
    if (loc == -1)
        return Val_I();
    return vectorPhoneBook[loc].val_i;
}

int findp_n(string name) // 연락처를 검색하는 검색 기능
{
    int loc = findLoc(name);
    if (loc == -1)
        return -1;
    return vectorPhoneBook[loc].val_i.p_n;
}

string finde_add(string name) // 연락처를 검색하는 검색 기능
{
    int loc = findLoc(name);
    if (loc == -1)
        return "";
    return vectorPhoneBook[loc].val_i.e_add;
}

string f_Name(int number)
{ // 연락처를 검색하는 검색 기능
    for (const auto &entry : vectorPhoneBook)
    {
        if (entry.val_i.p_n == number)
            return entry.p_name;
    }
    return "";
}

string f_Name(string email)
{
    for (const auto &entry : vectorPhoneBook)
    {
        if (entry.val_i.e_add == email)
            return entry.p_name;
    }
    return "";
}

void insert(string name, int number, string email)
{
    int loc = findLoc(name);
    if (loc == -1)
    {
        if (vectorPhoneBook.size() >= Entry_max)
        {
            cout << "***Error -- PhoneBook Overflow" << endl;
        }
        else
        {
            vectorPhoneBook.push_back(Entry(name, number, email));
        }
    }
    else
    {
        cout << "***Error -- Duplicated Name" << endl;
    }
}

void remove(string name)
{ // 이름을 기준으로 연락처를 삭제
    int loc = findLoc(name);
    if (loc != -1)
    {
        vectorPhoneBook.erase(vectorPhoneBook.begin() + loc);
    }
    else
    {
        cout << "***Error -- Name not found" << endl;
    }
}

void update(string name, int number, string email)
{ // 기존 연락처 정보를 수정
    int loc = findLoc(name);
    if (loc != -1)
    {
        vectorPhoneBook[loc].val_i.p_n = number;
        vectorPhoneBook[loc].val_i.e_add = email;
    }
    else
    {
        cout << "***Error -- Name not found" << endl;
    }
}

void update(string name, int number)
{
    int loc = findLoc(name);
    if (loc != -1)
    {
        vectorPhoneBook[loc].val_i.p_n = number;
    }
    else
    {
        cout << "***Error -- Name not found" << endl;
    }
}
void update(string name, string email)
{
    int loc = findLoc(name);
    if (loc != -1)
    {
        vectorPhoneBook[loc].val_i.e_add = email;
    }
    else
    {
        cout << "***Error -- Name not found" << endl;
    }
}

void listAll()
{ // 모든 연락처를 나열
    cout << left << setw(15) << "Name" << setw(10) << "Number"
         << "Email" << endl;
    for (auto i = 0u; i < vectorPhoneBook.size(); ++i)
    {
        cout << left << setw(15) << vectorPhoneBook[i].p_name
             << setw(10) << vectorPhoneBook[i].val_i.p_n
             << vectorPhoneBook[i].val_i.e_add << endl;
    }
}

int main()
{
    int incount = 10;
    for (int i = 0; i < incount; ++i)
    {
        insert(n_d[i], num_d[i], e_d[i]);
    }
    cout << "List All Inserted Entry" << endl;
    listAll();

    remove("Kim KS");
    insert("Kim CS", 5555, "kimcs@email.com");
    update("Kang JH", 5999);
    cout << "Find Phone Number By Name -- Kim CS	" << find("Kim CS").p_n << endl;
    cout << "Find Email Address By Name -- Kim CS	" << find("Kim CS").e_add << endl;

    cout << endl;
    cout << "List All Updated Entry" << endl;
    listAll();

    // cout << endl;
    // cout << "key-not-found(없는 키): " << endl;
    // cout << "입력한 이름이 없는 경우: ";
    // remove("park");
    // update("park", 4052, "park@email.com");
    // cout << endl;

    // cout << "duplicated -key(키 중복되면 안됨): " << endl;
    // cout << "중복된 이름: ";
    // insert("Park SH", 2334, "12334@email.com");
    // cout << "중복된 전화번호: ";
    // insert("Leo Park", 5023, "leopark@email.com");
    // cout << "중복된 이메일: ";
    // insert("Leo Park", 2334, "parksh@email.com");
    // cout << endl;

    return 0;
}
/*
문제의 정의 : 전화번호부 데이터베이스를 관리하도록 설계되었습니다. 연락처 세부 정보 삽입, 제거, 업데이트 및 찾기와 같은 작업이 가능합니다. 해결된 문제는 쉽게 액세스하고 수정할 수 있는 방식으로 연락처 정보 모음을 구성하고 조작하는 것입니다.

문제의 해결 방안 :
Entry클래스는 개별 연락처 항목을 저장함
Val_I클래스는 전화번호와 이메일 주소를 보유함
vector명명된 항목은 vectorPhoneBook모든 항목을 나타냄


insert: 전화번호부에 새 연락처를 추가합니다.
remove: 이름을 기준으로 연락처를 삭제합니다.
update: 기존 연락처 정보를 수정합니다.
findp_n, finde_add, f_Name: 연락처를 검색하는 검색 기능입니다.
listAll: 모든 연락처를 나열합니다.
findLoc: 항목의 색인을 찾는 도우미 기능입니다.
find: Val_I특정 이름의 를 검색합니다.

삽입하는 동안 중복된 항목이 있는지 확인합니다.
최대 연락처 항목을 초과하지 않도록 합니다.
업데이트 또는 제거 중에 연락처를 찾을 수 없는 경우를 처리합니다.
*/
