#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 100 + 7;

int a[N], n;

struct Node
{
	int x;
	Node* l, *r;
};

Node* buildtree(int st, int ed)
{
	if(st > ed) return nullptr;
	
	Node* root = new Node;
	root->x = a[st];
	
	int nst = st + 1;
	while(nst <= ed && a[nst] < a[st]) nst++;
	
	root->l = buildtree(st + 1, nst - 1);
	root->r = buildtree(nst, ed);
	
	return root;
}

Node* findMax(Node* root)
{
	while(root->r != nullptr) root = root->r;
	return root;
}

Node* findMin(Node* root)
{
	while(root->l != nullptr) root = root->l;
	return root;
}

Node* deleteNode(Node* root, int val)
{
	if(root == nullptr) return nullptr;
	
	if(val < root->x) root->l = deleteNode(root->l, val);
	else if(val > root->x) root->r = deleteNode(root->r, val);
	else
	{
		if(root->l == nullptr && root->r == nullptr)
		{
			delete root;
			return nullptr;
		}
		else if(root->l != nullptr)
		{
			Node* mx = findMax(root->l);
			root->x = mx->x;
			root->l = deleteNode(root->l, mx->x);
		}
		else
		{
			Node* mi = findMin(root->r);
			root->x = mi->x;
			root->r = deleteNode(root->r, mi->x);
		}
	}
	
	return root;
}

void print(Node* root)
{
	if(root == nullptr) return;
	queue<Node*> q;
	q.push(root);
	vector<int> ans;
	
	while(q.size())
	{
		Node* c = q.front(); q.pop();
		ans.pb(c->x);
		if(c->l != nullptr) q.push(c->l);
		if(c->r != nullptr) q.push(c->r);
	}
	
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if(i + 1 != ans.size()) cout << ' ';
	}
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	Node* root = buildtree(1, n);
	
	int k; cin >> k;
	while(k--)
	{
		int x; cin >> x;
		root = deleteNode(root, x);
	}
	
	print(root);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 7
// 4 2 1 3 6 5 7
// 2
// 3 6

// 4 2 5 1 7