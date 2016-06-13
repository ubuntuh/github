// Accepted.
#include <cstdio>

int main(void)
{
	int c = 0, x = 0;
	for (int i = 0; i < 12; i++) {
		scanf("%c", &c);
		x = x << 1 ^ c < 0x50;
	}
	if (x < 672) printf("Si\n");
	else if (x < 882) printf("Mi\n");
	else if (x < 1192) printf("La\n");
	else if (x < 1202) printf("Re\n");
	else if (x < 1322) printf("So\n");
	else if (x < 1342) printf("Do\n");
	else printf("Fa\n");
	return 0;
}
