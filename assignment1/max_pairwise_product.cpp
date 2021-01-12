#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int64_t MaxPairwiseProduct(const vector<int64_t>& numbers) 
{
    int64_t max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) 
        {
            if(numbers[first] * numbers[second] > max_product)
            {
                max_product = numbers[first] * numbers[second];
            }
        }
    }

    return max_product;
}

int64_t MaxPairwiseProductFast(const vector<int64_t>& numbers) 
{

    int n = numbers.size();
    int a = 0;
    int b = 0;

    for (int first = 0; first < n; ++first) {
        if(numbers[first] > numbers[a])
        {
            a = first;
            //cout << "a = " << a << "\n";
        }
    }

    if(a == 0){
        b = 1;
    }
    
    for (int first = 0; first < n; ++first) {
        if((numbers[first] > numbers[b]) and first != a )
        {
            b = first;
            //cout << "b = " << b << "\n";
        }
    }

    return  numbers[a] * numbers[b];


}






int main() {
    int n;
    cin >> n;
    vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    //cout << MaxPairwiseProduct(numbers) << "\n";
    cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
