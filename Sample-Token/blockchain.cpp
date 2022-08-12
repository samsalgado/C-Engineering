#include <stdio.h>
#include <ctime>
#include <string>

<<<<<<< HEAD
#include "Block.h"
#include "Blockchain.h"

#include <vector>

=======
class Block {
    private:
        int index;
        size_t BlockHash;
        size_t previousHash;
        size_t generateHash();
    public:
        Block(int id, TransactionData d, size_t prevHash);
        size_t get_Hash();
        size_t getPreviousHash();
        TransactionData data;
        bool isHashValid();
};
Block::Block(int id, TransactionData d, size_t prevHash) {
index = id;
data = d;
previousHash = prevHash;
BlockHash = generateHash();
}
size_t Block::generateHash() {
    hash <string> hash1;
    hash <size_t> hash2;
    hash <size_t> finalHash;
    string toHash = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);
    return finalHash(hash1(toHash) + hash2(previousHash)); 
};
size_t Block::get_Hash() {
    return BlockHash;
}
size_t Block::getPreviousHash() {
    return previousHash;
}
bool Block::isHashValid(){
    return generateHash() == BlockHash;
}
class Blockchain {
    private:
        Block createGenesisBlock();
    public:
    Blockchain();
    //Public chain
        vector<Block> chain;
    void addBlock(TransactionData data);
    bool isChainValid();

    Block *getLatestBlock();
    void printChain();
};
//Constructor
>>>>>>> 6dd22d5f55e82d57eda400a9e1ec18c57013df7f
Blockchain::Blockchain()
{
    Block genesis = createGenesisBlock();
    chain.push_back(genesis);
}

std::vector<Block> Blockchain::getChain() {
    return chain;
}

Block Blockchain::createGenesisBlock()
{
     time_t current;
    TransactionData d;
    d.amount =0;
    d.receiverKey = "None";
    d.senderKey = "None";
    d.timestamp = time (&current);
    std::hash<int> hash1;
    Block genesis(0, d, hash1(0));
    return genesis;
}

Block *Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size() - 1;
    std::size_t previousHash = (int)chain.size() > 0 ? getLatestBlock()->get_Hash() : 0;
    Block newBlock(index, d, getLatestBlock() -> get_Hash());
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid()
{
    std::vector<Block>::iterator it;
    int chainLen = (int) chain.size();
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isHashValid())
        {
            return false;
        }
         if(chainLen > 1) {
                Block previousBlock = *(it -1);
                if(currentBlock.getPreviousHash() != previousBlock.get_Hash()) {
                    return false;
                }
            }
        if(chainLen > 1) {
                Block previousBlock = *(it -1);
                if(currentBlock.getPreviousHash() != previousBlock.get_Hash()) 
                {
                    return false;
                }
            }
        if (it != chain.begin())
        {
            Block previousBlock = *(it - 1);
            if (currentBlock.getPreviousHash() != previousBlock.get_Hash())
            {
                return false;
            }
        }
    }
    
    return true;
}
<<<<<<< HEAD

void Blockchain::printChain() {
    std::vector<Block>::iterator it;
    
    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        printf("\n\nBlock ===================================");
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount);
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.receiverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.timestamp);
        printf("\nHash: %zu", currentBlock.get_Hash());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid?: %d", currentBlock.isHashValid());
    }
}
=======
 
>>>>>>> 6dd22d5f55e82d57eda400a9e1ec18c57013df7f
