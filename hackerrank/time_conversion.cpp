/*
Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: 
- 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example

s = "12:01:00PM"
Return '12:01:00'.

s = "12:01:00AM"
Return '00:01:00'
*/

#include <bits/stdc++.h>

using namespace std;

string timeConversion(string s) {
    string temp = "";
    int hours = 0;
    hours += (s[0] - '0')*10;
    hours += s[1] - '0';
    if (s[8] == 'A') 
    {
        if (hours == 12) temp += "00";
        else if (hours >= 10) temp += to_string(hours);
        else temp += '0' + to_string(hours);
        for (int i = 2; i < 8; i++)
            temp += s[i];
    }
    else
    {
        hours += 12;
        if (hours == 24) hours = 12;
        temp += to_string(hours);
        for (int i = 2; i < 8; i++)
            temp += s[i];
    }
    return temp;
}

int main()
{
    string s;
    getline(cin, s);
    string result = timeConversion(s);
    cout << result << endl;

    return 0;
}