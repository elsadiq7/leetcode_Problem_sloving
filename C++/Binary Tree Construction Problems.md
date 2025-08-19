# 🌳 Binary Tree Construction Problems

We are usually asked to **reconstruct a binary tree** given some combinations of traversals.

---

## 🔹 Traversal Recap

* **Preorder**: `Root → Left → Right`
* **Inorder**: `Left → Root → Right`
* **Postorder**: `Left → Right → Root`

---

## 🔹 Possible Cases

### ✅ Case 1: **Preorder + Inorder**

* **Root** = first element of preorder.
* Use inorder to **split left vs right subtrees**.
* Build left subtree first, then right.
* **Order:** `root → left → right`
* Complexity: `O(n)` with hashmap.

---

### ✅ Case 2: **Postorder + Inorder**

* **Root** = last element of postorder.
* Use inorder to **split left vs right subtrees**.
* Build right subtree first, then left.
* **Order:** `root → right → left` (because we move backward).
* Complexity: `O(n)` with hashmap.

---

### ⚠️ Case 3: **Preorder + Postorder**

* Not always unique (many different trees may give the same traversals).
* Can only be reconstructed uniquely if the tree is **full binary tree** (every node has 0 or 2 children).

---

## 🔹 General Pattern

1. Use **preorder** or **postorder** to know the **current root**.
2. Use **inorder** to know how to **split left vs right subtrees**.
3. Recurse to build subtrees.
4. Use a hashmap (`value → index in inorder`) to speed up splitting (`O(1)` lookup).

---

## 🔹 Complexity

* **Time:** `O(n)` → each node processed once.
* **Space:** `O(n)` → hashmap + recursion stack.

---

✅ **In short**:

* **Preorder + Inorder** → pick root from **front**, build **left then right**.
* **Postorder + Inorder** → pick root from **back**, build **right then left**.
* **Preorder + Postorder** → not unique unless full tree.
