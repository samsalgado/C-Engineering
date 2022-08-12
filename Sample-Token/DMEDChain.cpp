
#include <iostream>
#include <ctime>
#include <vector>

#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;

int main()
{
    Blockchain DMEDToken;
    TransactionData data1;
    time_t data1Time;
    data1.amount = 6; //For Ayurveda clinic
    data1.receiverKey = "Ayurveda Clinic Id:5";
    data1.senderKey = "ID: 423";
    data1.timestamp = time(&data1Time);
    DMEDToken.addBlock(data1);
    cout << "Is chain valid ?" << endl
        << DMEDToken.isChainValid() << endl;

    TransactionData data2;
    time_t data2Time;
    data2.amount = 0.9;
    data2.receiverKey = "Accupuncturist ID:3";
    data2.senderKey = "ID: 9";
    data2.timestamp = time(&data2Time);
    DMEDToken.addBlock(data2);
    DMEDToken.printChain();
}