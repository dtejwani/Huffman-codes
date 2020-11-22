# Huffman-codes
Static Huffman coding assigns variable length codes to symbols based on their frequency of occurrences in the given message.
Low frequency symbols are encoded using many bits, and high frequency symbols are encoded using fewer bits.
The message to be transmitted is first analyzed to find the relative frequencies of its constituent characters.
The coding process generates a binary tree, the Huffman code tree, with branches labeled with bits (0 and 1).
The Huffman tree (or the character codeword pairs) must be sent with the compressed information to enable the receiver decode the message. 
It generates  Huffman codes to compress a given string. A Huffman code uses a set of prefix code to compress the string with no loss of data (lossless).
David Huffman developed this algorithm in the paper “A Method for the Construction of
Minimum-Redundancy Codes” (http://compression.ru/download/articles/huff/
huffman_1952_minimum-redundancy-codes.pdf) 
