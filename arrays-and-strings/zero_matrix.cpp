//Complexity = O(n2)
//Space Complexity = O(m/n) (whichever is higher)

#include <iostream>
using namespace std;

void zero_matrix(int matrix[][3]) {
	static bool row_array[3];
	static bool column_array[3];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			if(matrix[i][j] == 0) {
				row_array[i] = true;
				column_array[j] = true;
			}
		}
	}

	for(int k = 0; k < 3; k++) {
		if(row_array[k] == true) {
			for(int l = 0; l < 3; l++) {
				matrix[k][l] = 0;
			}
		}
	}
	
	for(int k = 0; k < 3; k++) {
		if(column_array[k] == true) {
			for(int l = 0; l < 3; l++) {
				matrix[l][k] = 0;
			}
		}
	}

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cout<<matrix[i][j];
			cout<<"";
		}
		cout<<"\n";
	}
}

int main ()
{
  int matrix[3][3] = {1,1,0, 
      1,1,1,
      1,1,1,
  };

  zero_matrix(matrix);
}