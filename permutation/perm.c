#include <stdio.h>

//#define SWAP(A, B, TMP) ((TMP)=(A), (A)=(B), (B)=(TMP))
void SWAP (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm(int Arr[], int index, int ArrSize) {
	// edge condition
	if (index == ArrSize-1) {
		// printf result
		for (int j=0; j<ArrSize; j++) {
			if (j != ArrSize-1) {
				printf("%d, ", Arr[j]);
			} else {
				printf("%d\n", Arr[j]);
			}
		}
	} else {
		for (int i=index; i < ArrSize; i++) {
			// Arr[index] ~ Arr[ArrSize] swap into Arr[index] 
			SWAP (Arr+index, Arr+i);
			// change into the next permutation
			perm (Arr, index+1, ArrSize);
			// Recovery order.
			SWAP (Arr+index, Arr+i); 
		}
	}
	
}

int main(void) {
	int Arr[] = {10, 20, 30, 40};
	perm (Arr, 0, 3);
	return 0;
}
