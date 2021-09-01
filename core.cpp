

namespace my_math
{
    // ���飬 ���鳤�ȣ� ����Ԫ��
    int seek1(const int* list, int length, int ele)
    {
        // ˳�����
        for (int i = 0; i < length; ++i) {
            if (*(list+i) == ele) return i;
        }
        return -1;
    }

    int seek2(const int* list, int length, int ele)
    {
        // ���ֲ���
        int left = 0, right = length-1;
        int i = (left + right) / 2;
        while (*(list+i) != ele)
        {
            if (*(list + i) > ele) right = i;
            else left = i;
            i = (left + right) / 2;
            if (left == right) return -1;
        }
        return i;
    }
}