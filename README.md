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
A program can generate Huffman codes from a string using the following steps:
• Generate a list of the frequency in which characters appear in the string using a map
• Inserting the characters and their frequencies into a priority queue (sorted first by the lowest
frequency and then lexicographically)
• Until there is one element left in the priority queue
• Remove two characters/frequencies pairs from the priority queue
• Turn them into leaf nodes on a binary tree
• Create an intermediate node to be their parent using the sum of the frequencies for those
children
• Put that intermediate node back in the priority queue
• The last pair in the priority queue is the root node of the tree
• Using this new tree, encode the characters in the string using a map with their prefix code by
traversing the tree to find where the character’s leaf is. When traversal goes left, add a 0 to
the code, when it goes right, add a 1 to the code
• With this encoding, replace the characters in the string with their new variable-length prefix
codes 
