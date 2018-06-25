#include <iostream>

using namespace std;

template <typename Type_>
class tree_t
{
private:
    struct node_t {
        node_t * left_;
        node_t * right_;
        T key_;
    };
private:
    node_t * root_;
public:
    tree_t(std::initializer_list<T> keys);
    auto operator==(tree_t const & other) const;
    void insert(T key);
    bool remove(T key);
    bool find(T key) const;
    void print(std::ostream & stream) const;
};



class tree_t
{
private:
	struct node_t 
  	{
		node_t * left_;
		node_t * right_;
		int key_;

		node_t() 
    		{
			left_ = nullptr;
			right_ = nullptr;
			key_ = 0;
		}

		void print_(ostream & stream, int size_) const 
    		{
			if (left_ != nullptr) 
      			{
        			left_->print_(stream, size_ + 4);
      			}
			for (int i = 0; i < size_ + 4; i++) 
      			{
        			stream << '-';
      			}
			stream << key_ << endl;

			if (right_ != nullptr)
      			{
        			right_->print_(stream, size_ + 4);
      			} 
		}

		~node_t() 
    		{
			if (left_ != nullptr) 
      			{
        			delete left_;
      			}
			if (right_ != nullptr)
      			{
        			delete right_;
      			}
		}

	};

	node_t * root_;

public:
	tree_t() 
  	{
		root_ = nullptr;
	}

	void insert(int key_) 
  	{

		if (root_ == nullptr) 
    		{
			root_ = new node_t;
			root_->key_ = key_;
		}
		else 
    		{
			node_t * temp = root_;

			while (root_->left_ != nullptr || root_->right_ != nullptr) 
      			{
				if (root_->key_ < key_ ) 
        			{
					if (root_->left_ != nullptr)
         	 			{
            					root_ = root_->left_;
          				}
					else
          				{
            					break;
          				} 
				}
				else if (root_->key_ > key_ ) 
        			{
					if (root_->right_ != nullptr) 
          				{
            					root_ = root_->right_;
          				}
          				else 
          				{
            					break;
          				}
				}
			}

			if (root_->key_ < key_) 
      			{
				root_->left_ = new node_t;
				root_->left_->key_ = key_;
			}
			else if (root_->key_ > key_) 
      			{
				root_->right_ = new node_t;
				root_->right_->key_ = key_;
			}
			root_ = temp;
		}
	}

	bool find(int key_) const 
  	{

		if (root_ == nullptr) 
    		{
      			return false;
    		}
    		else 
    		{
			node_t * temp = root_;

			while (temp != nullptr) 
      			{
				if (temp->key_ == key_)
        			{
          				return true;
        			} 
				else if (temp->key_ > key_) 
				{
					temp = temp->right_;
				}
				else if (temp->key_ < key_)
				{
					temp = temp->left_;
				} 
			}
			return false;
		}
	}

	void print(ostream & stream) const 
  	{
		if (root_ == nullptr) 
    		{
			stream << "пустое дерево " << endl;
		}
		else 
    		{
			root_->print_(stream, 0);
		}
	}

	~tree_t() 
  	{
		if (root_ != nullptr) 
    		{
      			delete root_;
    		}
	}
};


int main()
{
	char c = '=';
	tree_t tree_;
	int key_;

	while (c != 'q') 
  	{
		switch (c)
		{
		case '+':
			cin >> key_;
			tree_.insert(key_);
			tree_.print(cout);
			break;
		
		case '?':
			cin >> key_;
			if (tree_.find(key_))
      			{
        			cout << "true" << endl;
      			} 
			else
			{
				cout << "false" << endl;
			} 
			break;

		case '=':
			tree_.print(cout);
			break;
		
    		default:
      			cout << "NATHING HERE ZULUL" << endl;
    		}
  		
		cin >> c;

	}
	return 0;
}
