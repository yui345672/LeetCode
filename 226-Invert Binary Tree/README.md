## 题意
   让你翻转一棵二叉树。
   
   ![image](https://user-images.githubusercontent.com/16880879/40830864-0ed7c22a-65ba-11e8-8a9c-ebe033454737.png)
   
   **这里说的翻转就是指镜像的那种翻转。**
   
## 思路
   1. 一开始我想的有点复杂了。我想的是：把每一层的点存到栈中去，然后再弹出来，这样就能够实现顺序的变化了。
   但是这样写起来有点问题，因为我是把每个点存下来，所以这里有一个问题就是会和之前的父节点连接不上，所以这种做法就被放弃了。
   
   2. 后来放了一天，又开始想，在草稿纸上比划了一下发现：
   哎~！！！这不就是左右两棵子树相互对换位置吗？不停的左子树和右子树换位置就好了！
   于是，就利用了递归来实现。
   
   3. solution 区中解答给出了迭代的方式，其实也就是上面递归的改版。也是不停的将左右子树压进去，然后对换位置就好了。
   它是用java写的，但是思路看一下就好了。
   
```java
   public TreeNode invertTree(TreeNode root) {
     if (root == null) return null;
     Queue<TreeNode> queue = new LinkedList<TreeNode>();
     queue.add(root);
     while (!queue.isEmpty()) {
         TreeNode current = queue.poll();
         TreeNode temp = current.left;
         current.left = current.right;
         current.right = temp;
         if (current.left != null) queue.add(current.left);
         if (current.right != null) queue.add(current.right);
     }
     return root;
}
```
