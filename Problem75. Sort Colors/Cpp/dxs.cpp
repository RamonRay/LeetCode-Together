//#include <iostream>
//#include <random>

//using std::cout; using std::endl;
using std::default_random_engine;


class Solution {
public:

    void sortColors(vector<int>& nums) {
        vector<int>& veci32Values=nums;
        quickSort(0, veci32Values.size()-1, veci32Values, cmpInt32IfSmall);
    }
        
        
private:
    static bool cmpInt32IfSmall(int i32V1, int i32V2)
    {
        return (i32V1<i32V2);
    }
    void quickSort(int i32Left, int i32Right, vector<int>& veci32Values, bool (*cmpInt32)(int x, int y))
    {
        if (i32Right<=i32Left)return;
        
        default_random_engine dreEngine;
        int i32MidIdx = i32Left +(dreEngine() % (i32Right-i32Left+1));
        //int i32MidIdx = (i32Left+i32Right)>>1;
        int i32Key = veci32Values[i32MidIdx];
        int p= i32Left-1;
        int i32MidNewId;
            
        for (int i=i32Left; i<=i32Right; i++)
        {
            if(cmpInt32(veci32Values[i],i32Key) || veci32Values[i]==i32Key)//<= is important
            {
                p++;
                if(veci32Values[i]!=veci32Values[p])
                {
                    veci32Values[i] = veci32Values[i]^veci32Values[p];
                    veci32Values[p] = veci32Values[i]^veci32Values[p];
                    veci32Values[i] = veci32Values[i]^veci32Values[p];
                }
                if(veci32Values[p]== i32Key)
                {
                    i32MidNewId = p;
                }
            }
        }

        if(veci32Values[i32MidNewId]!=veci32Values[p])
        {
            veci32Values[i32MidNewId] = veci32Values[i32MidNewId]^veci32Values[p];
            veci32Values[p] = veci32Values[i32MidNewId]^veci32Values[p];
            veci32Values[i32MidNewId] = veci32Values[i32MidNewId]^veci32Values[p];
        }
        
        quickSort(i32Left,p-1, veci32Values, cmpInt32);
        quickSort(p+1, i32Right, veci32Values, cmpInt32);    
    }
        
};