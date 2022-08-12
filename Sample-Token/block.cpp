
#include <stdio.h>
#include <string>

#include "Block.h"
#include "TransactionData.h"
// Constructor with params
Block::Block(int id, TransactionData d, size_t prevHash)
{
    index = id;
    data = d;
    previousHash = prevHash;
    BlockHash = generateHash();
}

int Block::getIndex()
{
    return index;
}

size_t Block::generateHash() {
    std::hash <std::string> hash1;
    std::hash <size_t> hash2;
    std::hash <size_t> finalHash;
    std::string toHash = std::to_string(data.amount) + data.receiverKey + data.senderKey + std::to_string(data.timestamp);
    return finalHash(hash1(toHash) + hash2(previousHash)); 
};

// Public Functions
size_t Block::get_Hash()
{
    return BlockHash;
}

size_t Block::getPreviousHash()
{
    return previousHash;
}

bool Block::isHashValid()
{
    return generateHash() == get_Hash();
}