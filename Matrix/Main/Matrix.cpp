#include "Matrix.h"

void menu() {
	bool ret;
	int mode, M, N;
	double** A = nullptr, ** B = nullptr, **C = nullptr;
	system("chcp 1251");
	do {
		system("cls");
		cout << "1: Сумма матриц\n2: Умножение матриц:\n3: Заполнение п.ч.с.\n4: Заполнение змейкой\n";
		cout << "Введите число: ";
		cin >> mode;
		system("cls");
		while (cin.fail()) {  //  проверка на неверный ввод
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Неверный ввод\n";
			cout << "1: Сумма матриц\n2: Умножение матриц:\n3: Заполнение п.ч.с.\n4: Заполнение змейкой\n";
			cout << "Введите число: ";
			cin >> mode;
			system("cls");
		}
		switch (mode) {
		case 1:
			ret = matrix1(&A, M, N, mode);
			if (ret == true) {
				ret = matrix2(&B, M, N, mode);
				if (ret == true) sum(A, B, M, N);
				else cout << "Неверный ввод";
			}
			else cout << "Неверный ввод";
			break;
		case 2:
			ret = matrix1(&A, M, N, mode);
			if (ret == true) {
				ret = matrix2(&B, M, N, mode);
				if (ret == true) mul(A, B, &C, M, N);
				else cout << "Неверный ввод";
			}
			else cout << "Неверный ввод";
			break;
		case 3:
			snall(&A, M, N);
			break;
		case 4:
			snake(&A, M, N);
			break;
		case -1:
			break;
		default:
			cout << "Неверный ввод";
			break;
		}
		cout << endl;
		system("pause");
	} while (mode != -1);
}

bool input(int& M, int& N, int mode) {
	bool ret = true;
	if (mode == 2) {
		cout << "Кол-во строк: " << M << endl;
		cout << "Введите кол-во столбцов: ";
		cin >> N;
		if (cin.fail() || N <= 0) {  //  проверка на неверный ввод
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			ret = false;
		}
		system("cls");
	}
	else {
		cout << "Введите кол-во строк: ";
		cin >> M;
		if (cin.fail() || M <= 0) {  //  проверка на неверный ввод
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			ret = false;
		}
		else {
			cout << "Введите кол-во столбцов: ";
			cin >> N;
			if (cin.fail() || N <= 0) {  //  проверка на неверный ввод
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("cls");
				ret = false;
			}
			system("cls");
		}
	}
	return ret;
}

bool matrix1(double*** A, int& M, int& N, int mode) {
	bool ret = true;
	mode = 0;
	cout << "Матрица А\n";
	ret = input(M, N, mode);
	if (ret == true) {
		*A = new double* [M];
		for (int i = 0; i < M; i++) {
			(*A)[i] = new double[N];
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << "Введите число для матрицы A: ";
				cin >> (*A)[i][j];
				system("cls");
				if (cin.fail()) {  //  проверка на неверный ввод
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					ret = false;
					break;
				}
			}
			if (ret == false) break;
		}
	}
	return ret;
}

bool matrix2(double*** B, int& M, int& N, int mode) {
	bool ret = true;
	cout << "Матрица B\n";
	if (mode != 1) ret = input(M, N, mode);
	else system("cls");
	if (ret == true) {
		*B = new double* [M];
		for (int i = 0; i < M; i++) {
			(*B)[i] = new double[N];
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cout << "Введите число для матрицы B: ";
				cin >> (*B)[i][j];
				system("cls");
				if (cin.fail()) {  //  проверка на неверный ввод
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					ret = false;
					break;
				}
			}
			if (ret == false) break;
		}
	}
	return ret;
}

void sum(double** A, double** B, int& M, int& N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] += B[i][j];
		}
	}
	print(A, M, N);
	clear_A(A, M);
	clear_B(B, M);
}

void mul(double** A, double** B, double*** C, int& M, int& N) {
	*C = new double* [M];
	for (int i = 0; i < M; i++) {
		(*C)[i] = new double[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			(*C)[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				(*C)[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	print(*C, M, N);
	clear_A(A, M);
	clear_B(B, M);
	clear_C(*C, M);
}

void snall(double*** A, int& M, int& N) {
	int i = 0, j = 0, up, down = -1, left = 0, right, count = 0;
	cout << "Введите кол-во строк: ";
	cin >> M;
	cout << "Введите кол-во столбцов: ";
	cin >> N;
	system("cls");
	up = M;
	right = N;
	(*A) = new double* [M];
	for (int i = 0; i < M; i++) {
		(*A)[i] = new double[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			(*A)[i][j] = 0;
		}
	}
	while (count < M * N) {
		while (i < up) {
			(*A)[i][j] = count;
			count++;
			i++;
		}
		i--;
		up = i;
		count--;
		while (j < right) {
			(*A)[i][j] = count;
			count++;
			j++;
		}
		j--;
		right = j;
		count--;
		while (i > down) {
			(*A)[i][j] = count;
			count++;
			i--;
		}
		i++;
		down = i;
		count--;
		while (j > left) {
			(*A)[i][j] = count;
			count++;
			j--;
		}
		j++;
		left = j;
		count--;
	}
	print(*A, M, N);
	clear_A(*A, M);
}

void snake(double*** A, int& M, int& N) {
	int j = 0, count = 0;
	cout << "Введите кол-во строк: ";
	cin >> M;
	cout << "Введите кол-во столбцов: ";
	cin >> N;
	system("cls");
	(*A) = new double* [M];
	for (int i = 0; i < M; i++) {
		(*A)[i] = new double[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			(*A)[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++) {
		if (j == 0) {
			for (; j < N; j++) {
				(*A)[i][j] = count;
				count++;
			}
			j = N - 1;
		}
		else {
			for (; j >= 0; j--) {
				(*A)[i][j] = count;
				count++;
			}
			j = 0;
		}
	}
	print(*A, M, N);
	clear_A(*A, M);
}

void print(double** A, int& M, int& N) {
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			cout << A[i][j] << " ";
		}
		cout << A[i][N - 1] << endl;
	}
	for (int j = 0; j < N - 1; j++) {
		cout << A[M - 1][j] << " ";
	}
	cout << A[M - 1][N - 1];
}

void clear_A(double** A, int& M) {
	if (A != nullptr) {
		for (int i = 0; i < M; i++) {
			delete[] A[i];
		}
		delete[] A;
	}
}

void clear_B(double** B, int& M) {
	if (B != nullptr) {
		for (int i = 0; i < M; i++) {
			delete[] B[i];
		}
		delete[] B;
	}
}

void clear_C(double** C, int& M) {
	if (C != nullptr) {
		for (int i = 0; i < M; i++) {
			delete[] C[i];
		}
		delete[] C;
	}
}