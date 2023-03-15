#include <iostream>
#include <vector>

using namespace::std;
#define FOR(i, b) for(int i = 0; i < b; i++)

int main() {
    int N; cin>>N; N--;
    int arr[8] = {1, 2, 4, 7, 8, 11, 13, 14};
    cout<<arr[N%8]+15*(N/8)<<endl;
}