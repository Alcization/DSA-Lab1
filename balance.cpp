int height(Node* node) 
{
    if (node == nullptr) return 0;
    return max(height(node->left), height(node->right)) + 1;
}

//  Get balance value
int getBalance(Node* node)
{
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

Node* rotateRight(Node* root) 
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root->height = height(root);
    temp->height = height(temp);
    return temp;
}
 
Node* rotateLeft(Node* root) 
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = height(root);
    temp->height = height(temp);
    return temp;
}


//* cân bằng node yêu cầu xét mất cân bằng loại nào rồi quay nhưng count >= 3 thì dừng
//* trường hợp LL -> tính là count được cộng thêm 1
//* trường hợp RR -> tính là count được cộng thêm 1
//* trường hợp RL -> tính là count được cộng thêm 2
//* trường hợp LR -> tính là count được cộng thêm 2
//* nếu trường hợp LL cũng là LR -> xét như Trường hợp LL
//* nếu trường hợp RL cũng là RR -> xét như Trường hợp RR
//^ chú ý vì RL LR tính 2 lần nên khi count = 2 mà phải xử lí 1 này thì -> làm 1 lần rồi dừng
Node* balanceNode(Node* node, int& count) 
{
    //TODO      ???
    if (count == 3) return node;
    int balance = getBalance(node);
    if (balance > 1)
    {
        if (getBalance(node->left) >= 0) 
        {   
            node = rotateRight(node);
            count++;
        }
        else
        {
            node->left = rotateLeft(node->left);
            count++;
            if (count < 3)
            {
                node = rotateRight(node);
                count++;
            }
        }
    }
    else if (balance < -1)
    {
        if (getBalance(node->right) <= 0) 
        {
            node = rotateLeft(node);
            count++;
        }
        else
        {
            node->right = rotateRight(node->right);
            count++;
            if (count < 3)
            {
                node = rotateLeft(node);
                count++;
            }
        }
    }
    else return node;
    return node;
}

//* tiến hành đệ quy theo preOrder -> nếu count >= 3 thì dừng lại không cân bằng nữa
Node* balanceTree(Node* node, int& count)
{
    //TODO      ???
    if (node->height == 1) return node; // Node lá
    node = balanceNode(node, count);
    node->left = balanceTree(node->left, count);
    node->right = balanceTree(node->right, count);
    return node;
}
