// ���谴�������array������[left, right)�����е�Ԫ�ؽ�������
void QuickSort(int array[], int left, int right)
{
	if (right - left <= 1)
		return;
	// ���ջ�׼ֵ��array����� [left, right)�����е�Ԫ�ؽ��л���
	int div = partion(array, left, right);
	// ���ֳɹ�����divΪ�߽��γ������������� [left, div) �� [div+1, right)
	// �ݹ���[left, div)
	QuickSort(array, left, div);
	// �ݹ���[div+1, right)
	QuickSort(array, div + 1, right);
}