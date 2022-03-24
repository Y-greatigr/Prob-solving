#include<stdio.h>

struct Trie {
    bool isEnd;
    int endCnt;
    struct Trie* next[26];

    Trie() : isEnd(false), endCnt(0) {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }

    void insert(const char* str, bool print) {
        if (*str == 0) {
            isEnd = true;
            endCnt++;
            if (endCnt >= 2) printf("%d\n", endCnt);
            else printf("\n");
            return;
        }
        if (print) printf("%c", (*str));
        int key = (*str) - 'a';
        if (next[key] == NULL) {
            next[key] = new Trie();
            next[key]->insert(str + 1, false);
        }
        else {
            next[key]->insert(str + 1, true);
        }
    }
};

int main()
{
    int n;
    Trie* root = new Trie();
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char cst[11];
        scanf(" %s", cst);
        root->insert(cst, true);
    }
}