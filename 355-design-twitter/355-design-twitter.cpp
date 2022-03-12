class Twitter {
public:
    
    /*
    [postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
                                                                                     ^
    [[1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
                                                ^
      
    hash map     followingPeople
    user  tweet  user
    1  -> 5,3       0
    2  -> 6         0
    
    Make a hash map of vector
    key = userId, value'vector' = tweets
        
    Assume we have a priority queue <= 10
    "maxHeap" to retrieve the most recent tweets
    
    If I followed someone
        I would insert his tweets into the pq //till the size become 10
    If I unfollowed someone
        I would remove his tweets from the pq
        
    HashMap, user->tweets, 
    HashMap, user -> hashSet
    MaxHeap
        
    */
    
    unordered_map<int, vector<pair<int, int>>> userTweets;
    unordered_map<int, unordered_set<int>> userFollowings;
    int curTime = 0;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({++curTime, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int, int>> newsFeedPQ;
        
        //get the cur user's tweets
        for(auto tweet : userTweets[userId]) {
            newsFeedPQ.push(tweet);
        }
        
        //push the followings' tweets
        for(auto user = userFollowings[userId].begin(); user != userFollowings[userId].end(); user++) 
        {
            int followeeId = *user;
            for(auto tweet : userTweets[followeeId]) {
                newsFeedPQ.push(tweet);
             }
        }
        
        vector<int> newFeedList;
        while(newsFeedPQ.size()) 
        {
            if(newFeedList.size() == 10)
                break;
            newFeedList.push_back(newsFeedPQ.top().second);
            newsFeedPQ.pop();
        }
          
        return newFeedList;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowings[followerId].erase(followeeId);
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