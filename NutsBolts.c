#include <stdio.h>

int partition(int *items, int low, int high, int pivot) {
    int left = low; 
    int right = high;
    int temp;

    printf("partition %d %d %d\n", low, high, pivot);    
    while (left < right) {
        while (items[left] < pivot) 
            left++;
        while (items[right] > pivot)
            right--;
            
        if (left < right) {
            //printf("swap %d with %d\n", left, right);
            temp = items[left];
            items[left] = items[right];
            items[right] = temp;
        }
    }
    //printf("partition %d\n", left);
    return left;
}

void match_pair(int *nuts, int *bolts, int low, int high) {
    int pivot, pivot2;
    
    if (low > high) 
        return;
    printf("match_pair %d %d\n", low, high);
    // partition nuts with last bolt
    pivot = partition(nuts, low, high, bolts[high]); 
    //printf("pivot %d\n", pivot);
    // now nuts[pivot] matches bolts[bolts_count]
    // put bolts[bolts_count] in its right place in bolts
    pivot2 = partition(bolts, low, high, nuts[pivot]); 
    printf("%d %d\n", nuts[pivot], bolts[pivot2]);
    
    match_pair(nuts, bolts, low, pivot-1);
    match_pair(nuts, bolts, pivot+1, high);
}

char** solve(int nuts_count, int* nuts, int bolts_count, int* bolts, int* result_count) {
    /*
     * Write your code here.
     */
     if (nuts_count == bolts_count) 
        match_pair(nuts, bolts, 0, bolts_count-1);

}

int main(void) {
	// your code goes here
	int nuts[4] = {4, 32, 5, 7};
	int bolts[4] = {32, 7, 5, 4};
	
	solve(4, nuts, 4, bolts, 0);
	return 0;
}

