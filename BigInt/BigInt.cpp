#include <vector>
#include <iostream>
#include <string>
using namespace std;

class BigInt
{
private:
	vector<char> num;
public:
	BigInt(string s);
	BigInt(int n);
	void print();
	BigInt operator-(int n );
	BigInt operator+(BigInt n)const;
	BigInt operator+(int n);
	bool operator ==(int n);
	bool operator<(const BigInt& n) const;
	bool operator <= (int n);
	bool operator <= (BigInt n);
	BigInt operator ++(int);
	friend ostream& operator<< (ostream&stream,  BigInt n);
	

};


int main()
{
	BigInt B(213);
	BigInt B1("1234567891234567891234567891234567893242342");
	BigInt B2(1351);
	BigInt B3 = B + B2;
	cout << B3 << endl;
	B = B + 6;
	cout << B << endl;
	

}

BigInt::BigInt(string s)
{
	for (int i = s.length() - 1; i >= 0; i--)
	{
		num.push_back(s[i] - 48);
	}
}

 BigInt :: BigInt(int n)
{
	while (n > 9)
	{
		int digit = n % 10;
		num.push_back(digit);
		n = n / 10;
	}
	num.push_back(n);
}

void BigInt::print()
{
	vector<char> ::reverse_iterator rit;
	for (rit = num.rbegin(); rit != num.rend(); rit++)
	{
		cout << (int)*rit;
	}
	cout << endl;
}

BigInt BigInt :: operator+(int n)
{
	BigInt N(n);
	BigInt T(*this);
	BigInt fin = N + T;
	return fin;
}

BigInt BigInt::operator+(BigInt n) const
{
	BigInt result(*this);
	
	while (n.num.size() != result.num.size()) {
		if (n.num.size() > result.num.size())
		{
			result.num.push_back(0);
		}
		else {
			n.num.push_back(0);
		}
	}
	string s; 
	char carry = 0;
	
	for (int i = 0;i < result.num.size(); i++)
	{
		int sum = n.num[i] + result.num[i];
		if (sum > 9)
		{
			int digit = sum % 10;
			s.insert(0, to_string(digit));
			if (i == result.num.size() - 1)
			{
				s.insert(0, to_string(1));
			}
			else
			{
				result.num[i + 1] += 1;
			}
		}
		else if (sum < 10)
		{
			s.insert(0, to_string(sum));
		}
	}
	return BigInt(s);
}

bool BigInt::operator==(int n)
{
	BigInt other(n);
	if (this->num.size() > other.num.size())
	{
		return false;
	}
	else if (this->num.size() < other.num.size())
	{
		return false;
	}
	else if (this->num.size() == other.num.size())
	{
		for (int i = 0; i < other.num.size(); i++)
		{
			if (num[i] != other.num[i])
			{
				return false;
				break;
			}
			else
			{
				return true;
			}
		}
		
	}
}
bool BigInt:: operator<(const BigInt& n) const
{

}

ostream& operator<< (ostream& stream,  BigInt n)
{
	vector<char> ::reverse_iterator rit;
	for (rit = n.num.rbegin(); rit != n.num.rend(); rit++)
	{
		stream << (int)*rit;
	}
	return stream;

}
