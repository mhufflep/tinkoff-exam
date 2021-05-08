#include <iostream>

int		countTaller(int *employeesHeight, int employeesCount, int currIndex) {
	int count = 1;

	for (int j = currIndex; j < employeesCount; j++)
	{
		if (employeesHeight[j] > employeesHeight[currIndex])
		{
			count++;
			currIndex = j;
		}
	}
	return count;
}

void 	initIntArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

int main(void)
{
	int employeesCount;
	std::cin >> employeesCount;

	int *employeesHeight = new int[employeesCount];
	initIntArray(employeesHeight, employeesCount);
	for (int i = 0; i < employeesCount; i++)
	{
		std::cout << countTaller(employeesHeight, employeesCount, i) << " ";
	}
	std::cout << std::endl;

	delete [] employeesHeight;
	return (0);
}