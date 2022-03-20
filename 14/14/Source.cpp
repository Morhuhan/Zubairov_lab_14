#include <stdio.h>
#include <math.h>

int function_1(int x) {            // Считает сколько всего цифр в двоичной записи числа

	int c = 0;
	int i = 0;
	int flag = 0;

	while (flag != 1) {

		c = x >> i;
		c = (x >> ((sizeof(int) * 8) - i - 1));

		if (c > 0) {
			flag = 1;
		}

		i++;
	}
	return sizeof(int) * 8 - i + 1;
}


int function_2(int a, int b, int size_a, int size_b) { 

	int check = a;
	int bufer = a;
	int destroyer = pow(2, size_a);          // Уничтожает вышедшие за рамки буфера (size_a)

	for (int i = 0; i < 9; i++) {
		check = check >> (size_a - size_b);  // Сдвиг числа 'a' до тех пор, пока оно не станет нужного размера ( = 'b')
		
		if (check == b) {
			printf("ok!\n");
			return 0;
		}

		bufer = bufer << 1;					// В буфере хранится число 'a' постепенно побитово сдвигающееся вправо

		if ((bufer & destroyer) > 0) {
			bufer = bufer - destroyer;
		}

		check = bufer;
	}

	printf("net!\n");
}

void main() {

	int a = 0;
	int b = 0;

	printf("Enter the first number\n");
	scanf_s("%d", &a);

	printf("Enter the second number\n");
	scanf_s("%d", &b);

	function_2(a, b, function_1(a), function_1(b));

}

