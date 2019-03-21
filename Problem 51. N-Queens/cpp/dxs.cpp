class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        map<int, int> mapLine;
        map<int, int> mapAdd;
        map<int, int> mapSub;
        for (int i=0;i<=7;i++)mapLine[i]=0;
        for (int i=0;i<=14;i++)mapAdd[i]=0;
        for (int i=-7;i<=7;i++)mapSub[i]=0;
        
        vector<vector<string>> vec2dRecord;
        vector<string> vecCurrentRecord(n,string(n,'.'));
        
        getResult(0, &mapLine, &mapAdd, &mapSub, n, &vec2dRecord, &vecCurrentRecord);
        
        return vec2dRecord;
    }
    
private:
    int getResult(int i32Queens, map<int, int>* pmapLine, map<int,
                  int>* pmapAdd, map<int, int>* pmapSub, int i32Sum, 
                  vector<vector<string>>* pvec2dRecord, vector<string>* pvecCurrentRecord)
    {
        if (i32Queens==i32Sum)
        {
            (*pvec2dRecord).push_back(*pvecCurrentRecord);
            return 1;
        }
        int i32Result = 0;
        
        for (int i32Locality=0;i32Locality<i32Sum;i32Locality++)
        {
            if((*pmapLine)[i32Locality]==0
              &&(*pmapAdd)[i32Locality+i32Queens]==0
              &&(*pmapSub)[i32Locality-i32Queens]==0)
            {
                (*pmapLine)[i32Locality]=(*pmapAdd)[i32Locality+i32Queens]=(*pmapSub)[i32Locality-i32Queens]=1;
                (*pvecCurrentRecord)[i32Queens][i32Locality]='Q';
                i32Result+=getResult(i32Queens+1,pmapLine,pmapAdd,pmapSub, i32Sum,
                                    pvec2dRecord,pvecCurrentRecord);
                (*pmapLine)[i32Locality]=(*pmapAdd)[i32Locality+i32Queens]=(*pmapSub)[i32Locality-i32Queens]=0;
                (*pvecCurrentRecord)[i32Queens][i32Locality]='.';
            }
        }
        return i32Result;
    }
};