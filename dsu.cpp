vector<ll> parents, set_sizes;

ll get_parent(ll vertex) {
    if (parents[vertex] != vertex) {
        parents[vertex] = get_parent(parents[vertex]);
    }
    return parents[vertex];
}

bool in_same(ll first_vertex, ll second_vertex) {
    return get_parent(first_vertex) == get_parent(second_vertex);
}

void join(ll first_vertex, ll second_vertex) {
    first_vertex = get_parent(first_vertex);
    second_vertex = get_parent(second_vertex);
    if (first_vertex == second_vertex) {
        return;
    }
    if (set_sizes[first_vertex] > set_sizes[second_vertex]) {
        swap(first_vertex, second_vertex);
    }
    parents[first_vertex] = second_vertex;
    set_sizes[second_vertex] += set_sizes[first_vertex];
}

