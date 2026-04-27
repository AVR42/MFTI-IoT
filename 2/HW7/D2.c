tree * findBrother(tree *root, int key) {
    if (root == NULL) return NULL;
    
    // Ищем узел с ключом key и его родителя
    tree *current = root;
    tree *parent = NULL;
    
    while (current != NULL && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    // Если узел не найден или это корень (нет родителя)
    if (current == NULL || parent == NULL) return NULL;
    
    // Возвращаем брата (другого ребенка родителя)
    if (parent->left == current) {
        return parent->right;
    } else {
        return parent->left;
    }
}
