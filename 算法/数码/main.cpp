#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//��ȡ��λ����
int getFirstNum(int x) {
    int ans = 0;
    while (x > 0)
    {
        ans = x % 10;
        x /= 10;
    }
    return ans;
}

vector<int> getNum(int x) {
    vector<int> data;
    for (int i = 1; i <= x; i++) {
        if (x % i == 0) {
            data.push_back(getFirstNum(i));
        }
    }
    return data;
}
int dataNum[10] = { 0 };

struct MyPrint {
    void operator()(int num) {
        //cout << num << " ";
        dataNum[num - 1]++;
    }
};
//[1,r] ret->a[];
void calc(int r, int* data)
{
    for (int a = 1; a * a <= r; a++)    //ö��һ������a
    {
        int b = r / a;                //b�ķ�Χ�����i+1��Ϊ�˲����ظ������ҽ���r/i
        for (int j = 1; j <= r; j *= 10)   //ö��λ����ֱ����1�������ɸ�0�����������㣩
        {
            for (int k = 1; k <= 9; k++)   // ö����λ��
            {
                int x = max(j * k, a + 1);      //x�����λΪk��ʱ����½�
                int y = min((j * (k + 1)) - 1, b);  //y���Ͻ�
                if (y - x >= 0) data[k] += y - x + 1;  //���������ڣ������
            }
        }
        int tmp = getFirstNum(a);          //��a����λ
        data[tmp] += b - a + 1;            //�����˶��ٸ�a
    }
}


int main() {
    int l, r;
    
    cin >> l >> r;
    for (int i = l; i <= r; i++) {
        vector<int> data = getNum(i);
        //cout << i << ":";
        std::for_each(data.begin(), data.end(), MyPrint());
        //cout << endl;
    }
    for (size_t i = 0; i < 10; i++)
    {
        cout << dataNum[i] << endl;
    }
    return 0;
}