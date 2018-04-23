#include <stdio.h>
#include <stdlib.h>

// XXX: https://stackoverflow.com/questions/15720830/minimizing-steps-to-distribute-in-a-candies-in-a-circle/15722225
// XXX: https://stackoverflow.com/questions/44499262/given-an-array-of-integers-find-the-minimum-number-of-steps-to-make-each-value?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
// XXX: https://xoptutorials.com/index.php/2017/01/09/hackerearth173/
// XXX: https://www.careercup.com/question?id=17252672
// XXX: https://www.quora.com/What-is-the-approach-to-solve-SPOJ-com-Problem-BALIFE

#define MAX_SZ ((int)1E5)

int a[MAX_SZ] = { 0 };
int c[MAX_SZ] = { 0 };

#define max(a,b) (a>b?a:b);

int balance(int *a, int n) {
	int a_sum = 0;
	int r = -1;
	for (int i = 0; i < n; i++) {
		a_sum += a[i];
	}
	if (!(a_sum % n)) {
		int avg = a_sum / n;
		int c_max = 0;
		c[0] = 0;
		for (int i = 0; i < n - 1; i++) {
			c[i + 1] = c[i] + a[i] - avg;
			c_max = max(c_max, abs(c[i + 1]))
			;
		}
		r = c_max;
	}

	return r;
}

int main() {
	int n = 0;
	scanf("%d\n", &n);
	while (n != -1) {
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
		}
		int r = balance(a, n);

		printf("%d\n", r);

		while (scanf("%d\n", &n) != 1) {
		}
	}
	return EXIT_SUCCESS;
}
