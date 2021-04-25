# Permission checker

This is a task given by *Open Mobile Platform* to its interns.

### The goal

Implement an utility software that checks if users have write permissions to a directory.

### Details

* Recursively check underlying directories.
* Find all files and directories that allow given user/group to write.
* Use standard Linux permission check semantics (`owner` -> `group` -> `others`).
* Ignore the directory when unable to read contents.
* Ignore symbolic links.
* Ignore `/sys` and `/proc` directories.

Additionally, it's strongly recommended to:
* Organize code well.
* Use git.
* Use C/C++.

### Example usage

```bash
checkperm -u user -g group -p /home/user/magicdir
```

### Example output

`f` states that this is a file, `d` means it's an empty directory.

All entries have permissions for writing.

```bash
f /home/user/magicdir/not_a_file.png
f /home/user/magicdir/picture.txt
f /home/user/magicdir/another dir/cool report.md
d /home/user/magicdir/another dir/empty_dir
```