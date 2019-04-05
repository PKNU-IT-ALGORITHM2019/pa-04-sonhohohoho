#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void revary(int n);
void ranary(int n);

void swap(int a, int b);
void bubbleSort(int n);
void selectionSort(int n);
void insertionSort(int n);
void mergeSort(int p, int r);
void merge(int p, int q, int r);
void quickSort(int p, int r);
int partition(int p, int r);
void mquickSort(int p, int r);
int mpartition(int p, int r);
void rquickSort(int p, int r);
int rpartition(int p, int r);
void printresult();
void max_heapify(int i);
void build_max_heap();
void heapsort();
int compare_ary_by_qty(const void*p, const void *q) {
	return *(int*)p - *(int*)q;
}


int max_heap = 0;

int ary[1000000];

int tmp[1000000];

char sort[][20] = { "Bubble     ","Selection  ","Insertion  ","Merge      ","Quick1     ","Quick2     ","Quick3     " ,"Heap       ","Library    " };
double result[9][6] = { {0,0,0,0,-1,-1},{0,0,0,0,-1,-1} ,{0,0,0,0,-1,-1} ,{0,0,0,0,0,0} ,{0,0,0,-1,0,-1} ,{0,0,0,0,0,0} ,{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} };

int main(void) {

	int N[3] = { 1000,10000,100000 };
	int Nn = 0;
	double avgtime = 0;
	clock_t begin, end;

	srand(time(NULL));

	printf("bubblesort중입니다.\n");

	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {

				ranary(N[Nn]);
				begin = clock();
				bubbleSort(N[Nn]);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[0][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			bubbleSort(N[Nn++]);
			end = clock();
			result[0][i] = (double)(end - begin) / 1000;
		}
	}

	Nn = 0;


	printf("selectionsort중입니다.\n");

	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {

				ranary(N[Nn]);
				begin = clock();
				selectionSort(N[Nn]);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[1][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			selectionSort(N[Nn++]);
			end = clock();
			result[1][i] = (double)(end - begin) / 1000;
		}
	}

	Nn = 0;

	printf("insertionsort중입니다.\n");

	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {

				ranary(N[Nn]);
				begin = clock();
				insertionSort(N[Nn]);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[2][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			insertionSort(N[Nn++]);
			end = clock();
			result[2][i] = (double)(end - begin) / 1000;
		}
	}

	Nn = 0;

	printf("mergesort중입니다.\n");

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {

				ranary(N[Nn]);
				begin = clock();
				mergeSort(0, N[Nn] - 1);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[3][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			mergeSort(0, N[Nn++] - 1);
			end = clock();
			result[3][i] = (double)(end - begin) / 1000;
		}
	}

	Nn = 0;

	printf("quicksort1중입니다.\n");

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {
				ranary(N[Nn]);
				begin = clock();
				quickSort(0, N[Nn] - 1);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[4][i] = avgtime / 10;
			avgtime = 0;

		}
		else if (i == 1) {

			revary(N[Nn]);
			begin = clock();

			quickSort(0, N[Nn] - 1);
			Nn++;
			end = clock();

			result[4][i] = (double)(end - begin) / 1000;
		}
	}

	printf("quicksort2중입니다.\n");

	Nn = 0;
	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {

				ranary(N[Nn]);
				begin = clock();
				mquickSort(0, N[Nn] - 1);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[5][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			mquickSort(0, N[Nn++] - 1);
			end = clock();
			result[5][i] = (double)(end - begin) / 1000;
		}
	}

	Nn = 0;

	printf("quicksort3중입니다.\n");

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {

				ranary(N[Nn]);
				begin = clock();
				rquickSort(0, N[Nn] - 1);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[6][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			rquickSort(0, N[Nn++] - 1);
			end = clock();
			result[6][i] = (double)(end - begin) / 1000;
		}
	}

	Nn = 0;
	max_heap = N[Nn] - 1;

	printf("heapsort중입니다.\n");

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {
				ranary(N[Nn]);
				begin = clock();
				heapsort();
				end = clock();
				max_heap = N[Nn] - 1;
				avgtime += (double)(end - begin) / 1000;
			}
			result[7][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			heapsort();
			end = clock();
			Nn++;
			max_heap = N[Nn] - 1;
			result[7][i] = (double)(end - begin) / 1000;
		}
	}


	Nn = 0;

	printf("C언어 라이브러리제공 sort중입니다.\n");

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 10; j++) {

				ranary(N[Nn]);
				begin = clock();
				qsort(ary, N[Nn], sizeof(int), compare_ary_by_qty);
				end = clock();

				avgtime += (double)(end - begin) / 1000;
			}
			result[8][i] = avgtime / 10;
			avgtime = 0;

		}
		else {
			revary(N[Nn]);
			begin = clock();
			qsort(ary, N[Nn], sizeof(int), compare_ary_by_qty);
			end = clock();
			result[8][i] = (double)(end - begin) / 1000;
		}
	}

	Nn = 0;


	printresult();

	return 0;
}


void revary(int n) {
	for (int i = 0; i < n; i++)
		ary[i] = n - i;
}

void ranary(int n) {
	for (int i = 0; i < n; i++)
		ary[i] = rand() % n + 1;
}


void swap(int a, int b) {
	int tmp;
	tmp = ary[a];
	ary[a] = ary[b];
	ary[b] = tmp;
}


void bubbleSort(int n) {

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (ary[j] > ary[j + 1])
				swap(j, j + 1);
}



void selectionSort(int n) {
	int lar = 0;

	for (int i = n - 1; i > 0; i--) {

		for (int j = 0; j < i + 1; j++)
			if (ary[lar] < ary[j])lar = j;


		swap(lar, i);
		lar = 0;

	}

}


void insertionSort(int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (ary[j] < ary[j - 1])swap(j, j - 1);
			else break;
		}
	}
}



void mergeSort(int p, int r) {

	int q;

	if (p < r) {

		q = (p + r) / 2;
		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
	}

}

void merge(int p, int q, int r) {

	int x = p, y = q + 1;
	int k = p;
	for (int i = p; i < q + 1; i++)tmp[i] = ary[i];
	for (int i = q + 1; i < r + 1; i++)tmp[i] = ary[i];

	while (x != q + 1 && y != r + 1) {

		if (tmp[x] < tmp[y]) {
			ary[k] = tmp[x];
			x++;
		}
		else {
			ary[k] = tmp[y];
			y++;
		}

		k++;

	}

	while (x != q + 1 || y != r + 1) {

		if (x == q + 1)ary[k++] = tmp[y++];
		else ary[k++] = tmp[x++];

	}

}


void quickSort(int p, int r) {

	int q;

	if (p < r) {

		q = partition(p, r);
		quickSort(p, q - 1);
		quickSort(q + 1, r);

	}

}

int partition(int p, int r) {

	int k = p;

	for (int i = p; i < r; i++)
		if (ary[i] < ary[r]) {
			swap(i, k);
			k++;
		}

	swap(k, r);

	return k;
}


void mquickSort(int p, int r) {
	int q;

	if (p < r) {

		q = mpartition(p, r);
		mquickSort(p, q - 1);
		mquickSort(q + 1, r);

	}

}

int mpartition(int p, int r) {

	int k = p, pivot;


	if (ary[p] < ary[r]) {
		if (ary[r] < ary[(p + r) / 2])
			pivot = r;
		else
			if (ary[p] < ary[(p + r) / 2])
				pivot = (p + r) / 2;
			else
				pivot = p;
	}
	else {
		if (ary[p] < ary[(p + r) / 2])
			pivot = p;
		else
			if (ary[r] < ary[(p + r) / 2])
				pivot = (p + r) / 2;
			else
				pivot = r;
	}

	for (int i = p; i < r + 1; i++)
		if (ary[i] < ary[pivot]) {
			swap(k, i);
			if (k == pivot)pivot = i;
			k++;

		}

	swap(k, pivot);

	return k;

}


void rquickSort(int p, int r) {

	int q;

	if (p < r) {

		q = rpartition(p, r);
		rquickSort(p, q - 1);
		rquickSort(q + 1, r);

	}

}

int rpartition(int p, int r) {

	int k = p, pivot;

	pivot = rand() % (r - p + 1) + p;

	for (int i = p; i < r + 1; i++)
		if (ary[i] < ary[pivot]) {
			swap(k, i);
			if (k == pivot)pivot = i;
			k++;

		}

	swap(k, pivot);

	return k;

}


void printresult() {
	printf("\n-1은 오래걸리는 계산입니다.\n");
	printf("\n------------------------------------------------------------------------------\n");
	printf("               Ran1000    Rev1000   Ran10000   Rev10000   Ran100000   Rev100000\n");
	printf("------------------------------------------------------------------------------");
	for (int i = 0; i < 9; i++) {
		printf("\n%s", sort[i]);
		for (int j = 0; j < 6; j++) {
			printf("      %0.3lf", result[i][j]);
		}
	}

}

void heapsort() {
	build_max_heap();
	for (int i = max_heap; i > 0; i--) {
		swap(0, i);
		max_heap--;
		max_heapify(0);
	}
}


void build_max_heap() {

	int a = max_heap / 2 - 1;

	for (int i = a; i >= 0; i--) {
		max_heapify(i);
	}

}

void max_heapify(int i) {

	int k;

	while (i * 2 <= max_heap) {

		if (i * 2 == max_heap)
			k = i * 2;
		else if (ary[i * 2] < ary[i * 2 + 1])
			k = i * 2 + 1;
		else
			k = i * 2;


		if (ary[i] >= ary[k])
			return;


		swap(i, k);

		i = k;

	}


}