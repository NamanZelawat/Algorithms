#include <bits/stdc++.h>

using namespace std;

struct node
{
    struct node *left;
    struct node *right;
    string val;
};

int main()
{
    string s1, s2;
    cout << "Input start and end point" << endl;
    cin >> s1 >> s2;
    cout << s1 << "->";
    int len = s1.size();
    string temp1, temp2;
    while (len >= 0)
    {
        len--;
        temp1 = s1.substr(0, len);
        temp2 = s2.substr(0, len);
        cout << temp1 << "->";
        if (temp1.compare(temp2) == 0)
        {
            break;
        }
    }
    for (int i = temp1.size(); i < s2.size() - 1; i++)
    {
        temp1.push_back(s2[i]);
        cout << temp1 << "->";
    }
    cout << s2 << endl;
}