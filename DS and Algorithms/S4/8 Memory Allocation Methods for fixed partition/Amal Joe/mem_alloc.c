#include <stdio.h>

#define MAX 10

int p[MAX];
int block[MAX];

int n_p;
int n_block;

int input();
void allocate(int, int);
int first_fit();
int best_fit();
int worst_fit();


int main(int argc, char *argv[]) {
	int choice = input();
	switch (choice) {
		case 1:
			return first_fit();
		case 2:
			return best_fit();
		case 3:
			return worst_fit();
		default:
			printf("Invalid choice.\n");
			return 1;
	}
}

int input() {
	printf("Enter the no of processes:\n");
	scanf("%d", &n_p);
	printf("Enter the no of free blocks:\n");
	scanf("%d", &n_block);
	printf("Enter the size of processes (p0 p1 p2...):\n");
	for(int i = 0; i < n_p; i++) {
		scanf("%d", &p[i]);
	}
	printf("Enter the size of free blocks (b0 b1 b2...):\n");
	for(int i = 0; i < n_block; i++) {
		scanf("%d", &block[i]);
	}
	printf("\n");
	printf("The size of processes are:");
	for(int i = 0; i < n_p; i++) {
		printf("\t%dK", p[i]);
	}
	printf("\nThe size of free blocks are:");
	for(int i = 0; i < n_block; i++) {
		printf("\t%dK", block[i]);
	}
	printf("\n\n");
	int choice;
	printf("Choose a memory allocation algorithm (1 - First fit, 2 - Best fit, 3- Worst fit):\n");
	scanf("%d", &choice);
	printf("\n\n");
	return choice;
}

// allocate process at p_index to free block at block_index and print appropriate messages
void allocate(int p_index, int block_index){
	printf("P%d with size %dK is allocated to free block %d with size %dK", p_index, p[p_index], block_index, block[block_index]);
	block[block_index] -= p[p_index];
	printf("\nNow free block sizes become:");
	for (int i = 0; i < n_block; i++) {
		printf("\t%dK", block[i]);
	}
	printf("\n\n");
}

int first_fit() {
	int c = 0;
	for (int i = 0; i < n_p; i++) {
		for (int j = 0; j <= n_block; j++) {
            // allocate the first available free space which can accomodate the process
			if (block[j] >= p[i]) {
				c++;
				allocate(i, j);
				break;
			}
		}
	}
	if (c != n_p) {
		printf("First fit allocation failed. Not all processes were allocated.\\n");
		return 1;
	}
	return 0;
}

int best_fit() {
	for (int i = 0; i < n_p; i++) {
		int selected = -1;
		for (int j = 0; j <= n_block; j++) {
            // select the free block with minimum size which can accomodate the process
			if (block[j] >= p[i]) {
				if (selected == -1 || block[j] < block[selected]) {
					selected = j;
				}
			}
		}
		if (selected == -1) {
			printf("Best fit allocation failed. No free space available for P%d with size %dK\n", i, p[i]);
			return 1;
		}
		allocate(i, selected);
	}
	return 0;
}

int worst_fit() {
	for (int i = 0; i < n_p; i++) {
		int selected = -1;
		for (int j = 0; j <= n_block; j++) {
            // select the free block with maximum size which can accomodate the process
			if (block[j] >= p[i]) {
				if (selected == -1 || block[j] > block[selected]) {
					selected = j;
				}
			}
		}
		if (selected == -1) {
			printf("Worst fit allocation failed. No free space available for P%d with size %dK\n", i, p[i]);
			return 1;
		}
		allocate(i, selected);
	}
	return 0;
}

/*
4
5
90 20 50 200
50 100 90 200 50
2

*/