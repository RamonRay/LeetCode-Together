class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto i=nums1.begin();
        auto j=nums2.begin();
        
        while(nums1.size()>m)nums1.pop_back();
        
        while(j!=nums2.end())
        {
            if(i==nums1.end())
            {
                nums1.insert(i, j, nums2.end());
                break;
            }
            else if(*i<*j)
            {
                i++;
            }
            else
            {
                nums1.insert(i, j, j+1);
                j++;
            }
        }
    }
};