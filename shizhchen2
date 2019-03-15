class Solution {
    public void sortColors(int[] nums) {
        partition(nums,0,nums.length-1);
    }
    public void partition(int[] data,int first,int end){
        if(first<end){
            int base = data[first];
            int low = first;
            int high = end;
            while(low<high){
                while(low<high&&base<=data[high]){
                    high--;
                }
                data[low] = data[high];
                while(low<high&&data[low]<=base){
                    low++;
                }
                data[high]=data[low];
            }
            data[low]=base;
            partition(data,first,low);
            partition(data,low+1,end);  
        }
    }
}
