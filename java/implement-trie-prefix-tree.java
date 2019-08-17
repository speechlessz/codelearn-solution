class Trie {
    
    Trie[] next;
    boolean isEnd;

    /** Initialize your data structure here. */
    public Trie() {
        this.next = new Trie[26];
        this.isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie cur = this;
        for (char c: word.toCharArray()) {
            int i = c-'a';
            if (cur.next[i] == null) {
                cur.next[i] = new Trie();
            }
            cur = cur.next[i];
        }
        cur.isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Trie cur = this;
        for (char c: word.toCharArray()) {
            int i = c-'a';
            if (cur.next[i] == null) return false;
            cur = cur.next[i];
        }
        return cur.isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie cur = this;
        for (char c: prefix.toCharArray()) {
            int i = c-'a';
            if (cur.next[i] == null) return false;
            cur = cur.next[i];
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */