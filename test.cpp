#include <iostream>
#include <string>

class container
{
	container(void): box(nullptr), len(0), index(0){};
public:


private:
	int *box{};
	int len{};
	int index{};
};

int main(){
	std::string a, b;
	std::cin >> a >> b;

	std::cout << a + b << '\n';
	//std::cout << a << '\n';
}
