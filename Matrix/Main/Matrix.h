#pragma once

#include <iostream>

using namespace std;

void menu();

bool input(int& M, int& N, int mode);
bool matrix1(double*** A, int& M, int& N, int mode);
bool matrix2(double*** B, int& M, int& N, int mode);

void sum(double** A, double** B, int& M, int& N);
void mul(double** A, double** B, double*** C, int& M, int& N);
void snall(double*** A, int& M, int& N);
void snake(double*** A, int& M, int& N);

void print(double** A, int& M, int& N);

void clear_A(double** A, int& M);
void clear_B(double** B, int& M);
void clear_C(double** C, int& M);