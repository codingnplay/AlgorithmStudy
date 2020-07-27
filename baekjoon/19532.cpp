#include <iostream>

using namespace std;
int a, b, c, d, e, f, x, y;

int main()
{
	cin >> a >> b >> c >> d >> e >> f;
	
	y = (c * d - f * a) / (b * d - e * a);
	x = (c * e - b * f) / (a * e - b * d);
	cout << x << " " << y;
	return 0;
}
