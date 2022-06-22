// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    vector<int> ch;
    int partition1(string &arr,int left,int right){
	int pivot_index=rand()%(right-left+1)+left;
    int pivot=arr[pivot_index]; //令陣列的最後一個元素是pivot
    swap(arr[pivot_index],arr[right]);
    int front1=left; //front1用來交換元素
    for(int cur=left;cur<=right;cur++){ //cur枚舉陣列的所有元素
        if(ch[arr[cur]]>ch[pivot]){ //如果當前的元素比pivot小，就擺到左邊
            swap(arr[cur],arr[front1]); //互換
            front1++; //替換的位置加1
        }
    }
    //把pivot換到目前陣列front1+1的位置，就可以確保在pivot左邊的元素都比pivot小
    swap(arr[front1],arr[right]);
    return front1;//把pivot回傳
}
void quick_sort(string &arr,int left,int right){
    if(right>left){
        int pivot = partition1(arr,left,right); //找到pivot
        quick_sort(arr,left,pivot-1); //分別對pivot左邊右邊的陣列做一次quick_sort，因為pivot一定在陣列的中間所以不用排序
        quick_sort(arr,pivot+1,right);
    }
}
    string frequencySort(string s) {
        ch=vector<int>(128,0);
        int m=s.size();
        for(int i=0;i<m;i++){
            ch[s[i]]++;
        }
        quick_sort(s,0,s.size()-1);
        return s;
    }
};