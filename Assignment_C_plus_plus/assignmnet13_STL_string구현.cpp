#include <iostream>
using namespace std;

class String // 문자열 데이터를 관리하고 조작하기 위한 클래스
{
private: //buffer(문자열 데이터), len(문자열 길이)
	char* buffer;
	int len;
public:  //생성자, 소멸자, 연산자 오버로딩, 문자열 조작 및 검색 메소드
	String(); //기본 생성자
	String(const char p[]); // 단일 생성자
	String(const String& right); // 복사생성자
	~String(); // 소멸자

	String& operator=(const String& right); // Assignment operator
	String& operator+=(const String& right);
	char& operator[](int index);
	char operator[](int index) const;
	ostream& outstr(ostream& sout) const;

	int length() const;
	void append(const String& s);
	void append(int n, char c);
	void append(const String& s, int pos, int n);
	void clear();
	int compare(const String& s) const;
	bool empty();
	void erase(int pos, int n);
	int find(char c) const;
	int find(const String& s) const;
	int find(const String& s, int pos) const;
	void replace(int pos, int n, const String &s);
	void insert(int pos, const String &s);
	void pop_back();
	void push_back(char c);
	void resize(int n);
	void resize(int n, char c);
	String substr(int pos);
	String substr(int pos, int n);
	char at(int pos) const;
};

String operator+(const String& left, const String& right);
String operator+(char left, const String& right);
ostream& operator<<(ostream& out, const String& str);

bool operator<(const String& left, const String& right);
bool operator<=(const String& left, const String& right);
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
bool operator>=(const String& left, const String& right);
bool operator>(const String& left, const String& right);

String::String()
{
	//cout << "Default Constructor Called\n";
	len = 0;
	buffer = new char[0]; // No need to allocate array to hold zero characters
}

String::String(const char p[])
{
	// Determine number of characters in string (strlen(p))
	//cout << "Char Array Constructor Called str=";
	len = 0;
	while(p[len] != '\0')
	{
		len++;
	}
	// Allocate buffer array, remember to make space for NULL character
	buffer = new char[len+1];
	// Copy new characters (strcpy( buffer, p ))
	for(int i=0; i<len; i++)
	{
		buffer[i] = p[i];
	}
	buffer[len] = '\0';
	//cout << *this << endl;
}

String::String(const String& right)
{
	//cout << "Copy Constructor Called str=";
	int n = right.length();
	len = n;
	buffer = new char[n + 1];
	for(int i=0; i<n; i++)
	{
		buffer[i] = right.buffer[i];
	}
	buffer[n] = '\0';
	//cout << *this << endl;
}

String& String::operator=(const String& right)
{
	//cout << "Assignment Oper. Called str=";
	if(this != &right)
	{
		delete[] buffer; // Get rid of old buffer
		len = right.length();
		buffer = new char[len + 1];
		for(int i=0; i<len; i++)
		{
			buffer[i] = right[i];
		}
		buffer[len] = '\0';
	}
	else
	{
		//cout << "assign op--same var assign \n";
	}
	//cout << *this << endl;
	return *this;
}

String::~String()
{
	//cout << "Destructor Called str=";
	//cout << *this << endl;
	delete[] buffer;
}

String& String::operator+=(const String& right)
{
	char* newbuf = new char[len+right.length()+1];
	for(int i=0; i<len; i++)
	{
		newbuf[i] = buffer[i];
	}
	for(int i=0; i<right.length(); i++)
	{
		newbuf[len+i] = right[i];
	}

	delete[] buffer; // Get rid of old buffer

	len += right.length();
	buffer = newbuf;
	buffer[len] = '\0';
	return *this;
}

int String::length() const
{
	return len;
}

void String::append(const String& s) {
    char* newBuffer = new char[len + s.len + 1];
    for (int i = 0; i < len; ++i) {
        newBuffer[i] = buffer[i];
    }
    for (int i = 0; i < s.len; ++i) {
        newBuffer[len + i] = s.buffer[i];
    }
    delete[] buffer;
    buffer = newBuffer;
    len += s.len;
    buffer[len] = '\0';
}


void String::append(int n, char c) {
    char* newBuffer = new char[len + n + 1];
    for (int i = 0; i < len; ++i) {
        newBuffer[i] = buffer[i];
    }
    for (int i = 0; i < n; ++i) {
        newBuffer[len + i] = c;
    }
    delete[] buffer;
    buffer = newBuffer;
    len += n;
    buffer[len] = '\0';
}


void String::append(const String& s, int pos, int n) {
    if (pos > s.len) return; // 범위를 벗어난 경우 아무것도 하지 않음

    int realN = (pos + n > s.len) ? (s.len - pos) : n; // 범위 초과 처리
    char* newBuffer = new char[len + realN + 1];
    for (int i = 0; i < len; ++i) {
        newBuffer[i] = buffer[i];
    }
    for (int i = 0; i < realN; ++i) {
        newBuffer[len + i] = s.buffer[pos + i];
    }
    delete[] buffer;
    buffer = newBuffer;
    len += realN;
    buffer[len] = '\0';
}


void String::clear() {
    delete[] buffer;
    buffer = new char[1];
    buffer[0] = '\0';
    len = 0;
}


int String::compare(const String& s) const {
    int minLength = len < s.len ? len : s.len;
    for (int i = 0; i < minLength; ++i) {
        if (buffer[i] != s.buffer[i]) {
            return buffer[i] - s.buffer[i];
        }
    }
    if (len == s.len) {
        return 0; // 두 문자열이 같음
    } else {
        return len < s.len ? -1 : 1; // 길이에 따라 결과 반환
    }
}


bool String::empty() {
    return len == 0;
}


void String::erase(int pos, int n) {
    if (pos >= len) return; // 시작 위치가 문자열 길이를 넘어가면 아무것도 하지 않음

    int realN = (pos + n > len) ? (len - pos) : n; // 범위 초과 처리
    char* newBuffer = new char[len - realN + 1];
    for (int i = 0; i < pos; ++i) {
        newBuffer[i] = buffer[i];
    }
    for (int i = pos + realN; i < len; ++i) {
        newBuffer[i - realN] = buffer[i];
    }
    delete[] buffer;
    buffer = newBuffer;
    len -= realN;
    buffer[len] = '\0';
}

int String::find(char c) const {
    for (int i = 0; i < len; ++i) {
        if (buffer[i] == c) return i;
    }
    return -1; // 찾지 못함
}


int String::find(const String& s) const {
    for (int i = 0; i <= len - s.len; ++i) {
        bool found = true;
        for (int j = 0; j < s.len; ++j) {
            if (buffer[i + j] != s.buffer[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1; // 찾지 못함
}


int String::find(const String& s, int pos) const {
    if (pos >= len) return -1; // 시작 위치가 문자열 길이를 넘어가면 찾지 못함

    for (int i = pos; i <= len - s.len; ++i) {
        bool found = true;
        for (int j = 0; j < s.len; ++j) {
            if (buffer[i + j] != s.buffer[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1; // 찾지 못함
}


void String::replace(int pos, int n, const String &s) {
    if (pos >= len) return; // 시작 위치가 문자열 길이를 넘어가면 아무것도 하지 않음

    int realN = (pos + n > len) ? (len - pos) : n; // 범위 초과 처리
    char* newBuffer = new char[len - realN + s.len + 1];

    for (int i = 0; i < pos; ++i) {
        newBuffer[i] = buffer[i];
    }
    for (int i = 0; i < s.len; ++i) {
        newBuffer[pos + i] = s.buffer[i];
    }
    for (int i = pos + realN; i < len; ++i) {
        newBuffer[i - realN + s.len] = buffer[i];
    }
    delete[] buffer;
    buffer = newBuffer;
    len = len - realN + s.len;
    buffer[len] = '\0';
}

void String::insert(int pos, const String &s) {
    if (pos >= len) {
        append(s);
        return;
    }

    char* newBuffer = new char[len + s.len + 1];
    for (int i = 0; i < pos; ++i) {
        newBuffer[i] = buffer[i];
    }
    for (int i = 0; i < s.len; ++i) {
        newBuffer[pos + i] = s.buffer[i];
    }
    for (int i = pos; i < len; ++i) {
        newBuffer[i + s.len] = buffer[i];
    }
    delete[] buffer;
    buffer = newBuffer;
    len += s.len;
    buffer[len] = '\0';
}


void String::pop_back() {
    if (len == 0) return;
    buffer[--len] = '\0';
}


void String::push_back(char c) {
    char* newBuffer = new char[len + 2];
    for (int i = 0; i < len; ++i) {
        newBuffer[i] = buffer[i];
    }
    newBuffer[len] = c;
    delete[] buffer;
    buffer = newBuffer;
    buffer[++len] = '\0';
}


void String::resize(int n) {
    if (n <= len) {
        buffer[n] = '\0';
        len = n;
    } else {
        char* newBuffer = new char[n + 1];
        for (int i = 0; i < len; ++i) {
            newBuffer[i] = buffer[i];
        }
        for (int i = len; i < n; ++i) {
            newBuffer[i] = '\0';
        }
        delete[] buffer;
        buffer = newBuffer;
        len = n;
    }
}


void String::resize(int n, char c)
{
    if (n <= len) {
        buffer[n] = '\0';
        len = n;
    } else {
        char* newBuffer = new char[n + 1];
        for (int i = 0; i < len; ++i) {
            newBuffer[i] = buffer[i];
        }
        for (int i = len; i < n; ++i) {
            newBuffer[i] = c;
        }
        delete[] buffer;
        buffer = newBuffer;
        len = n;
        buffer[len] = '\0';
    }
}
String String::substr(int pos)
{
    if (pos >= len) return String(""); // 범위를 벗어난 경우 빈 문자열 반환

    return substr(pos, len - pos);
}

String String::substr(int pos, int n)
{
    if (pos >= len) return String(""); // 범위를 벗어난 경우 빈 문자열 반환

    int realN = (pos + n > len) ? (len - pos) : n; // 범위 초과 처리
    char* subBuffer = new char[realN + 1];
    for (int i = 0; i < realN; ++i) {
        subBuffer[i] = buffer[pos + i];
    }
    subBuffer[realN] = '\0';
    String result(subBuffer);
    delete[] subBuffer;
    return result;
}

char String::at(int pos) const
{
    if (pos < 0 || pos >= len) throw std::out_of_range("Index out of range");
    return buffer[pos];
}

int stoi(const String& s)
{
    int num = 0;
    int sign = 1;
    int i = 0;

    // 공백 건너뛰기
    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') {
        i++;
    }

    // 부호 확인
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i++] == '-') ? -1 : 1;
    }

    // 숫자 변환
    while (s[i] >= '0' && s[i] <= '9') {
        num = num * 10 + (s[i++] - '0');
    }

    return num * sign;
}

char String::operator [](int i) const
{
	return buffer[i];
}

char& String::operator [](int i)
{
	return buffer[i];
}

ostream& String::outstr(ostream& sout) const
{
	for(int i=0; i<len; ++i)
	{
		sout << buffer[i];
	}
	return sout;
}

ostream& operator<<(ostream& sout, const String& s)
{
	return s.outstr(sout);
}

String operator+(const String& left, const String& right)
{
	String res = left;
	res+=right;
	return res;
}

String operator+(char left, const String& right)
{
	char* subbuf = new char[2];
	subbuf[0] = left;
	subbuf[1] = '\0';
	String res = String(subbuf);
	res+=right;
	return res;
}

int main()
{
	/* 아래 두 줄은 주석 해제 하면 바로 실행 됨(제출 시 다시 주석처리) */
	// String t = "hello";
	// cout << t << endl;
	
	/* 아래 줄들을 주석 해제 하여 본인이 구현한 함수에 대한 작동 테스트(제출 시 다시 주석처리) */
	// t.append('o', 5);
	// String a = "bamboo";
	// cout << t.compare(a) << endl;
	// cout << t.substr(3) << endl;
	// String b = "am";
	// cout << a.find(b) << endl;
	// String c = "12345";
	// int d = stoi(c);
	// cout << d << endl;
	// t.push_back('w');
	// cout << t << endl;
	// t.pop_back();
	// cout << t << endl;
	
	return 0;
}
/*
문제의 정의 :  문자열 데이터를 효율적으로 관리하고 조작하기 위한 사용자 정의 String 클래스를 구현합니다. 이 클래스는 문자열의 생성, 복사, 할당, 소멸을 처리하며, 문자열의 길이 측정, 추가, 삭제, 검색, 비교, 대체, 삽입 등 다양한 문자열 관련 작업을 수행합니다.

문제의 해결 방안 : String 클래스에는 문자열 데이터를 저장하기 위한 동적 배열 buffer와 문자열 길이를 저장하는 len 변수가 있습니다.

append, insert, erase 등 문자열을 조작하는 메소드.
find, compare, substr 등 문자열을 검색하고 비교하는 메소드.
resize, clear, empty 등 문자열의 크기와 내용을 관리하는 메소드.

메모리 할당 실패나 잘못된 인덱스 접근 등에 대한 예외 처리를 포함합니다.
*/