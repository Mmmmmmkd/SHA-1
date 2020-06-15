//作业：SHA-1算法
//作者：M.kd
//邮箱：1132269071@qq.com

#include <iostream>

void init(char* input);//初始化字符串
int* process(char* input);//处理字符串成符合SHA-1算法要求形式
char* SHA_1(int* p_input, int num);//主要算法

int main()
{
	int i;
	int length, num = 1;
	char *input, *output;
	int* p_input;
	input = (char*)malloc(256 * sizeof(char));
	init(input);
	std::cout << "请输入256位以内十六进制消息\n";
	std::cin >> input;

	length = 4 * (int)strlen(input);
	p_input = process(input);
	
	if (length > 448) {
		num = 2;
	}
	if (length > 960) {
		num = 3;
	}

	output = SHA_1(p_input, num);
	for (i = 0; i < 40; i++) {
		std::cout << output[i];
	}
	std::cout << "\n";

	system("pause");
}
