#include <iostream>
using namespace std;

bool canFinish(int arr[], int n, int d, long long cap) {
    long long sum = 0;
    int days = 1;

    for (int i = 0; i < n; i++) {
        if (sum + arr[i] <= cap) {
            sum += arr[i];
        } else {
            days++;
            sum = arr[i];
        }
    }
    return days <= d;
}

int main() {
    int N, D;
    cin >> N >> D;

    int arr[N];
    long long low = 0, high = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > low)
            low = arr[i];   
        high += arr[i];     
    }

    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canFinish(arr, N, D, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}