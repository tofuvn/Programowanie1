// Van The Ho

#include <iostream>

using namespace std;

int** initialize_board(int **board, int M) {
	board = new int*[M];
	
	for (int i = 0; i < M; i++) {
		board[i] = new int[M];
	}
	return board;	
}

long long sum_of_board(int **board, int M) {
	long long sum = 0;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++ ){
			sum += board[i][j];
		}
	}
	return sum;
};

void N(int **board) {
	int x, y, w;
	cin >> x >> y >> w;
	board[x][y] = w;
}

int** C(int **board, int M) {
	board = initialize_board(board, M);
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	return board;
}

void move_to_left(int *board, int M, int from, int distance) {
	// move array to left with distance 
	for (int i = from; i < M - distance; i++) {
		board[i] = board[i + distance];
	}
	
	// fill last (distance) elements with 0s
	for (int i = M - distance; i < M; i++) {
		board[i] = 0;
	}
}

void L(int **board, int M) {
	// Perform on each row
	for (int i = 0; i < M; i++) {
		int j = 0;
		while (j < M) {
			
			if (board[i][j] == 0) {
				// if we encounter a 0 element , we'll count how many 0s after it, 
				// if all 0s , we done with this row and go to next row, 
				// otherwise we move this row to left with distance equals how many 0s we encountered 			
				// we return to the element right before and check again
				
				int k = j + 1;
<<<<<<< HEAD
				int dist = 1;
				while (k <= M - 1 && board[i][k] == 0) {
					k++;
					dist++;
=======
				int count = 1;
				while (k <= M - 1 && board[i][k] == 0) {
					k++;
					count++;
>>>>>>> 2b5dc53bbd62b3142359434bbec42a4381931971
				}
				
				if (k == M) break;
			
<<<<<<< HEAD
				move_to_left(board[i], M, j, dist);
=======
				move_to_left(board[i], M, j, count);
>>>>>>> 2b5dc53bbd62b3142359434bbec42a4381931971
				j = max(0, j - 1);
								
			} else if (board[i][j] == board[i][j+1]) {
					// if we encounter a element and the elemenet right after is equals it , 
					// we double first elemment and move this row to left with distance 1 and 
					// we return to the element right before and check again
					board[i][j] *= 2;
					move_to_left(board[i], M, j+1, 1);
					j = max(0, j - 1);
			} else {
				// if either 0 or 2 element equals , check next element
				j++;
			}
		}
	}
}

// The ideal of this function is so simple
// When the people swipe RIGHT , it actually do the same as peole swipe LEFT, just change the direction from LEFT to RIGHT
// so what we only need to do is REVERSE the board from LEFT to RIGHT
void reverseboard(int **board, int M) {
	int temp = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < (M / 2); j++) {
			temp = board[i][j];
			board[i][j] = board[i][M - 1 - j];
			board[i][M -1 -j] = temp;
		}
	}
}

// swipe DOWN is the same as first ROTATE the board 90 degrees clockwise and do the swipe LEFT ,
// and after do ROTATE the board 90 degrees counterclock wise ( or 3 times ROTATE 90 clockwise)
// swipe UP analogous
void rotationMatrix90ClockWise(int **board, int M) {
	int temp;
	for (int i = 0; i < M / 2; i++) {
        for (int j = i; j < M - i - 1; j++) {
 
			temp = board[i][j];
            board[i][j] = board[M - 1 - j][i];
            board[M - 1 - j][i] = board[M - 1 - i][M - 1 - j];
            board[M - 1 - i][M - 1 - j] = board[j][M - 1 - i];
            board[j][M - 1 - i] = temp;
        }
    }
}

void rotationMatrix90CounterClockWise(int **board,  int M) {
	
	int temp = 0;
    for (int x = 0; x < M / 2; x++) {
        for (int y = x; y < M - x - 1; y++) {

            temp = board[x][y];
            board[x][y] = board[y][M - 1 - x];
            board[y][M - 1 - x] = board[M - 1 - x][M - 1 - y];
            board[M - 1 - x][M - 1 - y] = board[M - 1 - y][x];
            board[M - 1 - y][x] = temp;
        }
    }
}




void W(int **board, int M) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}
}

void P(int **board, int M) {
	reverseboard(board, M); 
	L(board, M);
	reverseboard(board, M);           
} 


void D(int **board, int M) {
	rotationMatrix90ClockWise(board, M);
	L(board, M);
	rotationMatrix90CounterClockWise(board, M);
}



void G(int **board, int M) {
	rotationMatrix90CounterClockWise(board, M);
	L(board,M);
	rotationMatrix90ClockWise(board, M);
}

void S(int **board, int M) {
	cout << sum_of_board(board, M) << endl;
}


int main() {
	
	int M;
	
	cin >> M;
	
	int **board = NULL;
	
	board  = initialize_board(board, M);
	
	char key;
	
	bool quit = false;
	
	while (!quit) {
		
		cin >> key;	
		switch(key) {
		case 'N': 
			N(board);
			break;
		case 'L':
			L(board, M);
			break;
		case 'P': 
			P(board, M);
			break;
		case 'G':
			G(board, M);
			break;
		case 'D': 
			D(board, M);
			break;
		case 'S':
			S(board, M);
			break;
		case 'W': 
			W(board, M);
			break;
		case 'C':
			cin >> M;
			board = C(board, M);
			break;
		case 'K':
			S(board, M);
			delete[] board;
			quit = true;
			break;

		default: 
			cout << "Default";
	}
	}
	
	
	return 0;
}
