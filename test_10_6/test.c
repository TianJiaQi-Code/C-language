typedef int DataType;
struct Node
{
	struct Node* _firstChild1; // ��һ�����ӽ��
	struct Node* _pNextBrother; // ָ������һ���ֵܽ��
	DataType _data; // ����е�������
};