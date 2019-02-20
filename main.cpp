#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include <fstream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string> v(n);

    std::ifstream in("C:\\lab\\1\\build-untitled-Desktop_Qt_5_9_1_MinGW_32bit-Debug\\number.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
         for(int i=0; i<n;i++)
        {
            v.push_back(v(i));
        }
    }
    in.close();
    sort(v.begin(),v.end());
    for(int i=0; i<n;i++)
        cout<< v[i]<< " ";
string a;
list<string> l;

    return 0;
}
