// 2 Спосіб --- "Рекурсивний"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>

void value_elements(int* b, const int elements, int Low, int High, int index);
void vuvestu(int* b, const int elements, int index);
int ymova(int* b, const int elements, int index, int sum);
int suma(int* b, const int elements, int index, int sum);

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
	const int elements = 22;
	int b[elements];

	int Low = -40;
	int High = 50;

	value_elements(b, elements, Low, High, 0);

	std::cout << "сформований масив: " << std::endl;
	std::cout << std::endl;
	vuvestu(b, elements, 0);

	std::cout << std::endl;
	std::cout << std::endl;

	int kilkist = ymova(b, elements, 0, 0);

	std::cout << "Модифікований масив: " << std::endl;
	std::cout << std::endl;
	vuvestu(b, elements, 0);

	std::cout << std::endl;
	std::cout << std::endl;

	int value = suma(b, elements, 0, 0);

	std::cout << "Сума елементів які задовольняють вказаному критерію: " << value << std::endl;
	std::cout << std::endl;
	std::cout << "Кількість елементів які задовольняють вказаному критерію: " << kilkist << std::endl;

	return 0;
}

void value_elements(int* b, const int elements, int Low, int High, int index)
{
	b[index] = Low + rand() % (High - Low + 1);
	if (index < elements - 1)
		value_elements(b, elements, Low, High, index + 1);

}

void vuvestu(int* b, const int elements, int index)
{
	std::cout << std::setw(5) << b[index];
	if (index < elements - 1)
		vuvestu(b, elements, index + 1);
	else;
}

int ymova(int* b, const int elements, int index, int sum)
{
	if (b[index] % 5 || b[index] == 0)
		sum += 1;
	else
		b[index] = 0;
	if (index < elements - 1)
		return ymova(b, elements, index + 1, sum);
	else
		return sum;
}

int suma(int* b, const int elements, int index, int sum)
{
	sum += b[index];
	if (index < elements - 1)
		return suma(b, elements, index + 1, sum);
	else
		return sum;
}
