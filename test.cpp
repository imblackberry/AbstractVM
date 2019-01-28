#include <iostream>
int foo(float n){
	std::cout << "Foo = " << n << std::endl;
	n = 9;
	return n;
}

int foo2(float n){
	std::cout << "Foo2 = " << n << std::endl;
	return n;
}

int main(){
	std::function<int(float)> arr[2];
	std::function<int(float)> newf;
	newf = foo;
	newf(7);
	arr[0] = foo;
	arr[1] = foo2;
	for (int i = 0; i < 2; i++)
		arr[i](i);
	return 0;
}