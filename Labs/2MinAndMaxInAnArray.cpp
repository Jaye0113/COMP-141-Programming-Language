#include <utility>
#include <climits>
using namespace std;

pair<long, long> minmaxFromArray(const long _array[], short _array_length, short index = 0, long current_min = LONG_MAX, long current_max = LONG_MIN){
    if(index == _array_length){
        return {current_min, current_max};
    }

    current_min = (_array[index] < current_min) ? _array[index] : current_min;
    current_max = (_array[index] > current_max) ? _array[index] : current_max;

    return minmaxFromArray(_array, _array_length, index + 1, current_min, current_max);
}

