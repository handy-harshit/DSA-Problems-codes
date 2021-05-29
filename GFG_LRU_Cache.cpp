class LRUCache
{
    private:

    public:
    
    list<int> cache; // A linked List , behaving like a queue (push from back and removing from front)
    unordered_map<int,int> val; //to store values of keys
    unordered_map<int,list<int>::iterator> pos; //to store position/refernce of key inside a list 
    int capacity; 
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
    }
    
    //Function to return value corresponding to the key.
    
    //IMP -> if value is used it comes at first
    int get(int key)
    {
        //if find then erase it from between and bring it at first
        if(pos.find(key) != pos.end()) {
            cache.erase(pos[key]); //erasse from between 
            cache.push_back(key); //bring at first
            pos[key] = std::prev(cache.end()); //udate the pos 
            return val[key]; //return key -> value
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // if key is present .. delete it from cache & later update the pos and val 
        if(pos.find(key) != pos.end()) 
            cache.erase(pos[key]);
            
        // if size equal remove from front     
        if(cache.size() == capacity) {
            pos.erase(cache.front());
            val.erase(cache.front());
            cache.pop_front();
        }
        
        //push value from back and update val and pos
        cache.push_back(key);
        pos[key] = std::prev(cache.end());
        val[key] = value;
    }
};