#include <iostream>
using namespace std;

int N;
bool notPrime[4000001] = { false, };
int sum = 0;

int main()
{
    cin >> N;

    for (int i = 2; i <= 4000000; i++) {
        if (notPrime[i]) continue;
        for (long long j = 2; j * i <= 4000000; j++) {
            notPrime[j * i] = true;
        }
    }

    int low = 2;
    int high = 2;
    int sum = 2;
    long long count = 0;
    while (low <= N) {
        if (notPrime[low]) {
            low++;
        }
        else if (notPrime[high]) {
            high++;
            sum += 1;
        }
        else {
            if (N == sum) {
                count++;
                high++;
                sum += high;
            }
            else if (N < sum) {
                sum -= low;
                low++;

            }
            else {
                high++;
                sum += high;
            }
        }
    }

    cout << count;
    return 0;
}
