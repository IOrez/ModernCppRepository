#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, std::string, double> find()				//��ȯŸ�Կ� std:tuple�� ����Ѵ�
{
	return std::make_tuple(1, "marius", 1234.5);
}

int main()
{
	auto [id, name, score] = find();					//������ ���ε��� ����� Ʃ���� ���� ���� ��ü�� ���� �����Ѵ�.

	if (auto [id, name, score] = find();score>100)		//����(decomposition)������ ����� if�� �Ǵ� switch�� ������ ��ȯ�� ���� ������ ���ε��Ѵ�.
	{
		std::cout << name << std::endl;
	}


}