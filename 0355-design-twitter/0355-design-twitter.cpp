class Twitter {
    struct Tweet{
        int tweetId;
        int time;
        Tweet(int id,int t): tweetId(id),time(t){};
    };


    int time;

    unordered_map<int,vector<Tweet>>tweets;
    unordered_map<int,unordered_set<int>>following;

    class comp{
        public:
            bool operator()(const Tweet&a,const Tweet&b){
                return a.time>b.time;
            }
    };



public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId,time++));
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet,vector<Tweet>,comp> mainHeap;
        for (auto& tweet : tweets[userId]) {
            mainHeap.push(tweet);
            if (mainHeap.size() > 10) mainHeap.pop();
        }
        for (int followeeId : following[userId]) {
            for (auto& tweet : tweets[followeeId]) {
                mainHeap.push(tweet);
                if (mainHeap.size() > 10) mainHeap.pop();
            }
        }
        vector<int> result;
        while (!mainHeap.empty()) {
            result.push_back(mainHeap.top().tweetId);
            mainHeap.pop();
        }

        reverse(result.begin(), result.end()); // Most recent tweet first
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId== followeeId) return;

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId)!= following.end())
            following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */