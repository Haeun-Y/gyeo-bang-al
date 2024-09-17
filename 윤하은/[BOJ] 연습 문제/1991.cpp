//배열로도 구현해보기, idx로 자식노드 찾기
#include <bits/stdc++.h>
using namespace std;
int n;
typedef struct node
{
    struct node* left;
    struct node* right;
    char ch;
    
}node;
vector<node*> nodeAddr;
void preorderTraversal(node* cur)
{
    cout << cur->ch;
    if(cur->left != NULL)
        preorderTraversal(cur->left);
    
    if(cur->right != NULL)
        preorderTraversal(cur->right);
    
}
void postorderTraversal(node* cur)
{
    if(cur->left != NULL)
        postorderTraversal(cur->left);
    if(cur->right != NULL)
        postorderTraversal(cur->right);
    cout << cur->ch;
}
void inorderTraversal(node* cur)
{
    if(cur->left != NULL)
        inorderTraversal(cur->left);
    cout << cur->ch;
    if(cur->right != NULL)
        inorderTraversal(cur->right);
    
}
int main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    
    cin >> n;
    node* tmp = (node*)malloc(sizeof(node));
    nodeAddr = vector<node*>(n, tmp);
    node * p;
    for(int i = 0; i<n; i++)
    {
        vector<char> v(3);
        cin >> v[0] >> v[1] >> v[2];
        for(int i = 0; i<3; i++)
        {
            if(v[i] == '.') continue;
            int idx = v[i]-'A';
            if(nodeAddr[idx] != tmp)
            {
                p = (node*)malloc(sizeof(node));
                nodeAddr[idx] = p;
            }
            nodeAddr[idx]->ch = v[i];
            cout << nodeAddr[idx]->ch << " ";
        }
        cout << "\n";
        if(v[1] == '.')
            nodeAddr[v[0]-'A']->left = NULL;
        else
            nodeAddr[v[0]-'A']->left = nodeAddr[v[1]-'A'];
        if(v[2] == '.')
            nodeAddr[v[0]-'A']->right = NULL;
        else
            nodeAddr[v[0]-'A']->right = nodeAddr[v[2]-'A'];
    
    }
    for(int i = 0; i<n; i++)
        cout << nodeAddr[i]->ch << " ";
    cout << "\n";
    preorderTraversal(nodeAddr[0]);
    cout << "\n";
    inorderTraversal(nodeAddr[0]);
    cout << "\n";
    postorderTraversal(nodeAddr[0]);
    
    
    
}
