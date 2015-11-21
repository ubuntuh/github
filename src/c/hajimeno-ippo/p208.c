#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int i, r;
	int line = 2;
	
	srand (time(NULL));
	for (i = 0; i < 10; i++) {
		r = rand() % line;
		printf("%d\n", r);
	}
}

