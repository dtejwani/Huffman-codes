//This file has been created by Dev Tejwani
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <map>
#include <vector>
#include <sstream>
#include "HuffmanBase.hpp"
#include "Map.hpp"
#include <unordered_map>


class HuffmanTree : public HuffmanTreeBase
{
   private:
    std::string Stringin;
    std::string StringcodeHuff;
    std::string Stringserialhuff;
    std::string incompress;
    std::map<char, std::string> cdhfmaps;
    std::string stringdecomp;
    
  public:
   
    void preOrder(HuffmanNode *nodehuff, std::string stringcodes, std::map<char, std::string> &maphuff) const;

    void postOrder(HuffmanNode *nodehuff);

    void clearTree(HuffmanNode* nodehuff);
    virtual std::string compress(const std::string inputStr) override;
    virtual std::string serializeTree() const override;
    virtual std::string decompress(const std::string inputCode, const std::string serializedTree) override;

    
    

 
};

#endif
