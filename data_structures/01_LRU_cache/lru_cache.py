from typing import Union, Dict


class Node:
    def __init__(self, key: int, value: int) -> None:
        self.key = key
        self.value = value
        self._next: Union['Node', None] = None
        self._prev: Union['Node', None] = None

    """ PROPERTIES """
    @property  # var = Node.key
    def key(self) -> int:
        return self._key

    @key.setter  # Node.key = new_key
    def key(self, new_key: int) -> None:
        if (new_key < 0) or (new_key > 10**4):
            raise ValueError("Constraints for 'key' violated")
        self._key = new_key

    @property  # var = Node.value
    def value(self) -> int:
        return self._value

    @value.setter  # Node.value = new_value
    def value(self, new_value: int) -> None:
        if (new_value < 0) or (new_value > 10**5):
            raise ValueError("Constraints for 'value' violated")
        self._value = new_value

    @property  # var = Node.next
    def next(self) -> Union['Node', None]:
        return self._next

    @next.setter  # Node.next = new_next
    def next(self, new_next: Union['Node', None]) -> None:
        if isinstance(new_next, Node) or new_next is None:
            self._next = new_next
        else:
            raise ValueError(f"Unsupported type {type(new_next)} for Node.next")

    @property  # var = Node.prev
    def prev(self) -> Union['Node', None]:
        return self._prev

    @prev.setter  # Node.prev = new_prev
    def prev(self, new_prev: Union['Node', None]) -> None:
        if isinstance(new_prev, Node) or new_prev is None:
            self._prev = new_prev
        else:
            raise ValueError(f"Unsupported type {type(new_prev)} for Node.prev")


class LRUCache:
    def __init__(self, capacity: int = 10) -> None:
        self.capacity = capacity
        self.head: Union[Node, None] = None
        self.tail: Union[Node, None] = None
        self.key_to_node_dict: Dict[int, Node] = dict()

    """ PROPERTIES """
    @property  # var = LRUCache.capacity
    def capacity(self) -> int:
        return self._capacity

    @capacity.setter  # LRUCache.capacity = new_capacity
    def capacity(self, new_capacity: int) -> None:
        if (new_capacity < 1) or (new_capacity > 3000):
            raise ValueError("Constraints for 'capacity' violated")
        self._capacity = new_capacity

    """ INSTANCE METHODS """
    def insert_at_head(self, node: Node) -> None:
        node.next = self.head
        if self.head is not None:
            self.head.prev = node

        self.head = node
        if self.tail is None:
            self.tail = node

    def unlink_node(self, node: Node) -> None:
        if node.next is not None:
            node.next.prev = node.prev
        else:
            self.tail = node.prev
        if node.prev is not None:
            node.prev.next = node.next
        else:
            self.head = node.next

    def get(self, key: int) -> int:
        if key in self.key_to_node_dict.keys():
            if self.key_to_node_dict[key] != self.head:
                self.unlink_node(self.key_to_node_dict[key])
                self.insert_at_head(self.key_to_node_dict[key])

            return self.key_to_node_dict[key].value
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.key_to_node_dict.keys():
            self.key_to_node_dict[key].value = value
            if self.key_to_node_dict[key] != self.head:
                self.unlink_node(self.key_to_node_dict[key])
                self.insert_at_head(self.key_to_node_dict[key])
        else:
            if len(self.key_to_node_dict) == self.capacity:
                if self.tail is not None:
                    del self.key_to_node_dict[self.tail.key]
                    self.unlink_node(self.tail)

            newNode = Node(key, value)
            self.insert_at_head(newNode)
            self.key_to_node_dict[key] = newNode
