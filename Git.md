# Git

`git config --global pull.rebase true` 以rebase的方式拉取代码

修改了本地仓库名称master -> main

命令:

```
git branch -m master main
```

设置上游直接push

命令:

```
git push -u origin main    //其中-u意思是 --set-upstream
```

在github修改默认分支名称 main -> master(手动操作) 如果不修改本地,则需要在本地重新设置上游

在本地进行 本地仓库进行同步,修改本地仓库默认分支 不论修改本地的还是远程的都需要重新设置上游

命令:

```
git branch -m oldname newname
```

```
git branch -m main master
```

删除远程分支

```
git push origin --delete test
```

删除本地分支

```
git branch -d test
```

如果想要别人参与自己的项目,可以先复制HTTPS 然后在一个空文件夹里打开Git Bash输入

```
git clone URL
```

使用 `git clone` 命令时，Git 会自动初始化一个新的 Git 仓库，并将远程仓库的内容下载到本地。

别人修改完了然后提交给他自己的远程仓库然后进行合并申请.

[拉取请求三项选择介绍](https://blog.csdn.net/wohu1104/article/details/123218389)

然后直接add . commit push就行了

不管什么时候,合并的时候一定要保持自己的内容是最新的,不然,别人更改了一111.txt 然后上传入远程库

下次新增了222.txt 但是自己没有及时拉取就会造成合并冲突

这时候需要git pull 一下再进行merge

`git checkout -b` 创建一个新分支
分支一般用于开发阶段,是可以不断添加Commit进行迭代的

`Tag`:一般表示一个稳定的版本,指向的Commit一般不会变更

通过`git tag`生成tag

附注标签

`git tag -a ` 完成附注标签:一种特殊的Tag,可以给Tag提供一些额外的信息

## 查找悬空Object

`git fsck --lost-found`

## git gc 删除悬空Object

git reflog expire --expire=now --all

git gc --prune=now

## Reflog

作用:记录操作日志,防止误操作后数据丢失 手动将日志设置为过期

指定时间 git gc prune=now 指定的是修剪多久之前的对象,默认是两周前

## 修改最近一次的Commit信息,修改之后Commit id 会变

`git commit --amend`

## rebase

通过`git rebase -i HEAD~3` 可以实现对最近三个commit的修改

- 合并commit
- 修改具体的commit message
- 删除某个commit
