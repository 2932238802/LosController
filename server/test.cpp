
#include<unordered_map>

int main()
{
    std::unordered_map<int,char> map_;
    map_.insert({'2',3});
    map_.emplace('a',3);

}