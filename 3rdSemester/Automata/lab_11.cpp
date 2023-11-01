#include <bits/stdc++.h>
using namespace std;

int found = 0;
string path, path2;
void cfg(vector<string> &base, string output, string target, string currpath)
{
    if (found == 2)
        return;

    if (output.size() > target.size() + 2)
        return;

    if (output.find('S') == string::npos && output != " ")
    {
        while (output.find('E') != string::npos)
        {

            if (output.find('E') != string::npos)
            {
                string temp = output.substr(0, output.find('E'));
                temp += output.substr(output.find('E') + 1);
                output = temp;
            }
        }

        if (output == target)
        {
            found++;
            cout << "Path uploading: " << currpath << found << endl;
            if (found == 1)
                path = currpath;

            if (found == 2)
            {
                path2 = currpath;
                cout << "path2 printing: " << path2 << endl;
            }
        }
        return;
    }

    for (string x : base)
    {
        if (output.find('S') != string::npos)
        {
            string temp = output.substr(0, output.find('S'));
            temp += x;
            temp += output.substr(output.find('S') + 1);
            x = temp;
        }
        cout << x << endl;
        cfg(base, x, target, currpath + "->" + x);
        if (found == 2)
            return;
    }
}

int main()
{
    vector<string> base = {"E", "aS", "aSbS"};
    string s;
    cin >> s;
    cfg(base, "S", s, path);
    (found == 2) ? cout << "Yes" : cout << "no";
    cout << endl;

    cout << "path1 printing: " << path << endl;
    cout << " path2 printing: " << path2 << endl;
    if (found == 2)
    {
        if (path.find('E') != string::npos)
        {
            string temp = path.substr(0, path.find('E'));
            temp += path.substr(path.find('E') + 1);
            path = temp;
        }

        while (path.find('E') != string::npos)
        {

            if (path.find('E') != string::npos)
            {
                string temp = path.substr(0, path.find('E'));
                temp += path.substr(path.find('E') + 1);
                path = temp;
            }
        }
        while (path2.find('E') != string::npos)
        {

            if (path2.find('E') != string::npos)
            {
                string temp = path2.substr(0, path2.find('E'));
                temp += path2.substr(path2.find('E') + 1);
                path2 = temp;
            }
        }

        cout<<endl<<endl<<endl<< endl<< "Path-1: " << "S" + path << endl;
        cout << "Path-2: " + path2 << endl;
    }
    return 0;
}