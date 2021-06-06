  Node* cloneGraph(Node* node) {
        if(!node)
                return NULL;
        
        Node*curr=new Node(node->val,{});
        unordered_map<Node*,Node*>m;
        m[node]=curr;
        
        queue<Node*>todo;
        todo.push(node);
        
        while(!todo.empty())
        {
            Node*now=todo.front();
            todo.pop();
            
            for(Node*connection:now->neighbors)
            {
                if (m.find(connection) == m.end()) {
                    m[connection] = new Node(connection -> val, {});
                    todo.push(connection);
                }
                m[now] -> neighbors.push_back(m[connection]);
            }
        }
        
        return curr;
        
        
        //DFS Approach:
//         unordered_map<Node*,Node*>copies;
        
//                 if (!node) {
//             return NULL;
//         }
//         if (copies.find(node) == copies.end()) {
//             copies[node] = new Node(node -> val, {});
//             for (Node* neighbor : node -> neighbors) {
//                 copies[node] -> neighbors.push_back(cloneGraph(neighbor));
//             }
//         }
//         return copies[node];
//     }
    }
