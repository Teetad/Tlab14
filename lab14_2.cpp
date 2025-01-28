#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);


void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

//Do not modify source code above this line 
void  inputMatrix(double inMatrix[N][N]){
	double storage;
	for (int i = 0; i < N; i++){
		cout << "Row "<< i + 1<< ": ";
		for (int j = 0; j < N; j++){
			cin >> storage;
			inMatrix[i][j] = storage;
		}
	}
}

void findLocalMax(const double inMatrix[][N], bool ans[N][N]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1){
				ans[i][j] = 0;
			} 
			else if (inMatrix[i][j] >= inMatrix[i-1][j] && inMatrix[i][j] >= inMatrix[i+1][j] && inMatrix[i][j] >= inMatrix[i][j-1] && inMatrix[i][j] >= inMatrix[i][j+1]){
				ans[i][j] = 1;
			}else{
				ans[i][j] = 0;
			}
		}
	}
}

void showMatrix(const bool show[][N]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << show[i][j] << ' ';
		}
		cout << "\n";
	}
}