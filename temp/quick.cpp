#include <iostream>
#include <time.h>
using namespace std;
int n;
const int N = 1e5 + 10;
int q[N];
void quick_sort(int l, int r)
{
    if (l >= r) return;
    int i = l - 1, j = r + 1;
    int rand_idx = rand() % (r - l + 1) + l;
    swap(q[l], q[rand_idx]);
    int x = q[l];
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(l, i - 1);
    quick_sort(i, r);

}
int main(void)
{
    srand(time(nullptr));
    scanf("%d", &n);
    for (int i = 0; i < n;i++) scanf("%d", &q[i]);
    quick_sort(0, n - 1);
    for (int i = 0;i < n;i++) printf("%d ", q[i]);
    return 0;
}