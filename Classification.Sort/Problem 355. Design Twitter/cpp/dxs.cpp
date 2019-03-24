class Twitter 
{
private:
    #define MAX_PULL_NUM (10)
    #define FATHER(x) (x>>1)
    #define L_SON(x) (x<<1)
    #define R_SON(x) ((x<<1)+1)
    
    int i32TimeStamp;
    int i32NumOfUsers;
    unordered_map<int, set<int>> mapFollow;
    
    struct stNews
    {
        int i32Order;
        int i32NewsName;
        stNews(int i32Name, int i32Time): i32Order(i32Time), i32NewsName(i32Name){}
    };
    
    struct stUserNode
    {
        int i32NewestOrder()
        {
            if(vecContentPerUser.size()==0)return -1;
            return vecContentPerUser[vecContentPerUser.size()-1].i32Order;
        }
        vector<stNews> vecContentPerUser;
    };
     
    vector<stUserNode> vecGetOnesNews;
    struct stPriorityHeap
    {
        vector<stUserNode> vecHeap;
        void swap(stUserNode& a, stUserNode& b)
        {
            stUserNode stTemp = a;
            a = b;
            b = stTemp;
        }
        void MaxHeapify(int i32Idx)
        {
            if (i32Idx>vecHeap.size()-1)
            {
                return;
            }
            int i32MaxIdx = i32Idx;
            int i32MaxValue = vecHeap[i32Idx].i32NewestOrder();
            
            if(L_SON(i32Idx)<=vecHeap.size()-1)
            {
                if (vecHeap[L_SON(i32Idx)].i32NewestOrder()>i32MaxValue)
                {
                    i32MaxIdx =  L_SON(i32Idx);
                    i32MaxValue = vecHeap[L_SON(i32Idx)].i32NewestOrder();
                }
            }
            if(R_SON(i32Idx)<=vecHeap.size()-1)
            {
                if (vecHeap[R_SON(i32Idx)].i32NewestOrder()>i32MaxValue)
                {
                    i32MaxIdx =  R_SON(i32Idx);
                    i32MaxValue = vecHeap[R_SON(i32Idx)].i32NewestOrder();
                }
            }
            if(i32MaxIdx!=i32Idx)
            {
                swap(vecHeap[i32MaxIdx], vecHeap[i32Idx]);
                MaxHeapify(i32MaxIdx);
            }
            else
            {
                return;
            }
        }
        
        void buildHeap(int i32FollowerId, unordered_map<int, set<int>> mapFollow, vector<stUserNode> vecGetOnesNews)
        {
            while(!vecHeap.empty())vecHeap.pop_back();
            vecHeap.push_back(stUserNode());
            for (auto it1=mapFollow[i32FollowerId].begin();it1!=mapFollow[i32FollowerId].end();++it1)
            {
                vecHeap.push_back(vecGetOnesNews[*it1]);
            }
            //cout<<vecGetOnesNews[i32FollowerId].vecContentPerUser.size()<<endl;
            vecHeap.push_back(vecGetOnesNews[i32FollowerId]);
            for (int i=(vecHeap.size()-1)/2;i>=1;i--)
            {
               MaxHeapify(i);
            }
        }
        
        int getTop()
        {
            if (vecHeap.size()<=1)return -1;
            if (vecHeap[1].vecContentPerUser.size()==0)return -1;
            int i32Result = vecHeap[1].vecContentPerUser[vecHeap[1].vecContentPerUser.size()-1].i32NewsName;
            vecHeap[1].vecContentPerUser.pop_back();
            MaxHeapify(1);
            return i32Result;
        }  
    };
    vector<stPriorityHeap> vecGetHeapById;   


public:
    /** Initialize your data structure here. */
    Twitter() 
    {
        i32TimeStamp=0;
        i32NumOfUsers=0;
        vecGetOnesNews.push_back(stUserNode());//user0 
        vecGetHeapById.push_back(stPriorityHeap());//user0 
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        int& i32UserId = userId;
        int& i32TwId = tweetId;
        if (i32UserId<0)
        {
            cout<<"Invalid User Id!"<<endl;
            return;
        }
        if(i32NumOfUsers<i32UserId)
        {
            int i32AddTimes = i32UserId-i32NumOfUsers;
            for(int i=0; i<i32AddTimes; i++)
            {
                vecGetOnesNews.push_back(stUserNode());
                vecGetHeapById.push_back(stPriorityHeap());
                i32NumOfUsers++;
            }
        }
        stUserNode& stNode = vecGetOnesNews[i32UserId];
        stNode.vecContentPerUser.push_back(stNews(i32TwId, ++i32TimeStamp));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {  
        if(i32NumOfUsers<userId)
        {
            int i32AddTimes = userId-i32NumOfUsers;
            for(int i=0; i<i32AddTimes; i++)
            {
                vecGetOnesNews.push_back(stUserNode());
                vecGetHeapById.push_back(stPriorityHeap());
                i32NumOfUsers++;
            }
        }
           
        vecGetHeapById[userId].buildHeap(userId, mapFollow, vecGetOnesNews);
        vector<int> vecResult;
        for (int i=0;i<MAX_PULL_NUM;i++)
        {
            int i32Temp = vecGetHeapById[userId].getTop();
            if(i32Temp!=-1)vecResult.push_back(i32Temp);
        }
        return vecResult;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        
        if(i32NumOfUsers<followerId)
        {
            int i32AddTimes = followerId-i32NumOfUsers;
            for(int i=0; i<i32AddTimes; i++)
            {
                vecGetOnesNews.push_back(stUserNode());
                vecGetHeapById.push_back(stPriorityHeap());
                i32NumOfUsers++;
            }
        }
        if(i32NumOfUsers<followeeId)
        {
            //cout<<i32NumOfUsers<<" "<<followeeId<<endl;
            //cout<<vecGetOnesNews.size()<<endl;
            int i32AddTimes = followeeId-i32NumOfUsers;
            for(int i=0; i<i32AddTimes; i++)
            {
                vecGetOnesNews.push_back(stUserNode());
                vecGetHeapById.push_back(stPriorityHeap());
                i32NumOfUsers++;
            }
            cout<<vecGetOnesNews.size()<<endl;
        }
        
        if(followerId!=followeeId)
        {
            mapFollow[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        if(followerId!=followeeId)
        {
            mapFollow[followerId].erase(followeeId);
        }   
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */