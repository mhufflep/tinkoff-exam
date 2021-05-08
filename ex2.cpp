#include <iostream>
#include <string>

bool
isVowel(const char c)
{
	std::string vowels = "aeiouy";

	return (!(vowels.find(c) == std::string::npos));
}

bool
isDifferent(const char c1, const char c2)
{
	return ((isVowel(c1) && !isVowel(c2)) || (!isVowel(c1) && isVowel(c2)));
}

int main(void)
{
	std::string name;
	bool isGoodName;

	std::cin >> name;
	isGoodName = true;
	for (size_t i = 0; i < name.length() - 1 && isGoodName; i++)
	{
		isGoodName = isDifferent(name[i], name[i + 1]);
	}
	if (isGoodName)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return (0);
}