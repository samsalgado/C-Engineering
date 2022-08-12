
#ifndef BLOCKCHAIN_h
#define BLOCKCHAIN_h

#include <vector>

// Blockchain Class
class Blockchain
{
private:
    Block createGenesisBlock();
    std::vector<Block> chain;

public:
    Blockchain();
    
    // Public Functions
    std::vector<Block> getChain();
    Block *getLatestBlock();
    bool isChainValid();
    void addBlock(TransactionData data);
    void printChain();
};

#endif /* BLOCKCHAIN_h */