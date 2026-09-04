#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end) {
    int pivot = a[start];

    if (start == end) {
        return start;
    }
    
    while (start < end) {
        while (a[end] >= pivot) {
            --end;
            if (start == end) {
                a[start] = pivot;
                return start;
            }
        }
        a[start] = a[end];
        ++start;
        if (start == end){
            a[start] = pivot;
            return start;
        }
        while (a[start] <= pivot) {
            ++start;
            if (start == end) {
                a[start] = pivot;
                return start;
            }
        }
        a[end] = a[start];
        --end;
        if (start == end) {
            a[start] = pivot;
            return start;
        }
    }
    return -1;
}

void quicksort(int start, int end)
{
    int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}	
}

int order_statistic(int start, int end, int k) {
    --k;
    int i = partition(start, end);
    // i -= start;
	if (k == i) {
        return a[i];
    } else if (k > i) {
        return order_statistic(i+1, end, k+1);
    } else {
        return order_statistic(start, i-1, k+1);
    }
}

int main(void)
{
	quicksort(0, LEN-1);
    for (int i = 0; i < LEN; ++i) {
        printf("%d ", a[i]);
    }
    int k = 1;
    printf("\n%dth small num is:%d\n", k, order_statistic(0, LEN-1, k));
	return 0;
}