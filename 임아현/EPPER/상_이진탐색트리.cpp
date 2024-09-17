#include <bits/stdc++.h>

using namespace std;

vector<int> tree;
vector<int> result;

void postOrder(int left, int right) {
	//종료 조건
	if (left > right) {
		return;
	}

	int root = tree[left]; //전위 순회에서 가장 먼저 순회하는 노드는 root 노드

	int tmp = left + 1; //root보다 큰 노드 중 첫 번째 인덱스 (root 노드의 오른쪽 자식 노드)
	for (int i = left + 1; i <= right; i++) {
		if (tree[i] > root) {
			tmp = i;
			break;
		}
	}

	//후위 순회: left -> right -> root
	postOrder(left + 1, tmp - 1); //left 서브 트리 탐색
	postOrder(tmp, right); //right 서브 트리 탐색

	result.push_back(root); //root 입력
}

//전위 순회 결과 v가 주어졌을 때 후위 순회한 결과 벡터 반환
vector<int> solution() {
	vector<int> result;

	postOrder(0, tree.size() - 1);

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int num;

	while (cin >> num) {
		tree.push_back(num);
	}

	solution();

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}