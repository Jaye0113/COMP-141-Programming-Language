#include <vector>
#include <string>
#include <utility> // for pair
using namespace std;
// Chi-Hao Tu, Yaoyao Liu
vector<pair<string, string>> insertOrUpdate(
    vector<pair<string, string>> dictionary,
    string _key,
    string _value,
    unsigned short index = 0)
{
    // Base case: if we've checked all elements, return the dictionary with the new pair
    if(index >= dictionary.size()){
        dictionary.push_back(make_pair(_key, _value));
        return dictionary;
    }

    if (dictionary[index].first == _key){
        dictionary[index].second = _value;
        return dictionary;
    }

    return insertOrUpdate(dictionary, _key, _value, index + 1);
}

