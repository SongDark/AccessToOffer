/*
    二维数组的元素满足每行每列递增排序，要求在数组中查找某数是否存在.
    思路：
        从右上角开始，如果该数字大于目标，则目标不可能出现在这一列，如果小于目标，说明目标不可能出现在这一行；
        同理，从左下角开始，如果该数字大于目标，则目标不可能出现在这一行，如果小于目标，说明目标不可能出现在这一列。
*/

# include<iostream>
# include<vector>
using namespace std;

class Solution{
public:
    bool Find(int target, vector<vector<int> > mat){
        if(mat.empty())
            return false;
        int rows = mat.size(), cols = mat[0].size();

        for(int i = 0; i < rows; i++)
            if(mat[i].size() != cols)
                return false; // 防止矩阵错误
        
        int i = 0, j = cols - 1;
        while(i<rows && j>=0){
            if(mat[i][j] == target)
                return true;
            else if(mat[i][j] < target)
                i++;
            else 
                j--;
        }
        return false;
    }
};

int main(){
    vector<int> r1 = {1,2,8,9};
    vector<int> r2 = {2,4,9,12};
    vector<int> r3 = {4,7,10,13};
    vector<int> r4 = {6,8,11,15};
    vector<vector<int> > matrix = {r1, r2, r3, r4};

    // 测试：寻找 10
    int des = 10;
    Solution sol;
    if(sol.Find(4, matrix))
        printf("%d is found.\n", des);
    else
        printf("%d not found.\n", des);
}