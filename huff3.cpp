	int BinaryToDecimal(string n)
	{
		string num = n;
		int dec_value = 0;
		int base = 1;
		int len = num.size();
		for (int i = len - 1; i >= 0; i--) {
			if (num[i] == '1')
				dec_value += base;
			base = base * 2;
		}
		return dec_value;
	}

	void encodingHuffman_rec(vector<string>& encoding, Node* node, string s = "")
	{
		if (node->left == nullptr && node->right == nullptr)
		{   
			int index = node->c - '0' + 48;
			encoding[index] = s;
			return;
		} 
		if (node->left != nullptr)
		{   
			string left = s;
			left += "0";
			encodingHuffman_rec(encoding, node->left, left);
		}
		if (node->right != nullptr) 
		{   
			string right = s;
			right += "1";
			encodingHuffman_rec(encoding, node->right, right);
		}
	}
	int encodingHuffman(Node * root,string nameCaesar)
	{
		if (root->left == nullptr && root->right == nullptr) return 0;
		vector<string> encoding(256, ""); 
		encodingHuffman_rec(encoding, root);
		string binary;
		while (binary.size() < 10 && !nameCaesar.empty()) 
		{   
			char str = nameCaesar.back();
			nameCaesar.pop_back();
			int index = str - '0' + 48;
			binary = encoding[index] + binary;
		}
		if (binary.size() > 10)
		{
			int i = binary.size() - 10;
			binary = binary.substr(i, 10);
		}
		reverse(binary.begin(), binary.end());
		int result = 0;
		result = BinaryToDecimal(binary);
		return result;
	}
