from typing import List, Dict, Set
from collections import defaultdict


class Solution:
    def generate_sentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        if not self._check_constraints(synonyms, text):
            raise ValueError("Constraints violated")
        # Initialize Union-Find structure for grouping synonyms
        uf = self.UnionFind()
        for synonym in synonyms:
            uf.union_set(synonym[0], synonym[1])

        # Group words into root: (root, synonyms)
        group_synonyms: Dict[str, Set[str]] = defaultdict(set)
        for synonym in synonyms:
            root = uf.find(synonym[0])
            group_synonyms[root].add(synonym[0])
            group_synonyms[root].add(synonym[1])

        # Split the input text into words
        words = text.split(' ')
        sentences: List[str] = []
        self._generate_sentence(0, words, group_synonyms, uf, "", sentences)
        return sorted(sentences)

    class UnionFind:
        """Union-Find class for efficient grouping
        """
        def __init__(self, ) -> None:
            self.parent: Dict[str, str] = dict()

        def find(self, x: str) -> str:
            # Initialize x as independent element
            if x not in self.parent.keys():
                self.parent[x] = x
            # Find the parent of x, i.e. an independent element
            if x != self.parent[x]:
                self.parent[x] = self.find(self.parent[x])

            return self.parent[x]

        # Union two sets represented by elements x and y
        def union_set(self, x: str, y: str) -> None:
            # Initialize y as dependent on x
            self.parent[self.find(x)] = self.find(y)

    def _generate_sentence(self,
                           index: int, words: List[str],
                           group_synonyms: Dict[str, Set[str]],
                           uf: UnionFind, current: str, sentences: List[str]
                           ) -> None:
        if index == len(words):
            sentences.append(current)
            return

        # Add space between words, but not before the first word
        separator = '' if index == 0 else ' '
        # Find the root of the current word to identify its synonym group
        root = uf.find(words[index])
        # If the word has synonyms, recursively explore each possibility
        if root in group_synonyms.keys():
            for synonym in group_synonyms[root]:
                self._generate_sentence(index + 1, words, group_synonyms, uf,
                                        current + separator + synonym, sentences)
        else:  # If no synonyms, continue with the original word
            self._generate_sentence(index + 1, words, group_synonyms, uf,
                                    current + separator + words[index], sentences)

#   Helper function to check the constraints
    def _check_constraints(self, syn: List[List[str]], text: str) -> bool:
        if len(syn) < 0 or len(syn) > 10:
            return False

        syns = set()
        for i in range(len(syn)):
            if len(syn[i]) != 2:
                return False
            if len(syn[i][0]) < 0 or len(syn[i][0]) > 10 or len(syn[i][1]) < 0 or len(syn[i][1]) > 10:
                return False
            if syn[i][0] == syn[i][1]:
                return False
            if syn[i][0] in syns and syn[i][1] in syns:
                return False
            syns.update(syn[i])

        if len(text.split(' ')) > 10:
            return False

        return True
