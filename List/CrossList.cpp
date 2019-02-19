#include <iostream>
#include <vector>
using namespace std;
/*
 * This file includes the definiton of orthogonal list node and orthogonal list.
 * Besides, these is functions which employ orthogonal list to store and print 
 * sparse matrix data.
 */


//Node Denifition
struct CrossNode{
	int i, j, value;
	CrossNode *right, *down;
	CrossNode(int idx, int jdx, int val) : i(idx), j(jdx), value(val), right(NULL), down(NULL){}
};

typedef struct CrossNode CLNode, *CrossLine;


//Orthogonal List Definition
class CrossList{
public:
	CrossList(){}
	CrossList(vector< vector<int> > &arr);
	void Insert(CLNode* &node);
	void print();
	int getCount();
private:
	void InsertIntoRow(CLNode* &node);
	void InsertIntoColumn(CLNode* &node);
	void CreateSparseMatrix(vector< vector<int> > &arr);

	int row, col, count;
	CrossLine *rowHead, *colHead;
};

//Constructor
CrossList::CrossList(vector< vector<int> > &arr){
	if(arr.empty()) return;
	row = arr.size();
	col = arr[0].size();
	rowHead = new CrossLine[row];
	for(int m = 0; m < row; ++m)
		rowHead[m] = NULL;
	colHead = new CrossLine[col];
	for(int n = 0; n < col; ++n)
		colHead[n] = NULL;
	CreateSparseMatrix(arr);
}

//Insertion
void CrossList::Insert(CLNode* &node){
	InsertIntoRow(node);
	InsertIntoColumn(node);
}

//Update rowHead when insertion
void CrossList::InsertIntoRow(CLNode* &node){
	int m = node->i;
	cout << "m= " << m << endl;
	//if(rowHead[m] != NULL) cout << rowHead[m] << endl;
	if(!rowHead[m]){
		cout << "   1" << endl;
		rowHead[m] = node;
	}
	
	else{
		if(rowHead[m]->j > node->j){
			cout << "   2" << endl;
			node->right = rowHead[m];
			rowHead[m] = node;
		}
		else{
			cout << "   3" << endl;
			CLNode* cur = rowHead[m]; 
			while(cur->right && cur->right->j < node->j){
				cur = cur->right;
			}
			if(!cur->right){
				cur->right = node;
			}
			else{
				node->right = cur->right;
				cur->right = node;
			}
		}
	}
}

//Update colHead when insertion
void CrossList::InsertIntoColumn(CLNode* &node){
	int n = node->j;
	if(!colHead[n]){
		colHead[n] = node;
	}
	else{
		if(colHead[n]->i < node->i){
			node->down = colHead[n];
			colHead[n] = node;
		}
		else{
			CrossLine cur = colHead[n]; //CLNode *
			while(cur->down && cur->down->i < node->i){
				cur = cur->down;
			}
			if(!cur->down){
				cur->down = node;
			}
			else{
				node->down = cur->down;
				cur->down = node;
			}
		}
	}
}

//Store sparse matrix
void CrossList::CreateSparseMatrix(vector< vector<int> > &arr){
	for(int m = 0; m < row; ++m){
		for(int n = 0; n < col; ++n){
			if(arr[m][n] != 0){
				CLNode *newNode = new CLNode(m, n, arr[m][n]);
				Insert(newNode);
				++count;
			}
		}
	}
}

//Print sparse matrix
void CrossList::print(){
	for(int m = 0; m < row; ++m){
		CrossLine cur = rowHead[m];
		int n = 0;
		while(n < col){
			if(cur && n == cur->j){
				cout << cur->value << " ";
				cur = cur->right;
			}
			else cout << "0 ";
			++n;
		}
		cout << endl;
	}
}


int CrossList::getCount(){ 
	return count; 
}

/*
test case:
0 18 0 0 0 0
0 0 67 0 0 0
0 0 0 0 0 41
0 0 47 62 0 0
0 0 0 0 0 35

output:
0 18 0 0 0 0
0 0 67 0 0 0
0 0 0 0 0 41
0 0 47 62 0 0
0 0 0 0 0 35
*/

int main(){
	vector< vector<int> > arr = {
		{0,  18, 0,  0,  0,  0},
		{0,  0,  67, 0,  0,  0},
		{0,  0,  0,  0,  0,  41},
		{0,  0,  47, 62, 0,  0},
		{0,  0,  0,  0,  0,  35}
	};
	CrossList testList(arr);
	testList.print();
}




