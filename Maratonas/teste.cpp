#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << v.front() << endl;   // 10
    cout << v.back() << endl;    // 30
    cout << v[1] << endl;        // 20

    v.pop_back();

    cout << v.size() << endl;    // 2
    
    return 0;
}