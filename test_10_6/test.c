typedef int DataType;
struct Node
{
	struct Node* _firstChild1; // 第一个孩子结点
	struct Node* _pNextBrother; // 指向其下一个兄弟结点
	DataType _data; // 结点中的数据域
};