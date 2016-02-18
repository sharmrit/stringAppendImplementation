#include<iostream>

#include <cstring>
using namespace std;

class String
{
public:
	String()      { m_str = new char[1]; *m_str = 0; }
	~String();
	String& operator+= (const String& other);

	void setString( char* a){ m_str = a; }; 
	char* getString(){ return m_str; };

private:
	char* m_str;
};



String& String::operator+=(const String & other)
{
	char *temp = new char[strlen(m_str) + strlen(other.m_str) + 1]; // declare enough space to append the string
	strcpy(temp, m_str); 
	strcat(temp, other.m_str);
	m_str = temp;
	return *this;
}

String::~String()
{
	if (!m_str)
	{
		delete(m_str);
	}
}

int main()
{
	String myString;
	String stringtoAdd;
	char* a = "abc";
	char* d = "def";
	myString.setString(a);
	stringtoAdd.setString(d);
	myString += stringtoAdd;
	cout << myString.getString()<<endl;
	return 0;
}