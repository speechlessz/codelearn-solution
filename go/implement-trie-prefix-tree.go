type Trie struct {
	Next  map[rune]*Trie
	IsEnd bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	this := Trie{}
	this.Next = map[rune]*Trie{}
	this.IsEnd = false
	return this
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	cur := this
	for _, c := range word {
		if cur.Next[c] == nil {
			newTrie := Constructor()
			cur.Next[c] = &newTrie
		}
		cur = cur.Next[c]
	}
	cur.IsEnd = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	cur := this
	for _, c := range word {
		if cur.Next[c] == nil {
			return false
		}
		cur = cur.Next[c]
	}
	return cur.IsEnd
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	cur := this
	for _, c := range prefix {
		if cur.Next[c] == nil {
			return false
		}
		cur = cur.Next[c]
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */