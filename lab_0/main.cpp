#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include<algorithm>
#include<list>

using namespace std;
struct Data
{
    int number;
    Data(int s) : number(s) {}
};
bool operator==(const Data& lhs, const Data& rhs)
{
  return lhs.number == rhs.number;
}
bool compare_by_Data(const Data& lhs, const Data& rhs)
{
    return lhs.number < rhs.number;
}
bool comp1  ( const Data& lhs, const Data& rhs )
{
    return lhs.number == rhs.number;
}
int Dubl(vector<Data> new_Data);

int Povtor(vector<Data> new_Data, int repeat);

int main()
{
    setlocale(LC_ALL,"Russian");
    std::vector<Data> new_Data;
    int number;
    std::ifstream in("\\Dat.txt");
    if (in.is_open())
    {
        while (in >> number)
        {
            new_Data.push_back(Data(number));
            std::sort(new_Data.begin(), new_Data.end(), compare_by_Data);
            Dubl(new_Data);
            cout <<"—ообщение "<< new_Data[0].number << "-" << new_Data[new_Data.size()-1].number;
            Povtor(new_Data, 0);
            cout<<endl;
        }
    }
    in.close();
    return 0;
}
int Dubl(vector<Data> new_Data)
{
    auto last = std::unique(new_Data.begin(), new_Data.end(),comp1);
    new_Data.erase(last, new_Data.end());
    return 0;
}

int Povtor(vector<Data> new_Data, int repeat)
{
    vector<Data> lack_of_packet;
    for(int k = new_Data[0].number; k <= new_Data[new_Data.size()-1].number; k++)
    {
        if(find(new_Data.begin(), new_Data.end(),k) == new_Data.end())
        {
            lack_of_packet.push_back(Data(k));
            repeat++;
        }
    }
    if(repeat == 0)
    {
        cout<< " получено полностью.";
    }
    else
    {
      cout<< " не хватает пакетов:";
      for (int i = 0; i < lack_of_packet.size(); i++)
      std::cout << lack_of_packet[i].number<<" ";
    }
}
