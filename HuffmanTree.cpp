//This file has been created by Dev TEJWANI

#include <map> 
#include <stack> 
#include "HuffmanBase.hpp"
#include "HuffmanTree.hpp"
#include "HeapQueue.hpp"


/*
**************************************************************************************************
Compress the input string using the method explained. Note: Typically we would be
returning a number of bits to represent the code, but for this project we are returning a string
**************************************************************************************************
*/

std::string HuffmanTree::compress(const std::string inputStr) {//rETURNS COMPRESSED STRING
    std::string stringtemps = inputStr;
    HuffmanTree::incompress = stringtemps;
   
    std::map<char, int> mapfrequencyhuff; // create  list of the frequency 
    for(char ch : inputStr) {
        mapfrequencyhuff[ch]++;
    }

    
    HeapQueue<HuffmanNode*, HuffmanNode::Compare> ndheapq;
    std::map<char, int>::iterator terator;
    terator = mapfrequencyhuff.begin();
    while( terator != mapfrequencyhuff.end()) {
        
        HuffmanNode* nodehuff = new HuffmanNode(terator->first, terator->second, nullptr, nullptr, nullptr);
        ndheapq.insert(nodehuff);
        ++terator;
    }

   
    while(ndheapq.size() != 1) {
        
        HuffmanNode* left = ndheapq.min();
        ndheapq.removeMin();
        HuffmanNode* right = ndheapq.min();
        ndheapq.removeMin();

        
        int fresum = left->getFrequency() + right->getFrequency();
       
        HuffmanNode* parent = new HuffmanNode('\0', fresum, nullptr, left, right);

        
        ndheapq.insert(parent);
    }
        HuffmanNode* root = ndheapq.min();
      
        std::map<char, std::string> maphuff;
       
        preOrder(root, "", maphuff);
        postOrder(root);

        
        std::string returnStr = "";
        for(auto c : inputStr) {
                returnStr += maphuff[c];
        }

        
        HuffmanTree::StringcodeHuff = returnStr;
        HuffmanTree::Stringin = inputStr;
        HuffmanTree::cdhfmaps = maphuff;

       
        return returnStr;
};
void HuffmanTree:: preOrder(HuffmanNode *nodehuff, std::string stringcodes, std::map<char, std::string> &maphuff) const
    {
        

        if (nodehuff->isLeaf())
        {
            
            maphuff[nodehuff->getCharacter()] = stringcodes;
           
        }
        else
        {
            
            preOrder(nodehuff->left, stringcodes + "0", maphuff);
            preOrder(nodehuff->right, stringcodes + "1", maphuff);
        }
    };
    void HuffmanTree:: postOrder(HuffmanNode *nodehuff)
    {
      
        if(nodehuff != nullptr) {
            postOrder(nodehuff->left);
            postOrder(nodehuff->right);
            
            if(nodehuff->isLeaf()) {
                Stringserialhuff += "L";
                Stringserialhuff += nodehuff->getCharacter();    
            }

            if(nodehuff->isBranch()) {
                Stringserialhuff += "B";
            }
        }
        
    };
    void HuffmanTree:: clearTree(HuffmanNode* nodehuff) {
        if(nodehuff != nullptr) {
            clearTree(nodehuff->left);
            clearTree(nodehuff->right);
            delete nodehuff;
        }    
    };

std::string HuffmanTree::serializeTree() const {
  
    return Stringserialhuff;
};


std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree) {//rETURNS DECOMPRESSED STRING
    stringdecomp = "";
    std::stack<HuffmanNode*> Treehuff;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode* nodehuff = new HuffmanNode(serializedTree.at(1), 1, nullptr, nullptr, nullptr);
    Treehuff.push(nodehuff);
    for(unsigned int terator = 1; terator < serializedTree.size(); terator++) {
        char charrs = serializedTree.at(terator);
    
        if(charrs == 'B') {
            
            if((serializedTree.at(terator -1) == 'L') && (serializedTree.at(terator -2) != 'L')) {
                continue;
            }    
            else {
                right = Treehuff.top();
                Treehuff.pop();
                left = Treehuff.top();
                Treehuff.pop();
                HuffmanNode* stringtemps = new HuffmanNode(charrs, 1, nullptr, left, right);
                Treehuff.push(stringtemps);
            }
        }
        
        if((charrs == 'L') && (serializedTree.at(terator -1) != 'L')) {
            HuffmanNode* nodehuff = new HuffmanNode(serializedTree.at(terator +1), 1, nullptr, nullptr, nullptr);
            Treehuff.push(nodehuff);
        }
    }

    HuffmanNode* root;
    HuffmanNode* Rtnew;

    postOrder(Treehuff.top());
    root = Treehuff.top();
    Rtnew = Treehuff.top();

    for(auto charrs : inputCode) {

        if(charrs == '1') {
            root = root->right;
            if(root->isLeaf()) {
                stringdecomp += root->getCharacter();
                root = Rtnew;
            }
        }        

        if(charrs == '0') {
            root = root->left;
            if(root->isLeaf()) {
                stringdecomp += root->getCharacter();
                root = Rtnew;
            }
        }
    }

    HuffmanNode* topTemperory = Treehuff.top();
    clearTree(topTemperory);
    Treehuff.pop();

    
    return stringdecomp;
};