#pragma once
int fact( int n) {
	int fn = 1;
	for (int i=1; i <= n; i++)  fn *= i;
	return fn;
}