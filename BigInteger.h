#include <bits/stdc++.h>
using namespace std;

#define big_abs bigint::_big_abs
#define big_max bigint::_big_max
#define big_min bigint::_big_min
#define big_pow bigint::_big_pow
#define big_sqrt bigint::_big_sqrt
#define big_swap bigint::_big_swap
#define big_reverse bigint::_big_reverse
#define big_gcd bigint::_big_gcd
#define big_lcm bigint::_big_lcm
#define big_fact bigint::_big_fact
#define to_bigint bigint::_to_bigint

class bigint
{
private:
    string str;
    static string add(string, string);
    static string trim(string);
    static string subtract(string, string);
    static string multiply(string, string);
    static string shortDivide(string);
    static string divide(string, string);
    static string mod(string, string);
    static string maximum(string, string);
    static bool is_maximum(string, string);
    static bool is_strictly_maximum(string, string);
    static string minimum(string, string);
    static bool is_minimum(string, string);
    static bool is_strictly_minimum(string, string);
    static bool is_bigint(string);
    static bool is_equal(string, string);

    static string abs(string);
    static string pow(string, string);
    static string sqrt(string);
    static void swap(string &, string &);
    static string reverse(string);
    static string gcd(string, string);
    static string lcm(string, string);
    static string fact(string);

public:
    bigint()
    {
        str = "0";
    }
    bigint(string input)
    {
        str = input;
    }
    bigint(long long int input)
    {
        str = to_string(input);
    }
    bigint(const bigint &input)
    {
        str = input.str;
    }

    friend ostream &operator<<(ostream &stream, const bigint &val)
    {
        stream << val.str;
        return stream;
    }
    friend istream &operator>>(istream &stream, bigint &val)
    {
        stream >> val.str;
        return stream;
    }

    bigint operator+(bigint const &val)
    {
        bigint answer;
        answer.str = add(str, val.str);
        return answer;
    }
    friend bigint operator+(const bigint &val, long long int val2)
    {
        bigint answer;
        answer.str = add(val.str, to_string(val2));
        return answer;
    }
    friend bigint operator+(long long int val, const bigint &val2)
    {
        bigint answer;
        answer.str = add(to_string(val), val2.str);
        return answer;
    }

    bigint &operator+=(const bigint &val)
    {
        this->str = add(this->str, val.str);
        return *this;
    }
    bigint &operator+=(long long int val)
    {
        this->str = add(this->str, to_string(val));
        return *this;
    }

    // operator overloading (- operator)
    bigint operator-(const bigint &val)
    {
        bigint answer;
        answer.str = subtract(this->str, val.str);
        return answer;
    }
    friend bigint operator-(const bigint &val, long long int val2)
    {
        bigint answer;
        answer.str = subtract(val.str, to_string(val2));
        return answer;
    }
    friend bigint operator-(long long int val, const bigint &val2)
    {
        bigint answer;
        answer.str = subtract(to_string(val), val2.str);
        return answer;
    }

    // -= operator
    bigint &operator-=(const bigint &val)
    {
        this->str = subtract(this->str, val.str);
        return *this;
    }
    bigint &operator-=(long long int val)
    {
        this->str = subtract(this->str, to_string(val));
        return *this;
    }

    // operator overloading (* operator)
    bigint operator*(const bigint &val)
    {
        bigint answer;
        answer.str = multiply(this->str, val.str);
        return answer;
    }
    friend bigint operator*(bigint &val, long long int val2)
    {
        bigint answer;
        answer.str = multiply(val.str, to_string(val2));
        return answer;
    }
    friend bigint operator*(long long int val, const bigint &val2)
    {
        bigint answer;
        answer.str = multiply(to_string(val), val2.str);
        return answer;
    }

    // *= operator
    bigint &operator*=(const bigint &val)
    {
        this->str = multiply(this->str, val.str);
        return *this;
    }
    bigint &operator*=(long long int val)
    {
        this->str = multiply(this->str, to_string(val));
        return *this;
    }

    // operator overloading (/ operator)
    bigint operator/(const bigint &val)
    {
        bigint answer;
        answer.str = divide(this->str, val.str);
        return answer;
    }
    friend bigint operator/(const bigint &val, long long int val2)
    {
        bigint answer;
        answer.str = divide(val.str, to_string(val2));
        return answer;
    }
    friend bigint operator/(long long int val, const bigint &val2)
    {
        bigint answer;
        answer.str = divide(to_string(val), val2.str);
        return answer;
    }

    // *= operator
    bigint &operator/=(const bigint &val)
    {
        this->str = divide(this->str, val.str);
        return *this;
    }
    bigint &operator/=(long long int val)
    {
        this->str = divide(this->str, to_string(val));
        return *this;
    }

    // operator overloading (% operator)
    bigint operator%(const bigint &val)
    {
        bigint answer;
        answer.str = mod(this->str, val.str);
        return answer;
    }
    friend bigint operator%(const bigint &val, long long int val2)
    {
        bigint answer;
        answer.str = mod(val.str, to_string(val2));
        return answer;
    }
    friend bigint operator%(long long int val, const bigint &val2)
    {
        bigint answer;
        answer.str = mod(to_string(val), val2.str);
        return answer;
    }

    // *= operator
    bigint &operator%=(const bigint &val)
    {
        this->str = mod(this->str, val.str);
        return *this;
    }
    bigint &operator%=(long long int val)
    {
        this->str = mod(this->str, to_string(val));
        return *this;
    }

    // pre increment
    bigint &operator++()
    {
        this->str = add(this->str, "1");
        return *this;
    }
    //post increment
    bigint operator++(int)
    {
        this->str = add(this->str, "1");
        return *this;
    }

    // pre decrement
    bigint &operator--()
    {
        this->str = subtract(this->str, "1");
        return *this;
    }
    // post decrement
    bigint operator--(int)
    {
        this->str = subtract(this->str, "1");
        return *this;
    }

    bool operator>(const bigint &val)
    {
        return is_strictly_maximum(this->str, val.str);
    }
    friend bool operator>(const bigint &val1, long long int val2)
    {
        return is_strictly_maximum(val1.str, to_string(val2));
    }
    friend bigint operator>(long long int val1, const bigint &val2)
    {
        return is_strictly_maximum(to_string(val1), val2.str);
    }

    bool operator>=(const bigint &val)
    {
        return is_maximum(this->str, val.str);
    }
    friend bool operator>=(const bigint &val1, long long int val2)
    {
        return is_maximum(val1.str, to_string(val2));
    }
    friend bigint operator>=(long long int val1, const bigint &val2)
    {
        return is_maximum(to_string(val1), val2.str);
    }

    bool operator<(const bigint &val)
    {
        return is_strictly_minimum(this->str, val.str);
    }
    friend bool operator<(const bigint &val1, long long int val2)
    {
        return is_strictly_minimum(val1.str, to_string(val2));
    }
    friend bigint operator<(long long int val1, const bigint &val2)
    {
        return is_strictly_minimum(to_string(val1), val2.str);
    }

    bool operator<=(const bigint &val)
    {
        return is_minimum(this->str, val.str);
    }
    friend bool operator<=(const bigint &val1, long long int val2)
    {
        return is_minimum(val1.str, to_string(val2));
    }
    friend bigint operator<=(long long int val1, const bigint &val2)
    {
        return is_minimum(to_string(val1), val2.str);
    }

    bool operator==(const bigint &val)
    {
        return is_equal(this->str, val.str);
    }
    friend bool operator==(const bigint &val1, long long int val2)
    {
        return is_equal(val1.str, to_string(val2));
    }
    friend bigint operator==(long long int val1, const bigint &val2)
    {
        return is_equal(to_string(val1), val2.str);
    }

    bool operator!=(const bigint &val)
    {
        return !is_equal(this->str, val.str);
    }
    friend bool operator!=(const bigint &val1, long long int val2)
    {
        return !is_equal(val1.str, to_string(val2));
    }
    friend bigint operator!=(long long int val1, const bigint &val2)
    {
        return !is_equal(to_string(val1), val2.str);
    }

    static bigint _big_max(const bigint &x, const bigint &y)
    {
        bigint answer;
        answer.str = maximum(x.str, y.str);
        return answer;
    }
    static bigint _big_min(const bigint &x, const bigint &y)
    {
        bigint answer;
        answer.str = minimum(x.str, y.str);
        return answer;
    }
    static bigint _big_abs(const bigint &x)
    {
        bigint answer;
        answer.str = abs(x.str);
        return answer;
    }

    static void _big_swap(bigint &x, bigint &y)
    {
        swap(x.str, y.str);
    }
    static bigint _big_reverse(const bigint &x)
    {
        bigint answer;
        answer.str = reverse(x.str);
        return answer;
    }
    static bigint _big_gcd(const bigint &x, const bigint &y)
    {
        bigint answer;
        answer.str = gcd(x.str, y.str);
        return answer;
    }
    static bigint _big_lcm(const bigint &x, const bigint &y)
    {
        bigint answer;
        answer.str = lcm(x.str, y.str);
        return answer;
    }
    static bigint _big_fact(bigint &x)
    {
        bigint answer;
        answer.str = fact(x.str);
        return answer;
    }
    static bigint _big_pow(bigint &a, bigint &b)
    {
        bigint answer;
        answer.str = pow(a.str, b.str);
        return answer;
    }
    static bigint _big_sqrt(bigint &a)
    {
        bigint answer;
        answer.str = sqrt(a.str);
        return answer;
    }
    static bigint _to_bigint(string x)
    {
        bigint answer;
        answer.str = x;
        return answer;
    }
    static bigint _to_bigint(long long int x)
    {
        bigint answer;
        answer.str = to_string(x);
        return answer;
    }
};

string bigint::add(string x, string y)
{
    int n = x.size(), m = y.size();
    int z = max(n, m);
    if (n == 0 and m == 0)
        return "0";
    else if (x[0] == '-' and y[0] == '-')
    {
        return "-" + add(x.substr(1), y.substr(1));
    }
    else if (x[0] == '-' and y[0] != '-')
    {
        return subtract(y, x.substr(1));
    }
    else if (x[0] != '-' and y[0] == '-')
    {
        return subtract(x, y.substr(1));
    }
    else
    {
        string res;
        int i = n - 1, j = m - 1, carry = 0, k = max(n, m) - 1;
        while (i >= 0 and j >= 0)
        {
            int value = x[i] + y[j] - 96;
            value += carry;
            char temp = 48 + (value % 10);
            res += temp;
            carry = value / 10;
            i--;
            j--;
            k--;
        }
        while (i >= 0)
        {
            int value = x[i] - 48 + carry;
            char temp = 48 + (value % 10);
            res += temp;
            carry = value / 10;
            i--;
            k--;
        }
        while (j >= 0)
        {
            int value = y[j] - 48 + carry;
            char temp = 48 + (value % 10);
            res += temp;
            carry = value / 10;
            j--;
            k--;
        }
        res = carry == 0 ? res : res + to_string(carry);
        std::reverse(res.begin(), res.end());
        return trim(res);
    }
}

bool xmin(string x, string y)
{
    if (x.size() < y.size())
        return true;
    if (x.size() > y.size())
        return false;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] < y[i])
            return true;
        if (x[i] > y[i])
            return false;
    }
    return false;
}

string bigint::subtract(string x, string y)
{
    int n = x.size(), m = y.size();
    char c1 = x[0], c2 = y[0];
    if (c1 == '-' and c2 == '-')
    {
        return subtract(y.substr(1), x.substr(1));
    }
    else if (c1 == '-' and c2 != '-')
    {
        return "-" + add(x.substr(1), y);
    }
    else if (c1 != '-' and c2 == '-')
    {
        return add(x, y.substr(1));
    }
    else
    {
        string mx, mn;
        bool is_x_min = xmin(x, y);
        if (is_x_min)
        {
            mx = y;
            mn = x;
        }
        else
        {
            mn = y;
            mx = x;
        }
        string answer = "";
        int carry = 0;
        std::reverse(mx.begin(), mx.end());
        std::reverse(mn.begin(), mn.end());
        for (int i = 0; i < mn.length(); i++)
        {
            int val = mx[i] - mn[i] - carry;
            if (val < 0)
            {
                val += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            answer += ('0' + val);
        }
        for (int i = mn.length(); i < mx.length(); i++)
        {
            int val = mx[i] - '0' - carry;
            if (val < 0)
            {
                val += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            answer += ('0' + val);
        }
        std::reverse(answer.begin(), answer.end());
        if (is_x_min)
        {
            answer = "-" + answer;
        }
        return trim(answer);
    }
}

string bigint::multiply(string x, string y)
{
    if (x == "0" or y == "0")
    {
        return "0";
    }
    if (x[0] == '-' and y[0] != '-')
    {
        return "-" + multiply(x.substr(1), y);
    }
    if (x[0] != '-' and y[0] == '-')
    {
        return "-" + multiply(x, y.substr(1));
    }
    if (x[0] == '-' and y[0] == '-')
    {
        return multiply(x.substr(1), y.substr(1));
    }
    else
    {
        std::reverse(x.begin(), x.end());
        std::reverse(y.begin(), y.end());
        string temp = "";
        string answer = "";
        for (int i = 0; i < x.size(); i++)
        {
            int a = x[i] - '0';
            string ans = "";
            int carry = 0;
            for (int j = 0; j < y.size(); j++)
            {
                int b = y[j] - '0';
                int val = (a * b + carry);
                ans += ('0' + (val % 10));
                carry = val / 10;
            }
            std::reverse(ans.begin(), ans.end());
            if (carry != 0)
            {
                ans = to_string(carry) + ans;
            }
            ans += temp;
            answer = add(answer, ans);
            temp += '0';
        }
        return answer;
    }
}

string bigint::shortDivide(string x)
{
    int divisor = 2;
    string ans;
    int ind = 0;
    long long int temp = x[ind] - '0';

    while (temp < divisor)
    {
        temp = temp * 10 + (x[++ind] - '0');
        if (ind >= x.length())
            break;
    }
    while (x.length() > ind)
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + x[++ind] - '0';
    }

    if (ans.length() == 0)
        return "0";

    return ans;
}

string bigint::divide(string x, string y)
{ // return arithmetic division of str1/str2
    string answer;
    if (y == "0")
    {
        return "0";
    }
    else if (x == y)
    {
        return "1";
    }
    else if (x[0] == '-' && y[0] == '-')
    {
        answer = divide(x.substr(1), y.substr(1));
    }
    else if (x[0] == '-')
    {
        string temp = divide(x.substr(1), y);
        if (temp == "0")
        {
            answer = temp;
        }
        else
        {
            answer = '-' + temp;
        }
    }
    else if (y[0] == '-')
    {
        string temp = divide(x, y.substr(1));
        if (temp == "0")
            answer = temp;
        else
            answer = '-' + temp;
    }
    else
    {
        if (y == "1")
        {
            return x;
        }
        if (y == maximum(x, y))
        {
            return "0";
        }
        string s = "0", e = x;
        while (is_minimum(s, e))
        {
            string sub = subtract(e, s);
            string mid = add(s, shortDivide(sub));
            string temp = multiply(mid, y);
            if (temp == x)
            {
                return mid;
            }
            else if (maximum(temp, x) == temp)
            {
                e = subtract(mid, "1");
            }
            else
            {
                answer = mid;
                s = add(mid, "1");
            }
        }
    }
    return answer;
}

string bigint::mod(string x, string y)
{
    string answer = subtract(x, multiply(y, divide(x, y)));
    if (answer[0] == '-')
        return answer.substr(1);
    return answer;
}

string bigint::maximum(string x, string y)
{
    string answer = subtract(x, y);
    if (answer[0] == '-')
    {
        return y;
    }
    else
    {
        return x;
    }
}

string bigint::minimum(string x, string y)
{
    string answer = maximum(x, y);
    if (answer == x)
        return y;
    return x;
}

bool bigint::is_maximum(string x, string y)
{
    string answer = maximum(x, y);
    if (answer == x)
        return true;
    return false;
}

bool bigint::is_minimum(string x, string y)
{
    string answer = maximum(x, y);
    if (answer == y)
        return true;
    return false;
}

bool bigint::is_strictly_maximum(string x, string y)
{
    string answer = subtract(x, y);
    if (answer[0] == '-' or answer == "0")
        return false;
    return true;
}

bool bigint::is_strictly_minimum(string x, string y)
{
    string answer = subtract(x, y);
    if (answer[0] == '-')
    {
        return true;
    }
    return false;
}

bool bigint::is_equal(string x, string y)
{
    return x == y;
}

string bigint::abs(string x)
{
    if (x[0] == '-')
    {
        return x.substr(1);
    }
    return x;
}

void bigint::swap(string &x, string &y)
{
    string s;
    s = x;
    x = y;
    x = s;
    return;
}

string bigint::reverse(string x)
{
    std::reverse(x.begin(), x.end());
    return x;
}

string bigint::gcd(string x, string y)
{
    if (is_strictly_maximum(y, x))
        swap(x, y);
    string temp = "";
    while (is_strictly_maximum(y, "0"))
    {
        temp = mod(x, y);
        x = y;
        y = temp;
    }
    return x;
}

string bigint::lcm(string x, string y)
{
    return divide(multiply(x, y), gcd(x, y));
}

string bigint::pow(string x, string y)
{
    if (y == "0")
    {
        return "1";
    }
    if (x[0] == '-')
    {
        string ans = pow(x.substr(1), y);
        if (mod(y, "2") == "0")
        {
            return ans;
        }
        return "-" + ans;
    }
    string ans = pow(x, divide(y, "2"));
    if (mod(y, "2") == "0")
    {
        return multiply(ans, ans);
    }
    return multiply(x, multiply(ans, ans));
}

string bigint::sqrt(string x)
{
    if (x[0] == '-')
    {
        return "";
    }
    string s = "0";
    string e = x;
    string answer;
    while (is_minimum(s, e))
    {
        string sub = subtract(e, s);
        string mid = add(s, shortDivide(sub));
        string ans = multiply(mid, mid);
        if (ans == x)
        {
            return mid;
        }
        else if (maximum(x, ans) == x)
        {
            answer = mid;
            s = add(mid, "1");
        }
        else
        {
            e = subtract(mid, "1");
        }
    }
    return answer;
}

string bigint::fact(string s)
{
    string ans = "1";
    int cnt = 0;
    while (s != "0")
    {
        ans = multiply(ans, s);
        s = subtract(s, "1");
    }
    return ans;
}

string bigint::trim(string s)
{
    if (s == "0")
        return s;
    if (s[0] == '-')
    {
        int i = 1;
        while (s[i] == '0')
        {
            s.erase(i, 1);
        }
        return s;
    }
    else if (s[0] == '0')
    {
        int i = 0;
        while (s[i] == '0')
        {
            s.erase(i, 1);
        }
        return s;
    }
    return s;
}

bool bigint::is_bigint(string s)
{
    if (s[0] == '-')
        s.erase(0, 1);
    for (unsigned long long int i = 0; i < s.length(); ++i)
    {
        if (!((int)s[i] > 47 && (int)s[i] < 58))
            return false;
    }
    return true;
}
