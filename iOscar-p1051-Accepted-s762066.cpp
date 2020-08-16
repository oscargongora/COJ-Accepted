#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int n, resp;
	scanf("%d", &n);
	resp = n - ceil(n/3.00);
	printf("%d\n", resp);
	return 0;
}
