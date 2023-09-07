# AutoHotkey v2 Compile Toolset

This is a toolset for implementing in-place compilation capabilities in projects written in AutoHotkey.

> The binary files as `AutoHotkey64.exe` and `Ahk2Exe.exe` are COMPRESSED by `mpress.exe` by default for a smaller repo size.

## Usage

### Add submodule

```shell
git submodule add --depth=1 https://github.com/Nigh/ahk-compile-toolset
```

### Clone repo with submodule

```shell
git clone <your_repo_url> --recurse-submodules --shallow-submodules
```

### Compile

```shell
./ahk-compile-toolset/ahk2exe.exe /in "<your_script_name(main.ahk)>" /base "./ahk-compile-toolset/AutoHotkey64.exe" /compress 1
```

