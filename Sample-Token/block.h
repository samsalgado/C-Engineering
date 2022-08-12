

#ifndef Block_h
#define Block_h

#include "TransactionData.h"

// Block Class
class Block {
    private:
        int index;
        size_t BlockHash;
        size_t previousHash;
        size_t generateHash();
    public:
        Block(int id, TransactionData d, size_t prevHash);
        int getIndex();
        size_t get_Hash();
        size_t getPreviousHash();
        TransactionData data;
        bool isHashValid();
};
#endif /* Block_h */