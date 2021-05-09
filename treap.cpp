struct Node {
    ll weight, value, size;
    Node* left;
    Node* right;

    explicit Node(ll _value) {
        value = _value;
        left = right = nullptr;
        weight = (ll)rand();
        size = 1;
    }
};

void update(Node*& node) {
    if (!node) {
        return;
    }
    node->size = 1;
    if (node->left) {
        node->size += node->left->size;
    }
    if (node->right) {
        node->size += node->right->size;
    }
}

Node* merge(Node* left, Node* right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }
    if (left->weight > right->weight) {
        left->right = merge(left->right, right);
        update(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        update(right);
        return right;
    }
}

pair<Node*, Node*> split(Node* root, ll pos) {
    if (!root) {
        return {nullptr, nullptr};
    }
    ll ind = 0;
    if (root->left) {
        ind = root->left->size;
    }
    if (ind < pos) {
        auto part = split(root->right, pos - ind - 1);
        root->right = part.first;
        update(root);
        return {root, part.second};
    } else {
        auto part = split(root->left, pos);
        root->left = part.second;
        update(root);
        return {part.first, root};
    }
}

void print_tree(Node*& node) {
    if (!node) {
        return;
    }
    print_tree(node->left);
    cout << node->value << ' ';
    print_tree(node->right);
}