#include <iostream>

struct Branch 
{
    unsigned int liczba = 1;
    std::string v;
    Branch* left = NULL;
    Branch* right = NULL;
};
class Tree
{
public:
    Branch* root;
    Tree(std::string& v) : root(NULL)
    {
        root = new Branch;
        root->v = v;
    };
    void add(std::string& val, Branch** node)
    {
        if (*node == NULL)
        {
            *node = new Branch;
            (*node)->v = val;
            return;
        }
            if (val == (*node)->v)
                (*node)->liczba++;
            else if (val > (*node)->v)
                add(val, &(*node)->right);
            else
                add(val, &(*node)->left);
    }
    void inOrder(Branch** node)
    {
        if (*node == NULL)
            return;
        inOrder(&(*node)->left);
        for (int i = 0;i < (*node)->liczba;i++)
        {
        std::cout << (*node)->v << "\n";
        }
        inOrder(&(*node)->right);
    }
    ~Tree() 
    {
        delete root;
    }
};
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    unsigned int n;
    std::string value;

    std::cin >> n;
    std::cin >> value;
    
    Tree bn(value);
    
    for (int i = 1;i < n;i++)
    {
        std::cin >> value;
        bn.add(value,&bn.root);
    }
    bn.inOrder(&bn.root);
    return 0;
}