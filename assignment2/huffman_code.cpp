#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<string.h>
using namespace std;

map<char, string> codes;
map<char, int> freq; 
const int MAX_CHAR = 1000;
 
struct MinHeapNode {

    char data;
    unsigned freq;

    MinHeapNode* left, * right;

    MinHeapNode(char data, unsigned freq) {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};



struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; /*using priority queue*/

void storeCodes(struct MinHeapNode* root, string str)
{

    if (root == NULL)

        return;

    if (root->data != '$')

        codes[root->data] = str;

    storeCodes(root->left, str + "0");
    storeCodes(root->right, str + "1");
}


void encode(int size) {
    struct MinHeapNode* left, * right, * top;

   for (map<char, int>::iterator iter=freq.begin(); iter!=freq.end(); iter++) 
         minHeap.push(new MinHeapNode(iter->first, iter->second)); 

    while (minHeap.size() != 1) {

        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    storeCodes(minHeap.top(), "");
}

string decode(struct MinHeapNode* root, string str)
{

    string ans = "";

    struct MinHeapNode* curr = root;

    for (int i = 0; i < str.size(); i++)
    {

        if (str[i] == '0')
           curr = curr->left;

        else
           curr = curr->right;

        if (curr->left == NULL && curr->right == NULL)
        {

            ans += curr->data;
            curr = root;
        }

    }

    return ans + '\0';
}

int main() {

    string encodedString, decodedString;
	string str; 
    int num;
    cout << "Enter the string" << endl;
    cin >> str;

   for (int i=0; i<str.size(); i++) 
   {
        freq[str[i]]++; 
   }

    encode(str.length());

    cout << "Character With there Frequencies:\n";

    for (auto v = codes.begin(); v != codes.end(); v++)
        cout << v->first << ' ' << v->second << endl;

    for (auto i : str)
        encodedString += codes[i];

    cout << "\nEncoded Huffman data:\n" << encodedString << endl;


    decodedString = decode(minHeap.top(), encodedString);
    cout << "\nDecoded Huffman Data:\n" << decodedString << endl;

    return 0;
}
