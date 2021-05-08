#include <iostream>


void 	initFromStdin(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void 	initFromValue(int *arr, int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

int calculateTime(int *timeToEat, int eatersCount, int pizzaCount)
{
	int time;

	int *currTime = new int[eatersCount];
	initFromValue(currTime, eatersCount, 0);
	for (time = 0; pizzaCount > 0; time++)
	{
		for (int i = 0; i < eatersCount; i++)
		{
			if (currTime[i] == timeToEat[i])
			{
				pizzaCount--;
				if (pizzaCount == 0)
				{
					delete [] currTime;
					return (time);
				}
				currTime[i] -= 2 * timeToEat[i];
			}
			currTime[i]++;
		}
	}
	delete [] currTime;
	return (time);
}


int main(void)
{
	int time;
	int pizzaCount, eatersCount;

	std::cin >> pizzaCount >> eatersCount;

	int *timeToEat = new int[eatersCount];
	initFromStdin(timeToEat, eatersCount);

	time = calculateTime(timeToEat, eatersCount, pizzaCount);	
	std::cout << time << std::endl;
	return (0);
}