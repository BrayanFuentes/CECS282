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
	BigInt operator-(BigInt n)const;
	BigInt operator+(BigInt n)const;
	BigInt operator+(int n);
	bool operator ==(int n);
	bool operator==(const BigInt& n) const;
	bool operator<(const BigInt& n) const;
	bool operator <= (int n);
	bool operator <= (BigInt n);
	BigInt operator ++(int);
	friend ostream& operator<< (ostream&stream,  BigInt n);
	

};

int goldRabbits(int n)
{
	{

		if (n == 0 || n == 1) // base case

			return 1;

		else

			return goldRabbits(n - 1) + goldRabbits(n - 2); // general case

	}
}

BigInt goldRabbits(BigInt n )
{
	if (n == 0 || n == 1) // base case

		return 1;

	else

		return goldRabbits(n - 1) + goldRabbits(n - 2); // general case
}

void pause() 
{ 
	cout << "Press Enter to continue...";
	getchar(); 
}

int main()
{
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);
	BigInt MAX(INT_MAX);
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;
	cout << "\nB1:";
	B1.print();
	cout << endl;

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

BigInt BigInt:: operator-(int m)
{
	BigInt result(*this);
	BigInt n(m);
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

	for (int i = 0; i < result.num.size(); i++)
	{
		int t = (int)result.num[i];
		if (result.num[i] < n.num[i])
		{
			result.num[i] += 10;
			result.num[i + 1] -= 1;
			int sub = result.num[i] - n.num[i];
			s.insert(0, to_string(sub));
		}
		else if (i = result.num.size() - 1)
		{
			if (result.num[i] == 0 && n.num[i] == 0)
			{
				break;
			}
			else
			{
				int sub = result.num[i] - n.num[i];
				s.insert(0, to_string(sub));
			}
		}
		else
		{
			int sub = result.num[i] - n.num[i];
			s.insert(0, to_string(sub));
		}
	}
	return BigInt(s);
}


BigInt BigInt:: operator-(BigInt n)const
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

	for (int i = 0; i < result.num.size(); i++)
	{
		int t = (int)result.num[i];
		if (result.num[i] < n.num[i])
		{
			result.num[i] += 10;
			result.num[i + 1] -= 1;
			int sub = result.num[i]-n.num[i];
			s.insert(0, to_string(sub));
		}
		else if (i = result.num.size() - 1)
		{
			if (result.num[i] == 0 && n.num[i] ==0)
			{
				break;
			}
			else
			{
				int sub = result.num[i] - n.num[i];
				s.insert(0, to_string(sub));
			}
		}
		else
		{
			int sub = result.num[i] - n.num[i];
			s.insert(0, to_string(sub));
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

bool BigInt :: operator==(const BigInt& n) const
{
	if (this->num.size() > n.num.size())
	{
		return false;
	}
	else if (this->num.size() < n.num.size())
	{
		return false;
	}
	else if (this->num.size() == n.num.size())
	{
		for (int i = 0; i < n.num.size(); i++)
		{
			if (num[i] != n.num[i])
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
	BigInt x(*this);
	bool t = true;
	if(x == n)
	{
		t=   false;
	}
	else if (x.num.size() > n.num.size())
	{
		t= false;
	}
	else if (x.num.size() < n.num.size())
	{
		t= true;
	}
	else
	{
		for (int i = num.size() - 1; i > -1; i--)
		{
			if (x.num[i] > n.num[i])
			{
				t= false;
			}
			else if(x.num[i] < n.num[i])
			{
				t = true;
			}
		}
	}
	return t;
}

bool BigInt ::  operator <= (BigInt n)
{
	bool b = true;
	BigInt x(*this);

	if (x == n)
	{
		b = true;
	}
	else if (x.num.size() > n.num.size())
	{
		b = false;
	}
	else if (x.num.size() < n.num.size())
	{
		b = true;
	}
	else
	{
		for (int i = num.size() - 1; i > -1; i--)
		{
			if (x.num[i] > n.num[i])
			{
				b = false;
			}
			else if (x.num[i] < n.num[i])
			{
				b = true;
			}
		}
	}
	return b;
}

bool BigInt:: operator <= (int n)
{
	BigInt x(*this);
	BigInt y(n);
	if (x <= y)
	{
		return true;
	}
	else
	{
		return false;
	}
}


BigInt BigInt :: operator ++(int)
{
	return *this = *this + 1;
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

