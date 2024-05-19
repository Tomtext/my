#include <iostream>
using namespace std;
template<typename keytype,typename valuetype>
class Hashhode {
public:
    keytype key;
    valuetype value;
    Hashhode* next;
    Hashhode(const keytype &key, const valuetype& value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

};
template<typename keytype, typename valuetype>
class Hasttable {
private:
    int size;
    Hashhode<keytype,valuetype>** table;
    int hash(const keytype & key)const {
        int hashkey = key % size;
        if (hashkey < 0) {
            hashkey += size;
        }
        return hashkey;
    }
public:
    Hasttable(int size = 256);
    ~Hasttable();
    void insert( const keytype& key, const valuetype& value);
    void remove(const keytype &key);
    bool find(const keytype& key, valuetype& value)const;
};
template<typename keytype, typename valuetype>
Hasttable<keytype, valuetype>::Hasttable(int size) {
    this->size = size;
    this->table = new Hashhode<keytype, valuetype>*[size];
    for (int i = 0; i < size; ++i) {
        this->table[i] = NULL;
    }
}
template<typename keytype, typename valuetype>
Hasttable<keytype, valuetype>::~Hasttable() {
    for (int i = 0; i < size; i++) {
        if (table[i]) {
            Hashhode<keytype, valuetype>* curr = table[i];
            while (curr) {
                Hashhode<keytype, valuetype>* next = curr->next;
                delete curr;
                curr = next;
            }
            table[i] = NULL;
        }
    }
    delete table;
    table = NULL;
}
template<typename keytype, typename valuetype>
void Hasttable<keytype, valuetype>::insert(const keytype& key, const valuetype& value) {
    int index = hash(key);
    Hashhode<keytype, valuetype>* now = new Hashhode<keytype, valuetype>(key, value);
    if (table[index] == NULL) {
        table[index] = now;
    }
    else {
        now->next = table[index];
        table[index] = now;
    }
}
template<typename keytype, typename valuetype>
void Hasttable<keytype, valuetype>::remove(const keytype& key) {
    int index = hash(key);
    if (table[index]) {
        if (table[index]->key == key) {
            Hashhode<keytype, valuetype>* next = table[index]->next;
            delete table[index];
            table[index] = next;
        }
        else {
            Hashhode<keytype, valuetype>* curr = table[index];
            while (curr->next && curr->next->key!=key) {
                curr = curr->next;
            }
            if (curr->next) {
                Hashhode<keytype, valuetype>* next = curr->next->next;
                delete curr->next;
                curr->next = next;
            }
        }
    }
}
template<typename keytype, typename valuetype>
bool Hasttable<keytype, valuetype>::find(const keytype& key, valuetype& value)const {
    int index = hash(key);
    if (table[index]) {
        if (table[index]->key = key) {
            value = table[index]->value;
            return true;
        }
        else {
            Hashhode<keytype, valuetype>* curr = table[index];
            while (curr->next && curr->next->key != key) {
                curr = curr->next;
            }
            if (curr->next) {
                value = curr->next->value;
                return true;
            }
        }
    }
    return false;
}
template<typename keytype>
class hashcounter {
private:
    int* counter;
    int counterindex;
    int countersize;
    Hasttable<keytype, int>* hash;
public:
    hashcounter(int size = 256);
    ~hashcounter();
    void reset();
    int add(const keytype& key);
    int sub(const keytype& key);
    int get(const keytype& key);

};
template<typename keytype>
hashcounter< keytype>::hashcounter(int size) {
    countersize = size;
    counterindex = 0;
    counter = new int[countersize];
    hash = NULL;
    reset();

}
template<typename keytype>
hashcounter< keytype>::~hashcounter() {
    delete[]counter;
    if (hash) {
        delete hash;
        hash = NULL;
    }
}
template<typename keytype>
void hashcounter< keytype>::reset() {
    if (hash) {
        delete hash;
        hash = NULL;

    }
    hash = new Hasttable<keytype, int>(countersize);
    counterindex = 0;
    for (int i = 0; i < countersize; i++) {
        counter[i] = 0;
    }
}
template<typename keytype>
int hashcounter< keytype>::add(const keytype& key) {
    int idx;
    if (!hash->find(key, idx)) {
        idx = counterindex++;
        hash->insert(key, idx);
    }
    return ++counter[idx];
}
template<typename keytype>
int hashcounter< keytype>::sub(const keytype& key) {
    int idx;
    if (hash->find(key, idx)) {
        return --counter[idx];
    }
    return 0;
}
template<typename keytype>
int hashcounter< keytype>::get(const keytype& key) {
    int idx;
    if (hash->find(key, idx)) {
        return counter[idx];
    }
    return 0;
}
int main()
{
    Hasttable<int, char>h(1000);
    h.insert(1, 'a');
    h.insert(2, 'b');
    h.insert(3, 'c');
    h.insert(4102012, 'd');
    char val;
    if (!h.find(43, val)) {
        cout << "43 not find" << endl;
    }
    if (h.find(4102012, val)) {
        cout << "410201 is find val is  " << val<<endl;
    }
    hashcounter<long long>hs;
    hs.add(14);
    hs.add(14);
    hs.add(14);
    hs.add(14);
    hs.add(14);
    hs.sub(14);
    cout << hs.get(14) << endl;
}

