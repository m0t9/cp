ll tree[SIZE], a[SIZE], sz = 1;

void build(ll position, ll left, ll right) {
    if (right - left == 1) {
        tree[position] = a[left];
        return;
    }
    build(position * 2, left, (left + right) / 2);
    build(position * 2 + 1, (left + right) / 2, right);
    tree[position] = tree[position * 2] + tree[position * 2 + 1];
}

void update(ll position, ll left, ll right, ll request_position, ll request_value) {
    if (right - left == 1) {
        tree[position] = request_value;
        return;
    }
    ll middle = (left + right) / 2;
    if (request_position < middle) {
        update(position * 2, left, middle, request_position, request_value);
    } else {
        update(position * 2 + 1, middle, right, request_position, request_value);
    }
    tree[position] = tree[position * 2] + tree[position * 2 + 1];
}

ll get(ll position, ll current_left, ll current_right, ll left, ll right) {
    if ((right <= current_left) || (left >= current_right)) {
        return 0;
    }
    if (left <= current_left && current_right <= right) {
        return tree[position];
    }
    return get(position * 2, current_left, (current_left + current_right) / 2, left, right) +
           get(position * 2 + 1, (current_left + current_right) / 2, current_right, left, right);
}