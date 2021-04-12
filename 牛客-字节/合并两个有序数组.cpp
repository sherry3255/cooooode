//双指针法，从A、B数组的末尾开始遍历，将较大者保存到另一个指针指向的新A数组的末尾：
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a = m-1;
        int b = n-1;
        for(int i = m+n-1 ; i >= 0 ; i--)//需要填m+n次
        {
            if(b<0||(a>=0&&A[a]>=B[b]))
            //B数组中的数全部用完了就填A数组中的数 a数组中的数没有用完，并且A数组的数大
            {
                A[i]=A[a];
                a--;
            }
            else
            {
                A[i]=B[b];
                b--;
            }
        }
    }
};