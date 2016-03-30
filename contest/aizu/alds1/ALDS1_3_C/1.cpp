#include <cstdio>
#include <cstring>

struct Node {
    Node* next;
    Node* prev;
    int key;
};
Node* head = new Node();
Node* tail = new Node();
void printKeys() {
    Node* node = head->next;
    bool isFirst = true;
    while (node != tail) {
        if (!isFirst) {
            printf(" ");
        }
        printf("%d", node->key);
        isFirst = false;
        node = node->next;
    }
    printf("\n");
}
int n;
char insertStr[] = "insert";
char deleteStr[] = "delete";
char deleteFirstStr[] = "deleteFirst";
char deleteLastStr[] = "deleteLast";
int main() {
    head->next = tail;
    tail->prev = head;
    scanf("%d\n", &n);
    char s[20];
    int key;
    for (int i = 0; i <= n - 1; ++i) {
        scanf("%s", s);
        if (strcmp(s, deleteFirstStr) == 0) {
            Node* node = head->next;
            head->next = head->next->next;
            head->next->prev = head;
            delete node;
        } else if (strcmp(s, deleteLastStr) == 0) {
            Node* node = tail->prev;
            tail->prev = tail->prev->prev;
            tail->prev->next = tail;
            delete node;
        } else {
            scanf("%d", &key);
            if (strcmp(s, insertStr) == 0) {
                Node* node = new Node();
                node->prev = head;
                node->next = head->next;
                node->key = key;
                head->next->prev = node;
                head->next = node;
            } else {
                Node* node = head->next;
                while(node != tail) {
                    if (node->key == key) {
                        node->next->prev = node->prev;
                        node->prev->next = node->next;
                        delete node;
                        break;
                    }
                    node = node->next;
                }
            }
        }
        // printKeys();
    }
    printKeys();
}
