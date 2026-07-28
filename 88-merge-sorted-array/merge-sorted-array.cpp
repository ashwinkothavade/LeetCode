class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>a(m,0);
        for(int i=0;i<m;i++){
            a[i]=nums1[i];
        }
        int i=0;
        int j=0;
        while(i<m&&j<n){
            if(a[i]<nums2[j]){
                nums1[i+j]=a[i];
                i++;
            }else{
                nums1[i+j]=nums2[j];
                j++;
            }
        }
        while(i<m){
            nums1[i+j]=a[i];
            i++;
        }
        while(j<n){
            nums1[i+j]=nums2[j];
            j++;
        }
    }
};