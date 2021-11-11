// Van The Ho

#include <iostream>
#include <limits>
#include <cmath>


using namespace std;

long long sum_of_table(int **table, int M) {
	long long sum = 0;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++ ){
			sum += table[i][j];
		}
	}
	return sum;
};

void N(int **table) {
	int x, y, w;
	cin >> x >> y >> w;
	table[x][y] = w;
}

void move_to_left(int *table, int M, int from, int dist) {
	for (int i = from; i < M - dist; i++) {
		table[i] = table[i + dist];
	}
	
	for (int i = M - dist; i < M; i++) {
		table[i] = 0;
	}
}

void L(int **table, int M) {
	for (int i = 0; i < M; i++) {
		int j = 0;
		while (j < M) {
			if (table[i][j] == 0) {
				/*int count = 1;
				while (table[i][j] == table[i][j+1] and j < M - 1) {
					count++;
					j++;
				}
				move_to_left(table[i], M, j, count);
				if (j == M - 1) break;
				j = 0;	*/			
				
				int k = j + 1;
				while (k <= M - 1 && table[i][k] == 0) {
					k++;
				}
				
				if (k == (M )) break;
			
				move_to_left(table[i], M, j, 1);
				j = 0;
								
			} else if (table[i][j] == table[i][j+1]) {
					table[i][j] *= 2;
					move_to_left(table[i], M, j+1, 1);
					j = 0;
			} else {
				j++;
			}
		}
	}
}

void reverseTable(int **table, int M) {
	int temp = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < (M / 2); j++) {
			temp = table[i][j];
			table[i][j] = table[i][M - 1 - j];
			table[i][M -1 -j] = temp;
		}
	}
}



void W(int **table, int M) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void P(int **table, int M) {
	reverseTable(table, M);
	L(table, M);
	reverseTable(table, M);
} 

void C(int **table, int M) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> table[i][j];
		}
	}
}

void rotationMatrix90ClockWise(int **a, int N) {
	for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}

void rotationMatrix90CounterClockWise(int **mat,  int N) {
  
    for (int x = 0; x < N / 2; x++) {
       
        for (int y = x; y < N - x - 1; y++) {
         
            int temp = mat[x][y];
 
       
            mat[x][y] = mat[y][N - 1 - x];
 
            mat[y][N - 1 - x]
                = mat[N - 1 - x][N - 1 - y];
 
            mat[N - 1 - x][N - 1 - y]
                = mat[N - 1 - y][x];
 
            mat[N - 1 - y][x] = temp;
        }
    }
}

void D(int **table, int M) {
	rotationMatrix90ClockWise(table, M);
	L(table, M);
	rotationMatrix90ClockWise(table, M);
	rotationMatrix90ClockWise(table, M);
	rotationMatrix90ClockWise(table, M);
	//rotationMatrix90CounterClockWise(table, M);
}


void G(int **table, int M) {
	//rotationMatrix90CounterClockWise(table, M);
	rotationMatrix90ClockWise(table, M);
	rotationMatrix90ClockWise(table, M);
	rotationMatrix90ClockWise(table, M);
	L(table,M);
	rotationMatrix90ClockWise(table, M);
}

void S(int **table, int M) {
	cout << sum_of_table(table, M) << endl;
}

void K(int **table, int M) {
	cout << sum_of_table(table, M) << endl;
}

int main() {
	
	int M;
	
	cin >> M;
	
	int **table = new int*[M];
	
	for (int i = 0; i < M; i++) {
		table[i] = new int[M];
	}
	
	char key;
	
	bool quit = false;
	
	while (!quit) {
		
		cin >> key;	
		switch(key) {
		case 'N': 
			N(table);
			break;
		case 'L':
			L(table, M);
			break;
		case 'P': 
			P(table, M);
			break;
		case 'G':
			G(table, M);
			break;
		case 'D': 
			D(table, M);
			break;
		case 'S':
			S(table, M);
			break;
		case 'W': 
			W(table, M);
			break;
		case 'C':
			cin >> M;
			table = new int*[M];
			for (int i = 0; i < M; i++) {
				table[i] = new int[M];
			}
			C(table, M);
			break;
		case 'K':
			K(table, M);
			delete[] table;
			quit = true;
			break;

		default: 
			cout << "Default";
	}
	}
	
	
	return 0;
}
