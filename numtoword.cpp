#include <iostream>
using namespace std;

string one[] = { "", "one ", "two ", "three ", "four ",
				"five ", "six ", "seven ", "eight ",
				"nine ", "ten ", "eleven ", "twelve ",
				"thirteen ", "fourteen ", "fifteen ",
				"sixteen ", "seventeen ", "eighteen ",
				"nineteen " };

string ten[] = { "", "", "twenty", "thirty", "forty",
	        	"fifty", "sixty", "seventy", "eighty",
				"ninety" };

string numToWords(int n, string s)
{
	string str = "";
	if (n > 19)	str += ten[n / 10] + "-" + one[n % 10];
	else str += one[n];

	if (n) str += s;

	return str;
}

string convertToWords(long long n)
{
	string out;

    if (n < 0) 
    {
        out += "negative ";
        n = -n;
    }
	out += numToWords((n / 100000000), "hundred ");

    out += numToWords(((n / 1000000) % 100), "million ");

	out += numToWords(((n / 100000) % 10), "hundred ");

	out += numToWords(((n / 1000) % 100), "thousand ");

	out += numToWords(((n / 100) % 10), "hundred ");

	out += numToWords((n % 100), "");

	if (out=="")
	out = "zero";

	return out;
}

// Driver code
int main()
{
	long long int n;
    cin >> n;

	cout << convertToWords(n) << endl;

	return 0;
}