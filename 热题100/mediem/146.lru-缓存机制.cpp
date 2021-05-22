/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct DLinkedNode{
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0), value(0), prev(nullptr), next(nullptr){}
    DLinkedNode(int _key, int _value): key(_key),value(_value),prev(nullptr),next(nullptr){}
};
class LRUCache {
public:
// 首先使用哈希表进行定位，找出缓存项在双向链表中的位置，随后将其移动到双向链表的头部，即可在 O(1)O(1)O(1) 的时间内完成 get 或者 put 操作。
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        // 使用伪头部和伪尾部节点
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head-> next = tail;
        tail->prev = head;

    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key,value);
            // 添加进哈希表
            cache[key] = node;
            addToHead(node);
            size++;
            if(size > capacity){
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
        else{
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
};
// 时间复杂度为o(1),空间复杂度为哈希表的容量，哈希表和双向链表最多存储capacity+1个元素

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

