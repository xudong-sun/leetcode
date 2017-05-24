'''
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
'''


class UseListNode(object):
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

class LRUCache(object):
    def __init__(self, capacity):
        self.size = 0
        self.capacity = capacity
        self.use_list_head = self._use_list_tail = UseListNode(0)
        self.use_list_mapping = {}
        self.dict = {}

    def get(self, key):
        if key in self.dict:
            self._update_use_list(key)
            return self.dict[key]
        else: return -1

    def put(self, key, value):
        if key in self.dict:
            self._update_use_list(key)
            self.dict[key] = value
        else:
            if self.size == self.capacity:
                self._evict_key(self.use_list_head.next.val)
                self.size -= 1
            self.dict[key] = value
            self.use_list_mapping[key] = self._append_use_list(key)
            self.size += 1

    def _append_use_list(self, key):
        node = UseListNode(key)
        self._use_list_tail.next = node
        node.prev = self._use_list_tail
        self._use_list_tail = node
        return node
    def _update_use_list(self, key):
        node = self.use_list_mapping[key]
        self.use_list_mapping[key] = self._append_use_list(key)
        n1, n2 = node.prev, node.next
        if n1: n1.next = n2
        if n2: n2.prev = n1
        del node
    def _evict_key(self, key):
        del self.dict[key]
        del self.use_list_mapping[key]
        self.use_list_head = self.use_list_head.next

if __name__ == '__main__':
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(2, 2)
    print cache.get(1) # 1
    cache.put(3, 3)
    print cache.get(2) # -1
    cache.put(4, 4)
    print cache.get(1) # -1
    print cache.get(3) # 3
    print cache.get(4) # 4
    print '--------------------'
    cache = LRUCache(2)
    cache.put(1, 1)
    cache.put(1, 10)
    print cache.get(1) # 10
    cache.put(2, 2)
    print cache.get(1) # 10
    print cache.get(2) # 2
    cache.put(3, 3)
    print cache.get(2) # 2
    cache.put(4, 4)
    print cache.get(3) # -1
    print cache.get(2) # 2
    cache.put(5, 5)
    cache.put(5, 50)
    print cache.get(2) # 2
    print cache.get(5) # 50

