typedef int BTDataType;
// 二叉链
struct BinaryTreeNode
{
	struct BinTreeNode* _pLeft; // 指向当前节点左孩子
	struct BinTreeNode* _pRight; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
};

// 三叉链
struct BinaryTreeNode
{
	struct BinTreeNode* _pParent; // 指向当前节点的双亲
	struct BinTreeNode* _pLeft; // 指向当前节点左孩子
	struct BinTreeNode* _pRight; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
};