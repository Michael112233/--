
        treeNode* tmp = (treeNode*)malloc(sizeof(treeNode));
        tmp->ch = str[pos];
        // printf("%d 0\n", tmp->children.size());
        tmp->visited = 1;
        root->children.push_back(tmp);
        i = root->children.size()-1;