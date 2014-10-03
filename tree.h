#include <queue>
#include <stack>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;


template<class T>
class Node {
public:
	Node() { left = right = NULL; }
	Node(const T& el, Node *l = 0, Node *r = 0) {
		key = el; left = l; right = r;
	}

	T key;

	Node *left, *right;
};

template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void insert(const T& el);
	void deleteNode(Node<T> *& node);
	void visit(Node<T> *p);
	void data_show(Node<T> *p);
	int Height();
	int displayHeight(Node<T> *p);
	void balance(T data[], int first, int last);
	T *data;
	//T *data2;
	int i = 0;
	//int h = 0;

protected:
	Node<T> *root;

	void clear(Node<T> *p);
	void inorder(Node<T> *p);

};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
}

template<class T>
void Tree<T>::inorder(Node<T> *p) {
	if (p != 0) {
		inorder(p->left);
		//visit(p);
		data[i++] = p->key;
		inorder(p->right);
	}
}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	//data2[h++] = el;
	while (p != 0) {
		prev = p;
		if (p->key < el){
			p = p->right;
		}
		else{
			p = p->left;

		}
		
	}

	if (root == 0){
		root = new Node<T>(el);
		
	}
	else if (prev->key < el){
		prev->right = new Node<T>(el);
		
	}
	else{
		prev->left = new Node<T>(el);
		
	}

}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *tmp = node;
	if (node->right == 0)
		node = node->left;
	else if (node->left == 0)
		node = node->right;
	else {
		tmp = node->left;
		prev = node;
		while (tmp->right != 0) {
			prev = tmp;
			tmp = tmp->right;
		}
		node->key = tmp->key;
		if (prev == node)
			prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}

template<class T>
void Tree<T>::visit(Node<T> *p){
	cout << p->key << " ";
	//cout << "Height is :" << h << endl;
}

/*template<class T>
void Tree<T>::Height(){
	cout << "Height is : " << h << endl;
}*/
template<class T>
void Tree<T>::balance(T data[], int first, int last) {
	if (first <= last) {
		int middle = (first + last) / 2;
		insert(data[middle]);
		cout << data[middle] << " ";
		balance(data, first, middle - 1);
		balance(data, middle + 1, last);
	}
}

template <class T>
int Tree<T>::Height()
{

	return displayHeight(root) - 1;

}
template<class T>
int Tree<T>::displayHeight(Node<T> *p){

	if (p == NULL)
	{
		return 0;
	}
	else{
		int left = displayHeight(p->left);
		int right = displayHeight(p->right);
		if (left > right)
		{
			return left + 1;
		}
		else return right + 1;
	}
}

template<class T>
void Tree<T>::data_show(Node<T> *p){
	cout << p->key << " ";
	//cout << "Height is :" << h << endl;
}

#endif // Binary_Search_Tree
