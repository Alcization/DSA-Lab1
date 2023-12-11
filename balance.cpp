	int height(Node* node) 
	{
		if (node == nullptr) return 0;
		return max(height(node->left), height(node->right)) + 1;
	}

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

	Node* balanceNode(Node* node, int& count) 
	{
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

	Node* balanceTree(Node* node, int& count)
	{
		if (count == 3) return node;
		if (node == nullptr) return node; // Node lá
		node = balanceNode(node, count);
		node->left = balanceTree(node->left, count);
		node->right = balanceTree(node->right, count);
		return node;
	}

	Node* buildHuff(vector<pair<char, int>> freq)
	{
		vector<Node*> build;
		for (int i = 0; i < (int) freq.size(); i++)
		{
			Node* node = new Node(freq[i].second, freq[i].first);
			node->height = 1;
			build.push_back(node);
		}
		while(build.size() > 1)
		{
			Node* left = build.back();
			build.pop_back();
			Node* right = build.back();
			build.pop_back();
			Node* newNode = new Node(0, '\0', left, right);
			newNode->weight = left->weight + right->weight;
			newNode->height = height(newNode);
			int count = 0;
			newNode = balanceTree(newNode, count);
			vector<Node*>::iterator it = build.begin();
			bool found = false;
			for (int i = 0; i < (int) build.size(); i++, it++) 
			{
				if (newNode->weight >= build[i]->weight)
				{
					build.insert(it, newNode);
					found = true;
					break;
				}
			}
			if (!found) build.push_back(newNode);

		}		
		return build[0];
	}
