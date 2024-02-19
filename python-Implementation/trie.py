class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root=TrieNode()

    def insert(self, word):
        current = self.root
        for char in word:
            if char not in current.children:
                current.children[char]=TrieNode()
            current=current.children[char]
        current.is_end_of_word=True

    def search(self,word):
        current=self.root
        for char in word:
            if char not in current.children:
                return False
            current=current.children[char] 
        return current.is_end_of_word

    def starts_with_prefix(self,prefix):
        current=self.root
        for char in prefix:
            if char not in current.children:
                return False
            current=current.children[char]
        return True
                   
trie = Trie()
words = ["apple", "app", "apricot", "banana", "bat"]

for word in words:
    trie.insert(word)

print(trie.search("apple"))  # True
print(trie.search("app"))    # True
print(trie.search("apricot")) # True
print(trie.search("ap"))      # False (prefix is present, but not a complete word)
print(trie.search("orange"))  # False
print(trie.starts_with_prefix("ba"))  # True
print(trie.starts_with_prefix("batman")) 