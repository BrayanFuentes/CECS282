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
	BigInt operator-(BigInt n);
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
	/*
	BigInt B1("123456789123456789123456789123456789");
	BigInt B2(B1);
	BigInt MAX(INT_MAX);
	cout << "B1:" << B1 << "\nB2:" << B2 << "\nMAX:" << MAX << endl;
	cout << "\nB1:";
	B1.print();
	cout << endl;
	*/
	BigInt n(999),x(165);
	BigInt b = n  - x; 
	cout << b << endl;
	for (BigInt i = 0; i <= 20; i++)
	{
		cout << i << endl;
	}
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
	BigInt x(m);
	*this = *this - x;
	return *this;
}


BigInt BigInt:: operator-(BigInt n)
{
	BigInt temp(*this);
	while (n.num.size() != temp.num.size()) {
		if (n.num.size() > temp.num.size())
		{
			temp.num.push_back(0);
		}
		else {
			n.num.push_back(0);
		}
	}
	for (int i = 0; i < temp.num.size(); i++) 
	{
		if (temp.num[i] < n.num[i]) 
		{
			temp.num[i];
			temp.num[i + 1] -= 1;
			temp.num[i] -= n.num[i];
		}
		else
		{
			temp.num[i] -= n.num[i];
		}

		if (temp.num[i] == 0 && n.num[i] == 0 && i == temp.num.size() - 1) 
		{
			temp.num.erase(temp.num.end() - 1);
		}
	}
	return temp;
}


bool BigInt::operator==(int n)
{
	BigInt x(n);
	BigInt y(n);
	if (y == x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BigInt :: operator==(const BigInt& n) const
{
	if (this->num.size() == n.num.size())
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
	else
	{
		return false;
	}
}

bool BigInt:: operator<(const BigInt& n) const
{
	BigInt x(*this);
	if (x.num.size() < n.num.size())
	{
		return true;
	}
	else if (x.num.size() > n.num.size())
	{
		return false;
	}
	else if(x.num.size() == n.num.size())
	{
		for (int i = num.size() - 1; i > -1; i--) {
			if ((int)x.num[i] > (int)n.num[i]) 
			{
				return false;
			}
			else if ((int)x.num[i] < (int)n.num[i]) 
			{
				return true;
			}
		}
	}
}
bool BigInt ::  operator <= (BigInt n)
{
	bool b = true;
	BigInt x(*this);

	if (x == n || x.num.size() < n.num.size())
	{
		return true;
	}
	else if (x.num.size() > n.num.size())
	{
		return false;
	}
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

