from typing import List
import locale

class Node:
    def __init__(self,
                 name: str, children: List["Node"] = []
                 ) -> None:
        self.name = name
        self.children = children
    
    def count_same_nodes(self, search_name: str) -> int:
        lc_name = self.name.lower()
        lc_search_name = search_name.lower()
        cnt = 0
        if lc_name == lc_search_name:
            cnt += 1
        for child in self.children:
            cnt += child.count_same_nodes(search_name)
        return cnt


if __name__ == '__main__':
    locale.setlocale(locale.LC_ALL, '')
    node = Node(
        name="root",
        children=[Node(name="Coding",
                       children=[Node(name="I"),
                                 Node(name="Love"),
                                 Node(name="coDing")]), 
                  Node(name="Hello", 
                       children=[Node(name="heLLo"),
                                 Node(name="HELLO"),
                                 Node(name="worlD")])
        ]
    )
    print(node.count_same_nodes("cOding"))
    print(node.count_same_nodes("HELLO"))
    print(node.count_same_nodes("like"))
