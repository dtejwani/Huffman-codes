//This file has been created by Dev TEJWANI
#ifndef MAP_H
#define MAP_H
const int sizeofTable = 128;
class HashEntry {
    private:
        int key;
        int value; 
    public:
        HashEntry(int k, int v) {
            key = k;
            value = v;
        };

       

        int keyg() {
            return key;
        };
        int Valueg() {
            return value;
        };   
};
class HashMap {
    private:
        HashEntry **hashtb;
    public:
        HashMap() {
            hashtb = new HashEntry*[sizeofTable];
            int j = 0;
            while( j < sizeofTable) {
                hashtb[j] = NULL;
                j++;
            }
        };

        ~HashMap() {int i = 0;
            while( i < sizeofTable) {
                if(hashtb[i] != NULL) {
                    delete hashtb[i];
                    
                }
                i++;
            }
            delete[] hashtb;
            
        };

        int get(int k) {
            int hash = (k % sizeofTable);
            while(hashtb[hash] != NULL && hashtb[hash]->keyg() != k) {
                hash = (hash +1) % sizeofTable; 
                if(hashtb[hash] == NULL) {
                    return -1;
                }
                else {
                    return hashtb[hash]->Valueg();
                }
            }
        };
        void put(int k, int v) {
            int hash = (k % sizeofTable);
            while(hashtb[hash] != NULL && hashtb[hash]->keyg() != k) {
                hash = (hash +1) % sizeofTable;
                if(hashtb[hash] != NULL) {
                    delete hashtb[hash];
                    hashtb[hash] = new HashEntry(k, v);
                }
            }
        };
};


#endif