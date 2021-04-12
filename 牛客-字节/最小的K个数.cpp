
/*
对数组[l, r]一次快排partition过程可得到，[l, p), p, [p+1, r)三个区间,[l,p)为小于等于p的值
[p+1,r)为大于等于p的值。
然后再判断p，利用二分法

    如果[l,p), p，也就是p+1个元素（因为下标从0开始），如果p+1 == k, 找到答案
    2。 如果p+1 < k, 说明答案在[p+1, r)区间内，
    3， 如果p+1 > k , 说明答案在[l, p)内 
*/
class Solution {
public:
    int partition(vector<int> &input, int l, int r) {
        int pivot = input[r-1];
        int i = l;
        for (int j=l; j<r-1; ++j) {
            if (input[j] < pivot) {
                swap(input[i++], input[j]);
            }
        }
        swap(input[i], input[r-1]);
        return i;
 
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k > input.size()) return ret;
         int l = 0, r = input.size();
        while (l < r) {
            int p = partition(input, l, r);
            if (p+1 == k) {
                return vector<int>({input.begin(), input.begin()+k});
            }
            if (p+1 < k) {
                l = p + 1;
            }  
            else {
                r = p;
            }
 
        }
        return ret;
    }
};

/*
时间复杂度：平均时间复杂度为O(n),每次partition的大小为n+n/2+n/4+... = 2n,最坏时间复杂度为O(n^2), 因为每次partition都只减少一个元素
空间复杂度：O(1)
*/