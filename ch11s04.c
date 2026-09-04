#include <stdio.h>

#define LEN 8
int a[LEN] = { 5, 2, 4, 7, 1, 3, 2, 6 };

int partition(int start, int end)
{
    int pivot = a[start];
    
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

int main(void)
{
	quicksort(0, LEN-1);
    for (int i = 0; i < LEN; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
	return 0;
    printf("test1");
}