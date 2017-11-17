/*
* 二叉树的实现，包括二叉搜索树，二叉平衡树，红黑树
*/

#include "BinSearchTree.h"
#include "BiTNodeDef.h"
#include <iostream>

BinSearchTree::BinSearchTree()
{
    m_root = NULL;
}

BinSearchTree::BinSearchTree(const BiTree bt)
{
    m_root = bt;
}

void BinSearchTree::_delete_pointer(BiTree &node)
{
    if(NULL == node)
    {
        return ;
    }
    _delete_pointer(node->lchild);
    -delete_pointer(node->rchild);
    delete node;
}

BinSearchTree::~BinSearchTree()
{
    if(NULL != m_root)
    {
        _delete_pointer(m_root);
    }
}

void BinSearchTree::_preOrderTraverse(BiTree node)
{
    std::cout << node->data << " ";
    if(node->lchild != NULL)
    {
        _preOrderTraverse(node->lchild);
    }
    if(node->rchild != NULL)
    {
        _preOrderTraverse(node->rchild);
    }
}

int BinSearchTree::preOrderTraverse()
{
    if(NULL == m_root)
    {
        return -1;
    }
    _preOrderTraverse(m_root);

    return 0;
}

void BinSearchTree::_inOrderTraverse(BiTree node)
{
    if (node->lchild != NULL)
    {
        _inOrderTraverse(node->lchild);
    }
    std::cout << node->data << " ";
    if (node->rchild != NULL)
    {
        _inOrderTraverse(node->rchild);
    }
}

int BinSearchTree::inOrderTraverse()
{
    if (NULL == m_root)
    {
        return -1;
    }
    _inOrderTraverse(m_root);

    return 0;
}

void BinSearchTree::_postOrderTraverse(BiTree node)
{
    if (node->lchild != NULL)
    {
        _postOrderTraverse(node->lchild);
    }
    if (node->rchild != NULL)
    {
        _postOrderTraverse(node->rchild);
    }
    std::cout << node->data << " ";
}

int BinSearchTree::postOrderTraverse()
{
    if (NULL == m_root)
    {
        return -1;
    }
    _postOrderTraverse(m_root);

    return 0;
}

int BinSearchTree::findNode(BiTree tree, int data, BiTree parent, BiTNode *&self)
{
    if(NULL == tree)
    {
        self = parent;
        return 0;
    }
    else if(tree->data == data)
    {
        self = tree;
        return 1;
    }
    else if(tree->data > data)
    {
        return findNode(tree->lchild, data, tree, self);
    }
    else
    {
        return findNode(tree->rchild, data, tree, self);
    }
}

int BinSearchTree::insert_node(int key)
{
    BiTNode *self;
    if(!findNode(m_root, key, NULL, self))
    {
        BiTree node = new BiNode();
        node->lchild = NULL;
        node->rchild = NULL;
        node->data = key;
        if(NULL == self)
        {
            m_root = node;
        }
        else if(self->data > key)
        {
            self->lchild = node;
        }
        else
        {
            self->rchild = node;
        }
        return 0;
    }
    return -1;
}

/*
* @return 获得二叉树的根
*/
BiTree BinSearchTree::getRoot()
{
    return m_root;
}

int BinSearchTree::delete_node(int key)
{
    BiTree self = NULL;
    BiTree p = NULL;
    if(findNode(m_root, key, NULL, self))
    {
        if(NULL == self)
        {
            return 0;
        }
        if(NULL == self->rchild)
        {
            p = self;
            self = self->lchild;
            delete p;
        }
        else if(NULL == self->lchild)
        {
            p = self;
            self = self->rchild;
            delete p;
        }
        else
        {
            BiTree q;
            p = self->lchild;
            while(p->rchild)
            {
                q = p;
                p = p->rchild;
            }
            self->data = p->data;
            if(p != q)
            {
                q->lchild = p->rchild;
            }
            else
            {
                q->rchild = p->lchild;
            }
            delete p;
        }
    }
}

int BinSearchTree::findMaxValue(int &data)
{
    BiTree p = m_root;
    if(NULL == p)
    {
        return -1;
    }
    while(p->rchild)
    {
        p = p->rchild;
    }
    data = p->data;

    return 0;
}

int BinSearchTree::findMinValue(int &data)
{
    BiTree p = m_root;
    if (NULL == p)
    {
        return -1;
    }
    while (p->lchild)
    {
        p = p->lchild;
    }
    data = p->data;

    return 0;
}