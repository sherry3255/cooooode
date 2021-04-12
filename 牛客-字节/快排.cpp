class Solution {
public:
    void quickSort(vector<int>& arr, int l, int r) {
        if (l < r)
        {
            //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
            int i = l, j = r, x = arr[l];
            while (i < j)
            {
                while(i < j && arr[j] >= x) // 从右向左找第一个小于x的数
                    j--;  
                if(i < j) 
                    arr[i++] = arr[j];

                while(i < j && arr[i] < x) // 从左向右找第一个大于等于x的数
                    i++;  
                if(i < j) 
                    arr[j--] = arr[i];
            }
            arr[i] = x;
            quickSort(arr, l, i - 1); // 递归调用 
            quickSort(arr, i + 1, r);
        }
    }
    
    vector<int> MySort(vector<int>& arr) {
        if(arr.size() <= 1) //过滤简单情况
            return arr;
        quickSort(arr, 0, arr.size() - 1);
        return arr;
    }
};