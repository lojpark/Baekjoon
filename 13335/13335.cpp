/*
Just coding
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int i, j;
    int n, w, l, temp, w_sum = 0, time = 0;
    cin >> n >> w >> l;

    vector<int> truck;
    vector<int> bridge;
    for (i = 0; i < n; i++) {
        cin >> temp;
        truck.push_back(temp);
    }
    for (i = 0; i < w; i++) {
        bridge.push_back(0);
    }

    j = w - 1;
    for (i = 0; i < n; i++) {
        if (w_sum + truck[i] > l) {
            while (w_sum - bridge[j-w+1] + truck[i] > l) {
                bridge.push_back(0);
                j++;
                time++;
                w_sum -= bridge[j - w];
            }
        }
        bridge.push_back(truck[i]);
        j++;
        time++;
        w_sum += bridge[j];
        w_sum -= bridge[j - w];
    }

    cout << time + w << endl;

    return 0;
}