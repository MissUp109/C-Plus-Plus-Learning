#include <iostream>
using namespace std;

void magic(int** A, const int n){
	int i = 0, j = n / 2;
	for(int k = 1; k <= n * n; ++k){
		A[i][j] = k;
		if(k % n == 0) i++;
		else{
			i = (i - 1 + n) % n;
			j = (j - 1 + n) % n;
		}
	}
}

int main(){
	const int n = 3;
	int **A = new int*[n];
	for(int i = 0; i < n; ++i)
		A[i] = new int[n];

	magic(A, n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}