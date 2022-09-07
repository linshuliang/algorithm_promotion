# CPP 文件格式化

## 安装clang-format

Linux

```shell
sudo apt install clang-format
```

mac

```shell
brew install clang-format
```

## 自定义clang-format

输出默认的格式

```shell
clang-format -style=llvm -dump-config > .clang-format
```

自定义格式
在项目根目录下创建.clang-format文件，并输入自定义配置。参考配置如下：

```shell
IndentWidth: 4
TabWidth: 4

Language: Cpp
Standard: Cpp11
BasedOnStyle: Google

# indent
AccessModifierOffset: -4
ContinuationIndentWidth: 8

# align
BreakBeforeTernaryOperators: true
BreakBeforeBinaryOperators: false
ColumnLimit: 120

# constructor
BreakConstructorInitializersBeforeComma: false
ConstructorInitializerIndentWidth: 8
ConstructorInitializerAllOnOneLineOrOnePerLine: true

# short block
AllowShortBlocksOnASingleLine: false
AllowShortFunctionsOnASingleLine: false
AllowShortIfStatementsOnASingleLine: false
AllowShortLoopsOnASingleLine: false
Cpp11BracedListStyle: true

# other
AlwaysBreakTemplateDeclarations: true
DerivePointerAlignment: false
PointerAlignment: Left

# clang-format 3.9+
SortIncludes: false

# BreakStringLiterals: false
ReflowComments: true
```

## pre-commit hook内容

```shell
# !/bin/bash

# 格式化具体文件，需要提前安装好clang-format

format_file() {
  file="${1}"
  if [ -f $file ]; then
    clang-format -i ${1}
    git add ${1}
  fi
}

case "${1}" in

* )
   # 格式化修改的文件

    for file in `git diff-index --cached --name-only HEAD | grep -iE '\.(cpp|cc|h|hpp)$'` ; do
      format_file "${file}"
    done
    ;;
esac
```

将该hook文件拷贝为 .git/hooks/pre-commit

## 参考

* [使用githook格式化c++代码](https://blog.csdn.net/qq_25821689/article/details/114412369)
