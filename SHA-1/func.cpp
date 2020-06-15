#include <iostream>
#include <math.h>
#include <string.h>

void init(char* input) {
	int i;
	for (i = 0; i <= 256; i++) {
		input[i] = '\0';
	}
}

void Ox2B(char A16, int* p_input, int i) {
	if (A16 == '0') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == '1') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 1;
	}
	if (A16 == '2') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == '3') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 1;
	}
	if (A16 == '4') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == '5') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 1;
	}
	if (A16 == '6') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == '7') {
		p_input[0 + 4 * i] = 0;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 1;
	}
	if (A16 == '8') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == '9') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 1;
	}
	if (A16 == 'a' || A16 == 'A') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == 'b' || A16 == 'B') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 0;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 1;
	}
	if (A16 == 'c' || A16 == 'C') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == 'd' || A16 == 'D') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 0;
		p_input[3 + 4 * i] = 1;
	}
	if (A16 == 'e' || A16 == 'E') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 0;
	}
	if (A16 == 'f' || A16 == 'F') {
		p_input[0 + 4 * i] = 1;
		p_input[1 + 4 * i] = 1;
		p_input[2 + 4 * i] = 1;
		p_input[3 + 4 * i] = 1;
	}
}

char* B2Ox(int *A, int *B, int *C, int *D, int *E) {
	int i;
	int* arr;
	char *output;
	arr = (int*)malloc(40 * sizeof(int));
	output = (char*)malloc(40 * sizeof(char));
	if (arr) {
		for (i = 0; i < 8; i++) {
			arr[i] = 8 * A[4 * i] + 4 * A[4 * i + 1] + 2 * A[4 * i + 2] + A[4 * i + 3];
			arr[i + 8] = 8 * B[4 * i] + 4 * B[4 * i + 1] + 2 * B[4 * i + 2] + B[4 * i + 3];
			arr[i + 16] = 8 * C[4 * i] + 4 * C[4 * i + 1] + 2 * C[4 * i + 2] + C[4 * i + 3];
			arr[i + 24] = 8 * D[4 * i] + 4 * D[4 * i + 1] + 2 * D[4 * i + 2] + D[4 * i + 3];
			arr[i + 32] = 8 * E[4 * i] + 4 * E[4 * i + 1] + 2 * E[4 * i + 2] + E[4 * i + 3];
		}

		if (output) {
			for (i = 0; i < 40; i++) {
				if (arr[i] == 0) {
					output[i] = '0';
				}
				if (arr[i] == 1) {
					output[i] = '1';
				}
				if (arr[i] == 2) {
					output[i] = '2';
				}
				if (arr[i] == 3) {
					output[i] = '3';
				}
				if (arr[i] == 4) {
					output[i] = '4';
				}
				if (arr[i] == 5) {
					output[i] = '5';
				}
				if (arr[i] == 6) {
					output[i] = '6';
				}
				if (arr[i] == 7) {
					output[i] = '7';
				}
				if (arr[i] == 8) {
					output[i] = '8';
				}
				if (arr[i] == 9) {
					output[i] = '9';
				}
				if (arr[i] == 10) {
					output[i] = 'A';
				}
				if (arr[i] == 11) {
					output[i] = 'B';
				}
				if (arr[i] == 12) {
					output[i] = 'C';
				}
				if (arr[i] == 13) {
					output[i] = 'D';
				}
				if (arr[i] == 14) {
					output[i] = 'E';
				}
				if (arr[i] == 15) {
					output[i] = 'F';
				}
			}
		}
	}
	//free(arr);
	//arr = NULL;

	return output;
}

void D2B(int* p_input, int length, int p_length) {
	length = 4 * length;
	p_length = p_length - 11;

	if (length >= 1024) {
		p_input[p_length] = 1;
	    length -= 1024;
	}
	p_length++;
	if (length >= 512) {
		p_input[p_length] = 1;
	    length -= 512;
	}
	p_length++;
	if (length >= 256) {
		p_input[p_length] = 1;
	    length -= 256;
	}
	p_length++;
	if (length >= 128) {
		p_input[p_length] = 1;
	    length -= 128;
	}
	p_length++;
	if (length >= 64) {
		p_input[p_length] = 1;
	    length -= 64;
	}
	p_length++;
	if (length >= 32) {
		p_input[p_length] = 1;
	    length -= 32;
	}
	p_length++;
	if (length >= 16) {
		p_input[p_length] = 1;
	    length -= 16;
	}
	p_length++;
	if (length >= 8) {
		p_input[p_length] = 1;
	    length -= 8;
	}
	p_length++;
	if (length >= 4) {
		p_input[p_length] = 1;
	    length -= 4;
	}
	p_length++;
	if (length >= 2) {
		p_input[p_length] = 1;
	    length -= 2;
	}
	p_length++;
	if (length >= 1) {
		p_input[p_length] = 1;
	}
}
//上面都是进制转换函数和初始化函数

int* process(char* input) {//将十六进制输入处理为合适格式
	int i, length, p_length;
	int* p_input;
	p_input = (int*)malloc(512 * 3 * sizeof(int));
	length = strlen(input);
	p_length = 4 * length;

	if (p_input) {
		for (i = 0; i < length; i++) {
			Ox2B(input[i], p_input, i);
		}
		if (p_length % 512 != 448) {
			p_input[p_length] = 1;
			p_length = p_length + 1;
		}

		p_length = 4 * length;
		if (p_length > 960) {
			for (;p_length < 1536; p_length++) {
				p_input[p_length] = 0;
			}
		}
		if (p_length > 448) {
			for (;p_length < 1024; p_length++) {
				p_input[p_length] = 0;
			}
		}
		if (p_length > 0) {
			for (;p_length < 512; p_length++) {
				p_input[p_length] = 0;
			}
		}

		D2B(p_input, length, p_length);
	}

	return p_input;
}

void f1(int* B, int* C, int* D, int *arr) {//f1函数
	int i;
	for (i = 0; i < 32; i++) {
		arr[i] = (B[i] && C[i]) || ((1 - B[i]) && D[i]);
	}
}

void f2(int* B, int* C, int* D, int* arr) {//f2函数
	int i;
	for (i = 0; i < 32; i++) {
		arr[i] = B[i] ^ C[i] ^ D[i];
	}
}

void f3(int* B, int* C, int* D, int* arr) {//f3函数
	int i;
	for (i = 0; i < 32; i++) {
		arr[i] = (B[i] && C[i]) || (B[i] && D[i]) || (C[i] && D[i]);
	}
}

void Sk(int* array, int k, int *arr_this) {//循环左移k位
	int i, j;
	int save;
	
	if (arr_this) {
		for (i = 0; i < 32; i++) {
			arr_this[i] = array[i];
		}

		for (i = 0; i < k; i++) {
			save = arr_this[0];
			for (j = 0; j < 31; j++) {
				arr_this[j] = arr_this[j + 1];
			}
			arr_this[31] = save;
		}
	}
}

char* SHA_1(int* p_input, int num) {//主要算法
	int i, j, k, t;
	int* arr, * arr_s;
	arr = (int*)malloc(32 * sizeof(int));
	arr_s = (int*)malloc(32 * sizeof(int));
	char* output;

	int A[32] = { 0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1 };
	int B[32] = { 1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1 };
	int C[32] = { 1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0 };
	int D[32] = { 0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0 };
	int E[32] = { 1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0 };
	int H1[32], H2[32], H3[32], H4[32], H5[32];
	int Ha[32], Hb[32], Hc[32], Hd[32], He[32];
	int W[80][32];
	int K[4][32] = {
		{ 0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1 },
		{ 0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1 },
		{ 1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0 },
		{ 1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1,0,1,1,0 }
	};
	//初始化需要使用的数据

	for (i = 0; i < num; i++) {//num为消息分组数量
		for (j = 0; j < 32; j++) {
			H1[j] = A[j];
			H2[j] = B[j];
			H3[j] = C[j];
			H4[j] = D[j];
			H5[j] = E[j];
		}

		for (k = 0; k < 16; k++) {
			for (j = 0; j < 32; j++) {
				W[k][j] = p_input[512 * i + 32 * k + j];
			}
		}
		for (k = 16; k < 80; k++) {
			for (j = 0; j < 32; j++) {
				W[k][j] = W[k - 16][j] ^ W[k - 14][j] ^ W[k - 8][j] ^ W[k - 3][j];
			}
		}//计算W0-W79
		if (arr && arr_s) {
			for (t = 0; t < 80; t++) {//每组消息80轮变换
				for (j = 0; j < 32; j++) {
					Ha[j] = A[j];
					Hb[j] = B[j];
					Hc[j] = C[j];
					Hd[j] = D[j];
					He[j] = E[j];
				}
				if (t < 20) {
					for (k = 0; k < 32; k++) {
						f1(B, C, D, arr);
						Sk(A, 5, arr_s);
						A[k] = arr[k] ^ He[k] ^ arr_s[k] ^ W[t][k] ^ K[0][k];
						B[k] = Ha[k];
						Sk(Hb, 30, arr_s);
						C[k] = arr_s[k];
						D[k] = Hc[k];
						E[k] = Hd[k];
					}
				}
				if (t < 40) {
					for (k = 0; k < 32; k++) {
						f2(B, C, D, arr);
						Sk(A, 5, arr_s);
						A[k] = arr[k] ^ He[k] ^ arr_s[k] ^ W[t][k] ^ K[1][k];
						B[k] = Ha[k];
						Sk(Hb, 30, arr_s);
						C[k] = arr_s[k];
						D[k] = Hc[k];
						E[k] = Hd[k];
					}
				}
				if (t < 60) {
					for (k = 0; k < 32; k++) {
						f3(B, C, D, arr);
						Sk(A, 5, arr_s);
						A[k] = arr[k] ^ He[k] ^ arr_s[k] ^ W[t][k] ^ K[2][k];
						B[k] = Ha[k];
						Sk(Hb, 30, arr_s);
						C[k] = arr_s[k];
						D[k] = Hc[k];
						E[k] = Hd[k];
					}
				}
				if (t < 80) {
					for (k = 0; k < 32; k++) {
						f2(B, C, D, arr);
						Sk(A, 5, arr_s);
						A[k] = arr[k] ^ He[k] ^ arr_s[k] ^ W[t][k] ^ K[3][k];
						B[k] = Ha[k];
						Sk(Hb, 30, arr_s);
						C[k] = arr_s[k];
						D[k] = Hc[k];
						E[k] = Hd[k];
					}
				}
			}
		}
		for (k = 0; k < 32; k++) {
			A[k] = A[k] ^ H1[k];
			B[k] = B[k] ^ H2[k];
			C[k] = C[k] ^ H3[k];
			D[k] = D[k] ^ H4[k];
			E[k] = E[k] ^ H5[k];
		}
	}

	output = B2Ox(A, B, C, D, E);//二进制摘要转化为十六进制摘要输出
	return output;
}